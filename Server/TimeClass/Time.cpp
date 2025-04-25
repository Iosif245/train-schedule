#include "Time.h"

std::string Time::getCurrentDate() {
    auto currentDate = std::chrono::system_clock::now();
    std::time_t date = std::chrono::system_clock::to_time_t(currentDate);
    std::tm* localTime= std::localtime(&date);
    std::ostringstream returnDate;
    returnDate << std::setfill('0') << std::setw(2) << localTime->tm_mday << "."
               << std::setfill('0') << std::setw(2) << localTime->tm_mon + 1 << "."
               << localTime->tm_year + 1900;
    return returnDate.str();
}

std::chrono::system_clock::time_point Time::getCurrentTime(){
    return std::chrono::system_clock::now();
}

std::chrono::system_clock::time_point Time::convertStringToTimePoint(std::string &timeString){
    std::tm timeStruct = {};
    std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* currentDateTime = std::localtime(&currentTime);
    timeStruct.tm_year = currentDateTime->tm_year;
    timeStruct.tm_mon = currentDateTime->tm_mon;
    timeStruct.tm_mday = currentDateTime->tm_mday;
    std::istringstream time(timeString);
    time >> std::get_time(&timeStruct, "%H:%M");
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(std::mktime(&timeStruct));
    return timePoint;
}

std::string Time::addMinutes(std::string &timeToChange, int minutes){
    std::tm timeStruct = {};
    std::cout<<timeToChange<<std::endl;
    std::cout<<minutes<<std::endl;
    std::istringstream time(timeToChange);
    time >> std::get_time(&timeStruct, "%H:%M");
    timeStruct.tm_min += minutes;
    if(timeStruct.tm_min >= 60){
        timeStruct.tm_hour += timeStruct.tm_min / 60;
        timeStruct.tm_min %= 60;
    }
    std::ostringstream returnTime;
    returnTime << std::setfill('0') << std::setw(2) << timeStruct.tm_hour << ":"
               << std::setfill('0') << std::setw(2) << timeStruct.tm_min;
    std::cout<<returnTime.str()<<std::endl;
    return returnTime.str();
}

std::string Time::subtractMinutes(std::string &timeToChange, int minutes){
    std::cout<<timeToChange<<std::endl;
    std::cout<<minutes<<std::endl;
    std::tm timeStruct = {};
    std::istringstream time(timeToChange);
    time >> std::get_time(&timeStruct, "%H:%M");
    timeStruct.tm_min += minutes;
    if(timeStruct.tm_min < 0){
        timeStruct.tm_hour--;
        timeStruct.tm_min += 60;
    }
    std::ostringstream returnTime;
    returnTime << std::setfill('0') << std::setw(2) << timeStruct.tm_hour << ":"
               << std::setfill('0') << std::setw(2) << timeStruct.tm_min;
    std::cout<<returnTime.str()<<std::endl;
    return returnTime.str();
}

bool Time::checkIfTimeIsInCurrentHour(std::string timeToCheck){
    auto currentTime=getCurrentTime();
    auto finishHourTime = currentTime + std::chrono::hours(1);
    auto time = convertStringToTimePoint(timeToCheck);
    return time >= currentTime && time <= finishHourTime;
}

bool Time::checkIfCurrentTimeIsGreaterThenTimeToCheck(std::string &timeToCheck){
    auto currentTime=getCurrentTime();
    auto time = convertStringToTimePoint(timeToCheck);
    return time <= currentTime;
}