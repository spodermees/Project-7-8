

install vcpkg
install gcc/g++



compile met 

g++ -std=c++11 -o main main.cpp -I[path_to_vcpkg]/installed/x64-windows/include -L[path_to_vcpkg]/installed/x64-windows/lib -lpaho-mqttpp3 -lpaho-mqtt3as


bij olaf
g++ -std=c++11 -o main main.cpp -I C:\Users\Olaf\Documents\vcpkg/installed/x64-windows/include -L C:\Users\Olaf\Documents\vcpkg/installed/x64-windows/lib -lpaho-mqttpp3 -lpaho-mqtt3as





