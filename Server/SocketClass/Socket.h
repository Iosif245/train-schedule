#pragma once
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>

class Socket {
public:
    void writeToClient(int socket, std::string &msg);
    void readFromClient(int socket);
};

