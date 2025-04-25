#include "Toolkit.h"
#include <fstream>
#include <algorithm>
#include <cerrno>
#include <cstring>

void Toolkit::getUsers(std::vector<std::string>& users){
    std::ifstream usersFile("../ToolkitClass/users.txt");
    if(!usersFile.is_open()){
        std::cerr<<strerror(errno);
    }
    std::string user;
    while(usersFile >> user){
        users.push_back(user);
    }
    usersFile.close();
}

bool Toolkit::searchUser(const std::string &user, std::vector<std::string>& users){
    bool result = std::any_of(users.begin(), users.end(), [user](const std::string &name){
        return name == user;
    });
    return result;
}

bool Toolkit::checkTrainId(const std::string &trainId, std::vector<Train> &trains){
    bool result = std::any_of(trains.begin(), trains.end(), [trainId](const Train &train){
        return train.trainId == trainId;
    });
    return result;
}

void Toolkit::Error(const std::string &msg) {
    std::cout<< msg << std::endl;
}

bool Toolkit::checkStationName(const std::string &stationName, std::vector<Train> &trains) {
    bool result = std::any_of(trains.begin(), trains.end(), [stationName](const Train &train){
        return std::any_of(train.trainStations.begin(), train.trainStations.end(), [stationName](const Station &station){
            return station.cityName == stationName;
        });
    });
    return result;
}