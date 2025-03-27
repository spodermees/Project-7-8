zodat die niet steeds uitvalt: sudo nmcli connection modify "Wired connection 1" ipv4.method manual ipv4.address 192.168.0.8/24


ssh erin
cd home/olaf/Documents/
python3 -m venv .venv
source .venv/bin/activate
pip install "paho-mqtt<2.0.0"
pip install lgpio 