# sensor
import numpy as np
from acconeer.exptool import a121
# mqtt
import paho.mqtt.client as mqtt
# lcd
from RPLCD.i2c import CharLCD
# other
import time

# MQTT Broker details
broker = "172.20.10.3"   # <- Plaats hier het ip van de broker
port = 1883             # <- Plaats hier de poort
username = "Hidde"     # <- gebruikersnaam
password = "3332ks"     # <- wachtwoord
topic = "test/chat"     # <- topic

print("Opening sensor....")
sensorClient = a121.Client.open(serial_port="/dev/ttyUSB0")     # <- Als jouw usb poort anders is dan moet je het hier veranderen.
sensor_config = a121.SensorConfig()
print("Sensor opened successfully.")

print("connecting to MQTT broker...")
mqttClient = mqtt.Client()
mqttClient.username_pw_set(username, password)
print("Connected to MQTT broker successfully.")

print("Setting up LCD Screen...")
lcd = CharLCD(i2c_expander='PCF8574', address=0x27, port=1,
              cols=16, rows=2, dotsize=8,
              charmap='A00', auto_linebreaks=True)
lcd.clear()
print("LCD Screen setup complete.")


def initSensor():
    print("Initializing sensor...")
    # Set up sensor config correctly
    sensor_config.profile = a121.Profile.PROFILE_3
    sensor_config.step_length = 2  # 1–255 (adjust based on desired resolution)
    sensor_config.num_points = 100  # number of distance points (adjust as needed)
    sensor_config.sweeps_per_frame = 8
    sensor_config.hwaas = 16
    sensorClient.setup_session(sensor_config)
    print("Session configured successfully.")
    sensorClient.start_session()
    
    
def initMQTT():
    print("Initializing MQTT client...")
    # Connect to broker
    mqttClient.connect(broker, port, 60)

    # Start the network loop in a separate thread
    mqttClient.loop_start()
    print("MQTT client initialized successfully.")



# Optional: define callback for successful connection
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected successfully!")
    else:
        print(f"Failed to connect, return code {rc}")




try: 
    initMQTT()
    initSensor()
    print("Sensor and MQTT client initialized successfully.")
    while True:
        # Get one frame of data
        result = sensorClient.get_next()
        frame = result.frame  # shape: (sweeps_per_frame, num_points)
        averaged = np.mean(frame, axis=0)

        peak_idx = np.argmax(averaged)

        step_m = sensor_config.step_length * 0.005
        distance_m = peak_idx * step_m

        print(f"Measured distance: {distance_m:.2f} m")
        lcd.clear()
        lcd.write_string(f"Distance: {distance_m:.2f} m")
        mqttClient.publish(topic, f"Distance: {distance_m:.2f} m")
        time.sleep(0.1)
except KeyboardInterrupt:
    print("Session interrupted by user.")
    sensorClient.stop_session()
    sensorClient.close()
