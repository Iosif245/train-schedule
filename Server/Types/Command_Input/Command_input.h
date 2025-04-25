#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../Train/Train.h"

class Command_input{
public:
    std::string username;
    bool connected = false;
    int command ;
    int socket;
    int threadId;
    std::string stationName;
    std::string trainId;
    int delay;
    std::vector<Train>& trains;
    std::vector<std::string>& users;
};

