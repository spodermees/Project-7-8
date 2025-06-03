import paho.mqtt.client as mqtt

mqtt_client = mqtt.Client()
mqtt_client.connect("mqtt-broker-address", 1883)
mqtt_client.publish("test", distance_m)
mqtt_client.disconnect()