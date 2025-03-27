# CPP op de raspberrypi

In dit document vind je alles wat je nodig hebt om de code op de raspberrypi te runnen.


---
### C++ code
Om de c++ code te compilen op de raspberry pi heb je de library's nodig. Deze moet je instaleren op de raspberry pi. dat doe je met de volgende commando's.

``` cmd
sudo apt update
sudo apt install cmake gcc g++ git
sudo apt install libssl-dev
cd ~
git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c
mkdir build
cd build
cmake -DPAHO_WITH_SSL=ON -DPAHO_BUILD_STATIC=ON -DPAHO_BUILD_SHARED=ON ..
make -j$(nproc)
sudo make install
sudo ldconfig
cd ~
git clone https://github.com/eclipse/paho.mqtt.cpp.git
cd paho.mqtt.cpp
mkdir build
cd build
cmake -DPAHO_BUILD_SHARED=ON -DPAHO_BUILD_STATIC=ON ..
make -j$(nproc)
sudo make install
sudo ldconfig
cd ~/paho.mqtt.cpp/build
cmake ..
make -j$(nproc)
cd ~
git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi
./build
```

Daarna moet je de code compilen. Ga naar de zelfde directory als de cpp file en voer het volgende command in de terminal.

```cmd
g++ -o sensor-module sensor-module.cpp -lpaho-mqttpp3 -lpaho-mqtt3a -lpaho-mqtt3c -lwiringPi -pthread
```
Om de file te runnen voer je `sudo ./sensor-module` uit. De naam van het begin bestand is sensor-module.cpp. indien er een andere naam is zal je deze in de commands moeten veranderen.

---
### Webserver
De cpp code heeft een websocket naar een webserver. Hiervoor moet de webserver aangezet worden.