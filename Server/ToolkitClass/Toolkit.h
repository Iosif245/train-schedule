#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../Types/Train/Train.h"

class Toolkit{
public:
    static void getUsers(std::vector<std::string> &users);
    static bool searchUser(const std::string &user, std::vector<std::string> &users);
    static bool checkTrainId(const std::string &trainId, std::vector<Train> &trains);
    static void Error(const std::string &msg);
    static bool checkStationName(const std::string &stationName, std::vector<Train> &trains);
};

