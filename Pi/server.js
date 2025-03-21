const WebSocket = require('ws');
const mqtt = require('mqtt');
const websocketport = 8080;

// WebSocket server maken
const server = new WebSocket.Server({ port: websocketport });

// Start WebSocket server
server.on('listening', () => {
  console.log('WebSocket gestart op port ' + websocketport);
});

// MQTT-client
const mqttclient = mqtt.connect('mqtt://172.20.10.4:1883', {
  username: 'Hidde',
  password: 'AMIDH'
});

// Bij mqtt verbinding
mqttclient.on('connect', () => {
  console.log('MQTT client connected');
  mqttclient.subscribe('chat', (err) => {
    if (err) console.error('Error subscribing to chat:', err);
    else console.log('Server successfully subscribed to "chat"');
  });
});

// Bij bericht van MQTT
mqttclient.on('message', (topic, message) => {
  server.clients.forEach((socket) => {
    if (socket.readyState === WebSocket.OPEN) {
      socket.send(message.toString());
    }
  });
});

// Bij websocket verbinding
server.on('connection', (socket) => {
  console.log('Client connected');
  socket.on('message', (message) => mqttclient.publish('chat', message.toString()));
  socket.on('close', () => console.log('Client disconnected'));
  socket.send('You have successfully connected to the chat!;;;Server');
});