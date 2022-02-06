
#include <iostream>
#include <climits>
#include <exception>
#include "client/Client.h"

int main(int argc, char **argv) {
    int port;
    int exit_status;

    std::cout << '\n';

    if (argc < 3) {
        std::cerr << "too few arguments given, please call with the server's ip and linstening port." << std::endl;
        return -1;
    } else if (argc > 3) {
        std::cerr << "too many arguments given, please call with the server's ip and linstening port." << std::endl;
        return -1;
    }
    const char *ip = argv[1];
    port = std::atoi(argv[2]);

    if (port < 0 || port > USHRT_MAX) {
        std::cerr << "port exceeds maximum possible values" << std::endl;
        return -1;
    }
    
    Client client;
    try {
        exit_status = client.run(ip, port);
    } catch (sock::socket_error &e) {
        std::cerr << "A connection error has occured, info: " << e.what() << std::endl;
        return -1;
    } catch (std::exception &e) {
        std::cerr << "An unexpected error has occured, info: " << e.what() << std::endl;
        return -1;
    }

    std::cout << "The client exited with status code: " << exit_status << std::endl;
    return 0;
}