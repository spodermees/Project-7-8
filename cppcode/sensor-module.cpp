#include <iostream>
#include <mqtt/async_client.h>
#include <wiringPi.h>


const std::string SERVER_ADDRESS = "172.20.10.3:1883";  // Change to your broker
const std::string CLIENT_ID = "RaspberryPi5_Client";
//const std::string USERNAME = "your_username";  // Set your MQTT username
//const std::string PASSWORD = "your_password";  // Set your MQTT password
const std::string TOPIC = "chat/commands";

const int QOS = 0;
const int TIMEOUT = 10000;

class Callback : public virtual mqtt::callback {
public:
    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "Received message: " << msg->get_payload_str() << " on topic: " << msg->get_topic() << std::endl;
    }
};

int main() {
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    Callback cb;
    client.set_callback(cb);
    int count = 0;
    mqtt::connect_options connOpts;
    //connOpts.set_user_name(USERNAME);
    //connOpts.set_password(PASSWORD);
    connOpts.set_clean_session(true);
    if (wiringPiSetup() == -1) {
        std::cerr << "Failed to initialize WiringPi!" << std::endl;
        return 1;
    }
    int GPIO_PIN = 0;  // WiringPi pin number (GPIO 17 in BCM)
    pinMode(GPIO_PIN, INPUT);
    pullUpDnControl(GPIO_PIN, PUD_UP);  // Enable pull-up resistor



    try {
        std::cout << "Connecting to MQTT broker..." << std::endl;
        mqtt::token_ptr conntok = client.connect(connOpts);
        conntok->wait();
        std::cout << "Connected!" << std::endl;

        client.subscribe(TOPIC, QOS);
        std::cout << "Subscribed to topic: " << TOPIC << std::endl;

        std::string payload = "Hello from Raspberry Pi 5!";
        mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC, payload);
        pubmsg->set_qos(QOS);
        client.publish(pubmsg);
        std::cout << "Message published!" << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    while (true) {
        


        int state = digitalRead(GPIO_PIN);
        if (state == LOW) {
            std::string payload = std::to_string(count) + ": In range!";
            mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC, payload);
            pubmsg->set_qos(QOS);
            client.publish(pubmsg);
            count++;
        }

        delay(50);  // 500ms delay
    }


    return 0;
}
