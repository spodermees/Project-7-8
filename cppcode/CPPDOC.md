# CPP op de raspberrypi

In dit document vind je alles wat je nodig hebt om C++ op de raspberrypi te runnen.



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




g++ -o mqtt-client mqtt-client.cpp -lpaho-mqttpp3 -lpaho-mqtt3a -lpaho-mqtt3c -pthread
sudo ./mqtt-client






g++ -o read_gpio read_gpio.cpp -lwiringPi
