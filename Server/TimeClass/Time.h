#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>

class Time {
public:
    static std::string getCurrentDate();
    static std::chrono::system_clock::time_point getCurrentTime();
    static bool checkIfTimeIsInCurrentHour(std::string timeToCheck);
    static bool checkIfCurrentTimeIsGreaterThenTimeToCheck(std::string &timeToCheck);
    static std::string addMinutes(std::string &timeToChange, int minutes);
    static std::string subtractMinutes(std::string &time, int minutes);
    static std::chrono::system_clock::time_point convertStringToTimePoint(std::string &time);
};



