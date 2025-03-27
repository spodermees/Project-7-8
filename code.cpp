#include <iostream>
#include <mqtt/async_client.h>

const std::string SERVER_ADDRESS = "172.20.10.4:1883";  // Change to your broker
const std::string CLIENT_ID = "RaspberryPi5_Client";
const std::string USERNAME = "your_username";  // Set your MQTT username
const std::string PASSWORD = "your_password";  // Set your MQTT password
const std::string TOPIC = "test/topic";

const int QOS = 1;
const int TIMEOUT = 10000;

class Callback : public virtual mqtt::callback {
public:
    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "Received message: " << msg->get_payload_str() 
                  << " on topic: " << msg->get_topic() << std::endl;
    }
};

int main() {
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    Callback cb;
    client.set_callback(cb);

    mqtt::connect_options connOpts;
    connOpts.set_user_name(USERNAME);
    connOpts.set_password(PASSWORD);
    connOpts.set_clean_session(true);

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

        std::this_thread::sleep_for(std::chrono::seconds(10));
        client.disconnect()->wait();
        std::cout << "Disconnected from MQTT broker." << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }
    return 0;
}
