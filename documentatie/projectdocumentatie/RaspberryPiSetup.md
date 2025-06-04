# Setup van de Raspberry Pi

**NOTE: In deze setup guide verwachten we dat je kennis hebt over hoe je de Raspberry Pi moet flashen en erin moet komen met ssh.**

## Benodigdheden
- 4x female to female jumper wires
- 1x I2C LCD Screen
- 1x Raspberry Pi 5 (of Raspberry Pi 4) met Raspbian OS (64 bit) + ethernet kabel en power supply
- 1x XE125 Radar sensor + usb-a -> usb-c kabel

## Hardware
### LCD
Er zijn 4 aansluiting bij het LCD scherm. Deze zijn: VCC, GND, SCL, SDA. Zoek indien nodig de pinout voor jouw model op.
1. Sluit de 5V van de raspberry aan op de VCC van de LCD.
2. Sluit de GND van de raspberry aan op de GND van de LCD.
3. Sluit de SCL van de raspberry aan op de SCL van de LCD.
4. Sluit de SDA van de raspberry aan op de SDA van de LCD.

Als de raspberry power krijgt dan zal de backscreen van de LCD aan gaan.

### XE125 Sensor
De XE125 sluit je aan met een usb kabel. Doe de kant met usb-a in de raspberry in 1 van de 4 poorten. Doe de andere kant in de usb-c poort van de XE125.

## Raspberry Pi setup
### Systeem
Zorg dat je een Raspbian 64 bit OS hebt en zorg dat je in de commandline zit.

Eerst gaan we de Raspberry Pi updaten. Daarnaast installeren we ook meteen python3 en pip.
```bash
sudo apt update && sudo apt install python3 python3-pip
```

Omdat we een 64 bit OS gebruiken moeten we 32 bit support aanzetten. Dit is omdat de libraries van Acconeer 32 bit zijn.
```bash
sudo dpkg --add-architecture armhf
sudo apt update
sudo apt install libc6:armhf libgpiod2:armhf
```
Hierna moet je de Raspberry Pi rebooten.
```bash
sudo reboot
```
Dit zorgt ervoor dat alles herstart. Doe je dit niet zullen er dingen niet werken.
Om de controleren of het instaleren goed is gegaan kun je `uname -m` gebruiken. Dit moet `aarch64` aangeven.

Omdat we een I2C Screen gebruiken moeten we I2C aanzetten. dit doe je door `sudo raspi-config` te typen. 
1. Hierin navigeer je naar 'Interface Options'
2. Dan selecteer je I2C
3. Kies 'Yes' 
4. Navigeer terug en ga naar 'Finish'

Hierna reboot je de Raspberry Pi.
```bash
sudo reboot
```

Hierna moet je de I2C-tools installeren.
```bash
sudo apt install i2c-tools
```


### Virtual Software
Hierna kun je een venv maken. Dit is een virtual envirement. 
Een venv maak je doormiddel van in een directory naar keuze het command te gebruiken.
```bash
mkdir ~/autonoom/
cd ~/autonoom/
python -m venv ./venv
```

Nu je een venv hebt gemaakt kun venv activeren.
```bash
source venv/bin/activate
```
Als je venv wilt deaciveren type je `deactivate`.

Nu je je venv hebt geactiveerd kun je dingen met pip instaleren. We beginnen met de SDK van Acconeer te installeren.
```bash
pip install --upgrade acconeer-exptool[algo]
```

Nu we de tool hebben kunnen we de setup aanroepen.
```bash
python3 -m acconeer.exptool.setup
```

Als je het nog niet had gedaan kan je nu de XE125 verbinden met de Raspberry Pi.

Om te kijken of het apparaat herkent word kun je het volgende command doen
```bash
ls /dev/ttyUSB*
```
Nu krijg je waarschijnlijk de volgende poorten te zien: `/dev/ttyUSB0` en `/dev/ttyUSB1`. De eerste is gebruikt om data te versturen en ontvangen. Meestal is dit `/dev/ttyUSB0`. Als je de Raspbian OS gebruikt hoef je geen extra drivers te installeren. Anders heb je deze nodig: `CP210x`.

Note: Als jouw usb poorten allebei anders zijn moet je die veranderen in de code.

Om MQTT te gebruiken moet je de volgende libray installeren.
```bash
pip install paho-mqtt
```

Ook voor de LCD Screen hebben we een library nodig.
```bash
pip install RPLCD
```

Voor de websocket hebben we ook een library nodig.
```bash
pip install flask flask-socketio eventlet
```

**Optional**
Als je de sensor firmware wilt updaten heb kun je de volgende commands uitvoeren. (LET OP: Hier heb je wel een acconeer account voor nodig) En volg de instructies die worden gegeven.
```bash
pip install beautifulsoup4
python3 -m acconeer.exptool.flash flash -d XM125 -f
```



## Code

Als de code niet werkt doordat jouw user geen machtigingen heeft moet je de machtigingen geven met het volgende command. hierna moet je ook rebooten.
```bash
sudo usermod -a -G dialout $(whoami)
sudo reboot
```

De testcode staat bij [code](../../software/raspberrypi/testradar.py).


Om het hele systeem te testen is er ook een broker nodig. Je verbind met de broker door het IP address, port, gebruikersnaam en wachtwoord aan te passen naar de gegevens van jouw broker. Voor nu staat de gebruikersnaam en het wachtwoord erin voor de broker die is meegeleverd ([broker](../../software/broker/)).

```py
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

# Initialize the sensor with the desired configuration
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

# initialize MQTT client
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
        lcd.write_string(f"MQTT ERROR: {rc}")

try: 
    try:
        initSensor()
    except Exception as e:
        print(f"Error starting radar session: {e}")
        lcd.clear()
        lcd.write_string(f"XE125 ERROR: {e}")
        sensorClient.close()
        exit(1)
    initMQTT()
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
    mqttClient.loop_stop()
    mqttClient.disconnect()
```
