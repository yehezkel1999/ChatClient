
#include "Client.h"
#include <iostream>

Client::Client()
    : _socket() {}

int Client::run(const char *ip, int port) {
    std::cout << "Connecting to server: " << ip << ':' << port << std::endl;
    _socket.sconnect(ip, port);
    std::cout << "Done." << std::endl;

    while (true) {}

    return 0;
}