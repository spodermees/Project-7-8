#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <iostream>
#include <set>

typedef websocketpp::server<websocketpp::config::asio> server;

std::set<websocketpp::connection_hdl, std::owner_less<websocketpp::connection_hdl>> connections;

void on_open(server* s, websocketpp::connection_hdl hdl) {
    connections.insert(hdl);
    std::cout << "Client connected\n";
}

void on_close(server* s, websocketpp::connection_hdl hdl) {
    connections.erase(hdl);
    std::cout << "Client disconnected\n";
}

int main() {
    server ws_server;

    ws_server.init_asio();
    ws_server.set_open_handler(std::bind(&on_open, &ws_server, std::placeholders::_1));
    ws_server.set_close_handler(std::bind(&on_close, &ws_server, std::placeholders::_1));

    ws_server.set_message_handler([&](websocketpp::connection_hdl hdl, server::message_ptr msg) {
        std::string message = msg->get_payload();
        std::cout << "Received from client: " << message << std::endl;
    });

    ws_server.listen(9002);
    ws_server.start_accept();

    // Broadcast dummy data every 5 seconds
    std::thread broadcaster([&]() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::string data = "Sensor value: " + std::to_string(rand() % 100);
            for (auto& conn : connections) {
                ws_server.send(conn, data, websocketpp::frame::opcode::text);
            }
        }
    });

    ws_server.run();
}
