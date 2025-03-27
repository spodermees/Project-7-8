

sudo apt update
sudo apt install g++-aarch64-linux-gnu
cd ~
git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c
mkdir build
cd build

cmake -DPAHO_WITH_SSL=ON -DPAHO_BUILD_STATIC=ON -DPAHO_BUILD_SHARED=ON ..
make -j$(nproc)
sudo make install
sudo ldconfig
cd ~/paho.mqtt.cpp
mkdir -p build
cd build
cmake -DPAHO_MQTT_C_LIBRARIES="/usr/local/lib" -DPAHO_MQTT_C_INCLUDE_DIRS="/usr/local/include" ..
make -j$(nproc)
sudo make install
sudo ldconfig








g++ -o mqtt_client mqtt_client.cpp -lpaho-mqttpp3 -lpaho-mqtt3a -lpaho-mqtt3c -pthread



sudo apt update
sudo apt install git
cd ~
git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi
./build

g++ -o read_gpio read_gpio.cpp -lwiringPi
