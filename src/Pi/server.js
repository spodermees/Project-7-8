const WebSocket = require('ws');
const mqtt = require('mqtt');
const websocketport = 8080;

const datatopic = "module/sensordata"
const actiontopic = "module/action"

let data;

// WebSocket server maken
const server = new WebSocket.Server({ port: websocketport });

// Start WebSocket server
server.on('listening', () => {
  console.log('WebSocket gestart op port ' + websocketport);
});

// MQTT-client
//const mqttclient = mqtt.connect('mqtt://mosquitto-mqtt-broker-1:1883', {
const mqttclient = mqtt.connect('mqtt://172.20.10.4:1883', {
  username: 'Hidde',
  password: 'AMIDH'
});

// Bij mqtt verbinding
mqttclient.on('connect', () => {
  console.log('MQTT client connected');
  mqttclient.subscribe(actiontopic, (err) => {
    if (err) console.error('Error subscribing to chat:', err);
    else console.log('Server successfully subscribed to ' + actiontopic);
  });
});

mqttclient.on('error', (err) => {
  console.error('MQTT Connection Error:', err);
});

// Bij bericht van MQTT
mqttclient.on('message', (topic, message) => {
  console.log('Message received from broker: ' + message)
});

// Bij websocket verbinding
server.on('connection', (socket) => {
  console.log('Dashboard connected');
  socket.on('message', (message) => console.log('Message received from websocket: ' + message));
  socket.on('close', () => console.log('Dashboard disconnected'));
  socket.send('Hi from program');
  setInterval(() => {
    socket.send(data);
  }, 1000);
});

setInterval(() => {
  data = {
    sensor: 1,
    data: {
      distance: Math.floor(Math.random() * 100),
      speed: Math.floor(Math.random() * 20)
    }
  };
  data = JSON.stringify(data);
  mqttclient.publish(datatopic, data);
}, 10);

