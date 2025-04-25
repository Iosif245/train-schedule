#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../Types/Train/Train.h"
#include "../Types/Station/Station.h"
#include "../TimeClass/Time.h"

class Xml{
public:
    static void parseXml(std::vector<Train>&trains);
    static void updateXml(std::vector<Train>&trains, int newDelay, int delayType, std::string &trainId, std::string &stationName);
};