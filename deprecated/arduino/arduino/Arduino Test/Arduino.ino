#include "SparkFun_Qwiic_XM125_Arduino_Library.h"
#include <Ethernet.h>
#include <PubSubClient.h>
#include <LiquidCrystal_I2C.h>

// Setup MQTT Broker
const char* mqtt_server = "192.168.0.100";
const char* mqtt_topic = "radar/data";
const int mqtt_port = 1883;

// MQTT credentials
const char* mqtt_user = "Hidde";
const char* mqtt_pass = "3332ks";

// Ethernet instellingen
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 177);

// MQTT Client
EthernetClient ethClient;
PubSubClient client(ethClient);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Radar sensor object
SparkFunXM125Distance radarSensor;

// I2C default address
uint8_t i2cAddress = SFE_XM125_I2C_ADDRESS;

// Setup Variabelen
uint32_t startVal = 50;
uint32_t endVal = 5000;
uint32_t numDistances = 9;
uint32_t calibrateNeeded = 0;
uint32_t measDistErr = 0;

// Error status
uint32_t errorStatus = 0;

// Distance Variabelen
int32_t distancePeakStrength0 = 0;
uint32_t distancePeak0 = 0;
int32_t distancePeakStrength1 = 0;
uint32_t distancePeak1 = 0;

// Setup radar sensor
void setupRadar(){
    Wire.begin();

    // If begin is successful (0), then start example
    if (radarSensor.begin(i2cAddress, Wire) == 1)
    {
        Serial.println("Starting XM125 radar...");
    }
    else // Otherwise, infinite loop
    {
        Serial.println("Device failed to setup - Freezing code.");
        while (1)
            ; // Runs forever
    }

    // Distance Sensor Setup
    // Reset sensor configuration to reapply configuration registers
    radarSensor.setCommand(SFE_XM125_DISTANCE_RESET_MODULE);

    radarSensor.busyWait();

    // Check error and busy bits
    radarSensor.getDetectorErrorStatus(errorStatus);
    if (errorStatus != 0)
    {
        Serial.print("Detector status error: ");
        Serial.println(errorStatus);
    }

    delay(100);

    // Set Start register
    if (radarSensor.setStart(startVal) != 0)
    {
        Serial.println("Distance Start Error");
    }
    radarSensor.getStart(startVal);
    Serial.print("Start Val: ");
    Serial.println(startVal);

    delay(100);
    // Set End register
    if (radarSensor.setEnd(endVal) != 0)
    {
        Serial.println("Distance End Error");
    }
    radarSensor.getEnd(endVal);
    Serial.print("End Val: ");
    Serial.println(endVal);
    delay(100);

    // Set Distance Threshold Settings - Threshold Sensitivity (range: 0 to 1000)
    radarSensor.setThresholdSensitivity(100);

    // Set Fixed Amplitude Threshold
    radarSensor.setFixedAmpThreshold(100);

    // Apply configuration
    if (radarSensor.setCommand(SFE_XM125_DISTANCE_APPLY_CONFIGURATION) != 0)
    {
        // Check for errors
        radarSensor.getDetectorErrorStatus(errorStatus);
        if (errorStatus != 0)
        {
            Serial.print("Detector status error: ");
            Serial.println(errorStatus);
        }

        Serial.println("Configuration application error");
    }

    // Poll detector status until busy bit is cleared
    if (radarSensor.busyWait() != 0)
    {
        Serial.print("Busy wait error");
    }

    // Check detector status
    radarSensor.getDetectorErrorStatus(errorStatus);
    if (errorStatus != 0)
    {
        Serial.print("Detector status error: ");
        Serial.println(errorStatus);
    }
}

// Verbindt met de MQTT broker
void connectMQTT() {
    client.setServer(mqtt_server, mqtt_port);
    client.setKeepAlive(60);
    Serial.println("Connecting to MQTT...");
    while (!client.connected()) {
        // Verbind met gebruikersnaam en wachtwoord
        if (client.connect("Arduino", mqtt_user, mqtt_pass)) {
            Serial.println("Connected!");
        }
    }
}

void checkRadar(){
    // Check error bits
    radarSensor.getDetectorErrorStatus(errorStatus);
    if (errorStatus != 0)
    {
        Serial.print("Detector status error: ");
        Serial.println(errorStatus);
    }

    // Start detector
    if (radarSensor.setCommand(SFE_XM125_DISTANCE_START_DETECTOR) != 0)
    {
        Serial.println("Start detector error");
    }

    // Poll detector status until busy bit is cleared - CHECK ON THIS!
    if (radarSensor.busyWait() != 0)
    {
        Serial.println("Busy wait error");
    }

    // Verify that no error bits are set in the detector status register
    radarSensor.getDetectorErrorStatus(errorStatus);
    if (errorStatus != 0)
    {
        Serial.print("Detector status error: ");
        Serial.println(errorStatus);
    }

    // Check MEASURE_DISTANCE_ERROR for measurement failed
    radarSensor.getMeasureDistanceError(measDistErr);
    if (measDistErr == 1)
    {
        Serial.println("Measure Distance Error");
    }

    // Recalibrate device if calibration error is triggered
    radarSensor.getCalibrationNeeded(calibrateNeeded);
    if (calibrateNeeded == 1)
    {
        Serial.println("Calibration Needed - Recalibrating.. ");
        // Calibrate device (write RECALIBRATE command)
        radarSensor.setCommand(SFE_XM125_DISTANCE_RECALIBRATE);
    }
}

//Send current power usage to LCD screen
void sendDataToLCD(float data) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(data * .1);
  lcd.print(" cm");
}


void setup() {
    Serial.begin(9600);
    Serial.println();

    lcd.init(); 
    lcd.backlight();

    // Ethernet verbinding opzetten
    Serial.println("---------------------------");
    Serial.println("Connecting to ethernet...");
    Ethernet.begin(mac, ip);
    Serial.print("Local IP: ");
    Serial.println(Ethernet.localIP());
    Serial.println("---------------------------");

    // Radar initialiseren
    setupRadar();
    Serial.println("---------------------------");

    // Verbinden met MQTT broker
    connectMQTT();
    Serial.println("---------------------------");

    Serial.println("Program started!");
    delay(1000);
}

void loop() {
    // Verbind opnieuw als we niet meer verbonden zijn
    if (!client.connected()) {
        connectMQTT();
    }
    client.loop();  // Verwerkt inkomende berichten (indien aanwezig)

    // Lees de radarwaarden
    checkRadar();
    radarSensor.getPeak0Distance(distancePeak0);
    radarSensor.getPeak0Strength(distancePeakStrength0);
    radarSensor.getPeak1Distance(distancePeak1);
    radarSensor.getPeak1Strength(distancePeakStrength1);


    // Creëer een JSON-bericht met de gemeten waarden
    String data = String("{\"peak0_distance\":") + distancePeak0 +
                  ",\"peak0_strength\":" + distancePeakStrength0 +
                  ",\"peak1_distance\":" + distancePeak1 +
                  ",\"peak1_strength\":" + distancePeakStrength1 + "}";


    // Stuur de data naar de broker via MQTT
    if (!client.publish(mqtt_topic, data.c_str())) {
        Serial.println("Failed to send data");
    }

    static unsigned long timer = 0;
    if (millis() - timer > 1000) {
        timer = millis();
        sendDataToLCD(distancePeak0);
    }

    delay(50);
}