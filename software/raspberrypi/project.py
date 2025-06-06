import numpy as np
from acconeer.exptool import a121
import paho.mqtt.client as mqtt
from RPLCD.i2c import CharLCD
from flask import Flask, render_template_string
from flask_socketio import SocketIO
import time
import threading

checkSensor = True

# MQTT details
broker = "172.20.10.3"  # Replace with your MQTT broker IP
port = 1883             # Replace with your MQTT broker port
username = "Hidde"      # Replace with your MQTT username
password = "3332ks"     # Replace with your MQTT password
topic = "sensor/data"     # Replace with your MQTT topic

# Flask setup
app = Flask(__name__)
socketio = SocketIO(app)

# LCD setup
lcd = CharLCD(i2c_expander='PCF8574', address=0x27, port=1,
              cols=16, rows=2, dotsize=8,
              charmap='A00', auto_linebreaks=True)
lcd.clear()

# Sensor setup
sensorClient = a121.Client.open(serial_port="/dev/ttyUSB0")
sensor_config = a121.SensorConfig()

def on_message(sourceClient, userdata, message):
    payload = message.payload.decode()
    if(message.topic == "sensor1/action" and payload == "STOP"):
        lcd.write_string("Stopping sensor")
        checkSensor = False
        return
    if(message.topic == "sensor1/action" and payload == "START"):
        lcd.write_string("Starting sensor")
        checkSensor = True
        return
    print(f"[MQTT] Topic: {message.topic}, Message: {payload}")



def initSensor():
    sensor_config.profile = a121.Profile.PROFILE_3
    sensor_config.step_length = 2
    sensor_config.num_points = 100
    sensor_config.sweeps_per_frame = 8
    sensor_config.hwaas = 16
    sensorClient.setup_session(sensor_config)
    sensorClient.start_session()

# MQTT setup
mqttClient = mqtt.Client()
mqttClient.username_pw_set(username, password)

def initMQTT():
    mqttClient.connect(broker, port, 60)
    mqttClient.on_message = on_message
    mqttClient.loop_start()
    mqttClient.subscribe(topic)

@app.route('/')
def index():
    return render_template_string("""
        <!DOCTYPE html>
        <html>
            <head>
            <title>Live Sensor Distance</title>
            <script src="//cdnjs.cloudflare.com/ajax/libs/socket.io/4.7.2/socket.io.min.js"></script>
            </head>
            <body style="font-family:sans-serif;">
            <h1>Live Distance Reading</h1>
            <p id="distance">Waiting for data...</p>
            <script>
                const socket = io();
                socket.on('distance', data => {
                    console.log("adsf");
                    document.getElementById('distance').innerText = `Distance: ${data} m`;
                });
            </script>
            </body>
        </html>
    """)

def sensor_loop():
    try:
        initSensor()
    except Exception as e:
        lcd.write_string(f"XE125 ERROR: {e}")
        sensorClient.close()
        return

    initMQTT()
    try:
        while True:
            if(not checkSensor):
                lcd.write_string("Sensor stopped")
                time.sleep(1)
                continue
            result = sensorClient.get_next()
            frame = result.frame
            averaged = np.mean(frame, axis=0)
            smoothed = np.convolve(averaged, np.ones(5)/5, mode='same')
            smoothed = smoothed - np.min(smoothed)
            threshold = np.max(smoothed) * 0.5
            smoothed[smoothed < threshold] = 0
            peak_idx = np.argmax(smoothed)
            step_m = sensor_config.step_length * 0.005
            distance_m = peak_idx * step_m

            lcd.clear()
            lcd.write_string(f"Distance: {distance_m:.2f} m")
            mqttClient.publish(topic, f"Distance: {distance_m:.2f}")
            socketio.emit('distance', f"{distance_m:.2f}")
            time.sleep(0.1)
    except Exception as e:
        sensorClient.stop_session()
        sensorClient.close()
        mqttClient.loop_stop()
        mqttClient.disconnect()

def start_sensor_thread():
    thread = threading.Thread(target=sensor_loop)
    thread.daemon = True
    thread.start()

if __name__ == '__main__':
    start_sensor_thread()
    socketio.run(app, host='0.0.0.0', port=5000)