import paho.mqtt.client as mqtt
import lgpio
import time

# MQTT Broker details
BROKER = "172.20.10.4"  # Public test broker
PORT = 1883  # Default MQTT port
TOPIC = "test/mqtt" # Topic to subscribe to
CLIENT_ID = "meesisaardig" # Client ID to use
USERNAME = "Hidde"  # Replace with your username
PASSWORD = "AMIDH"  # Replace with your password
# GPIO Setup
SENSOR_PIN = 4  # Change this based on your GPIO pin
h = lgpio.gpiochip_open(0)
lgpio.gpio_claim_input(h, SENSOR_PIN)

# MQTT Setup
client = mqtt.Client(CLIENT_ID)

client.username_pw_set(USERNAME, PASSWORD)


def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker!")
    else:
        print(f"Failed to connect, return code {rc}")

client.on_connect = on_connect
client.connect(BROKER, PORT, 60)

try:
    print("Waiting for sensor trigger...")
    while True:
        message = (lgpio.gpio_read(h, SENSOR_PIN))
        client.publish(TOPIC, message)
        print(f"Published: {message}")
        time.sleep(0.1)  # Short delay for efficiency
except KeyboardInterrupt:
    print("\nStopping...")
    lgpio.gpiochip_close(h)
    client.disconnect()