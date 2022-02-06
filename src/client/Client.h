
#include "../../../socket/src/Socket.h"

class Client {
public: // usings


private: // private methods

public: // public methods
    Client();
    ~Client() {}

    int run(const char *ip, int port);

private: // class members
    sock::Socket _socket;
};