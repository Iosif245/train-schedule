#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../Station/Station.h"

class Train {
public:
    std::string trainName;
    std::string trainId;
    std::string trainFreeSeats;
    std::string date;
    std::vector<Station> trainStations;
};
