#pragma once

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Toolkit {
public:
    static void write_to_server(int sd, std::string &command);
    static void read_from_server(int sd, bool &connected);
    static void showCommands();
};

