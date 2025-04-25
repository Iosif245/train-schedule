#include "Xml.h"
#include "../tinyxml2/tinyxml2.h"

void Xml::parseXml(std::vector<Train> &trains) {
    trains.clear();
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError file = doc.LoadFile("../XmlClass/data.xml");
    if (file == tinyxml2::XML_SUCCESS) {
        tinyxml2::XMLElement *root = doc.FirstChildElement("trainList");
        if (root) {
            tinyxml2::XMLElement *train = root->FirstChildElement("train");
            while (train) {
                Train newTrain;
                newTrain.trainName = train->FirstChildElement("name")->GetText();
                newTrain.trainId = train->FirstChildElement("Id")->GetText();
                newTrain.trainFreeSeats = train->FirstChildElement("trainFreeSeats")->GetText();
                newTrain.date = train->FirstChildElement("date")->GetText();
                tinyxml2::XMLElement *stationList = train->FirstChildElement("stationList");
                tinyxml2::XMLElement *station = stationList->FirstChildElement("station");
                while (station) {
                    Station newStation;
                    newStation.cityName = station->FirstChildElement("cityName")->GetText();
                    newStation.arrivalTime = station->FirstChildElement("arrivalTime")->GetText();
                    newStation.arrivalDelay = atoi(station->FirstChildElement("arrivalDelay")->GetText());
                    newStation.departureTime = station->FirstChildElement("departureTime")->GetText();
                    newStation.departureDelay = atoi(station->FirstChildElement("departureDelay")->GetText());
                    newTrain.trainStations.push_back(newStation);
                    station = station->NextSiblingElement("station");
                }
                trains.push_back(newTrain);
                train = train->NextSiblingElement("train");
            }
        } else {
            std::cerr << strerror(errno);
        }
    } else {
        std::cerr << strerror(errno);
    }
}

void Xml::updateXml(std::vector<Train>&trains , int newDelay, int delayType, std::string &trainId, std::string &stationName) {
    std::string newData;
    int currentDelay;
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError file = doc.LoadFile("../XmlClass/data.xml");
    if (file == tinyxml2::XML_SUCCESS) {
        tinyxml2::XMLElement *root = doc.FirstChildElement("trainList");
        if (root) {
            tinyxml2::XMLElement *train = root->FirstChildElement("train");
            while (train) {
                std::cout << 3;
                if (std::strcmp(train->FirstChildElement("Id")->GetText(), trainId.c_str()) == 0) {
                    tinyxml2::XMLElement *stationList = train->FirstChildElement("stationList");
                    tinyxml2::XMLElement *station = stationList->FirstChildElement("station");
                    std::cout << 9;
                    while (station) {
                        std::cout << 4;
                        if (std::strcmp(station->FirstChildElement("cityName")->GetText(), stationName.c_str()) == 0) {
                            std::cout << 6;
                            if (delayType == 1) {
                                if (newDelay == 0)
                                    std::cout << "The delay need to be less or greater then 0.\n";
                                else if (newDelay < 0) {
                                    if (std::strcmp(station->FirstChildElement("arrivalTime")->GetText(), "Start") !=
                                        0) {
                                        newData = station->FirstChildElement("arrivalTime")->GetText();
                                        station->FirstChildElement("arrivalTime")->SetText(
                                                Time::subtractMinutes(newData, newDelay).c_str());
                                        currentDelay =
                                                atoi(station->FirstChildElement("arrivalDelay")->GetText()) + newDelay;
                                        station->FirstChildElement("arrivalDelay")->SetText(
                                                std::to_string(currentDelay).c_str());

                                        if (std::strcmp(station->FirstChildElement("departureTime")->GetText(),
                                                        "Finish") !=
                                            0) {
                                            newData = station->FirstChildElement("departureTime")->GetText();
                                            station->FirstChildElement("departureTime")->SetText(
                                                    Time::subtractMinutes(newData, newDelay).c_str());
                                            currentDelay =
                                                    atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                    newDelay;
                                            station->FirstChildElement("departureDelay")->SetText(
                                                    std::to_string(currentDelay).c_str());
                                        }
                                    } else {
                                        newData = station->FirstChildElement("departureTime")->GetText();
                                        station->FirstChildElement("departureTime")->SetText(
                                                Time::subtractMinutes(newData, newDelay).c_str());
                                        currentDelay =
                                                atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                newDelay;
                                        station->FirstChildElement("departureDelay")->SetText(
                                                std::to_string(currentDelay).c_str());
                                    }
                                } else {
                                    if (std::strcmp(station->FirstChildElement("arrivalTime")->GetText(), "Start") !=
                                        0) {
                                        newData = station->FirstChildElement("arrivalTime")->GetText();
                                        station->FirstChildElement("arrivalTime")->SetText(
                                                Time::addMinutes(newData, newDelay).c_str());
                                        currentDelay =
                                                atoi(station->FirstChildElement("arrivalDelay")->GetText()) + newDelay;
                                        station->FirstChildElement("arrivalDelay")->SetText(
                                                std::to_string(currentDelay).c_str());
                                        if (std::strcmp(station->FirstChildElement("departureTime")->GetText(),
                                                        "Finish") !=
                                            0) {
                                            newData = station->FirstChildElement("departureTime")->GetText();
                                            station->FirstChildElement("departureTime")->SetText(
                                                    Time::addMinutes(newData, newDelay).c_str());
                                            currentDelay =
                                                    atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                    newDelay;
                                            station->FirstChildElement("departureDelay")->SetText(
                                                    std::to_string(currentDelay).c_str());
                                            std::cout << currentDelay << std::endl;
                                        }
                                    } else {
                                        newData = station->FirstChildElement("departureTime")->GetText();
                                        station->FirstChildElement("departureTime")->SetText(
                                                Time::addMinutes(newData, newDelay).c_str());
                                        currentDelay =
                                                atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                newDelay;
                                        station->FirstChildElement("departureDelay")->SetText(
                                                std::to_string(currentDelay).c_str());
                                        std::cout << currentDelay << std::endl;
                                    }
                                }
                            } else {
                                if (newDelay == 0)
                                    std::cout << "The delay need to be less or greater then 0.\n";
                                else if (newDelay < 0) {
                                    if (std::strcmp(station->FirstChildElement("departureTime")->GetText(), "Finish") !=
                                        0) {
                                        newData = station->FirstChildElement("departureTime")->GetText();
                                        station->FirstChildElement("departureTime")->SetText(
                                                Time::subtractMinutes(newData, newDelay).c_str());
                                        currentDelay =
                                                atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                newDelay;
                                        station->FirstChildElement("departureDelay")->SetText(
                                                std::to_string(currentDelay).c_str());
                                    }
                                } else {
                                    if (std::strcmp(station->FirstChildElement("departureTime")->GetText(), "Finish") !=
                                        0) {
                                        newData = station->FirstChildElement("departureTime")->GetText();
                                        station->FirstChildElement("departureTime")->SetText(
                                                Time::addMinutes(newData, newDelay).c_str());
                                        currentDelay =
                                                atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                newDelay;
                                        station->FirstChildElement("departureDelay")->SetText(
                                                std::to_string(currentDelay).c_str());
                                    }
                                }
                            }
                            station = station->NextSiblingElement("station");
                            while (station) {
                                std::cout<<station->FirstChildElement("cityName")->GetText()<<std::endl;
                                if (delayType == 1) {
                                    if (newDelay == 0)
                                        std::cout << "The delay need to be less or greater then 0.\n";
                                    else if (newDelay < 0) {
                                        if (std::strcmp(station->FirstChildElement("arrivalTime")->GetText(),
                                                        "Start") !=
                                            0) {
                                            newData = station->FirstChildElement("arrivalTime")->GetText();
                                            station->FirstChildElement("arrivalTime")->SetText(
                                                    Time::subtractMinutes(newData, newDelay).c_str());
                                            currentDelay =
                                                    atoi(station->FirstChildElement("arrivalDelay")->GetText()) +
                                                    newDelay;
                                            station->FirstChildElement("arrivalDelay")->SetText(
                                                    std::to_string(currentDelay).c_str());
                                            if (std::strcmp(station->FirstChildElement("departureTime")->GetText(),
                                                            "Finish") != 0) {
                                                newData = station->FirstChildElement("departureTime")->GetText();
                                                station->FirstChildElement("departureTime")->SetText(
                                                        Time::subtractMinutes(newData, newDelay).c_str());
                                                currentDelay =
                                                        atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                        newDelay;
                                                station->FirstChildElement("departureDelay")->SetText(
                                                        std::to_string(currentDelay).c_str());
                                            }
                                        } else {
                                            newData = station->FirstChildElement("departureTime")->GetText();
                                            station->FirstChildElement("departureTime")->SetText(
                                                    Time::subtractMinutes(newData, newDelay).c_str());
                                            currentDelay =
                                                    atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                    newDelay;
                                            station->FirstChildElement("departureDelay")->SetText(
                                                    std::to_string(currentDelay).c_str());
                                        }
                                    } else {
                                        if (std::strcmp(station->FirstChildElement("arrivalTime")->GetText(),
                                                        "Start") !=
                                            0) {
                                            newData = station->FirstChildElement("arrivalTime")->GetText();
                                            station->FirstChildElement("arrivalTime")->SetText(
                                                    Time::addMinutes(newData, newDelay).c_str());
                                            currentDelay =
                                                    atoi(station->FirstChildElement("arrivalDelay")->GetText()) +
                                                    newDelay;
                                            station->FirstChildElement("arrivalDelay")->SetText(
                                                    std::to_string(currentDelay).c_str());
                                            if (std::strcmp(station->FirstChildElement("departureTime")->GetText(),
                                                            "Finish") != 0) {
                                                newData = station->FirstChildElement("departureTime")->GetText();
                                                station->FirstChildElement("departureTime")->SetText(
                                                        Time::addMinutes(newData, newDelay).c_str());
                                                currentDelay =
                                                        atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                        newDelay;
                                                station->FirstChildElement("departureDelay")->SetText(
                                                        std::to_string(currentDelay).c_str());
                                            }
                                        } else {
                                            newData = station->FirstChildElement("departureTime")->GetText();
                                            station->FirstChildElement("departureTime")->SetText(
                                                    Time::addMinutes(newData, newDelay).c_str());
                                            currentDelay = atoi(station->FirstChildElement("departureDelay")->GetText()) +newDelay;
                                            station->FirstChildElement("departureDelay")->SetText(
                                                    std::to_string(currentDelay).c_str());
                                        }
                                    }
                                } else {
                                    if (newDelay == 0)
                                        std::cout << "The delay need to be less or greater then 0.\n";
                                    else if (newDelay < 0) {
                                        newData = station->FirstChildElement("arrivalTime")->GetText();
                                        station->FirstChildElement("arrivalTime")->SetText(
                                                Time::subtractMinutes(newData, newDelay).c_str());
                                        currentDelay =
                                                atoi(station->FirstChildElement("arrivalDelay")->GetText()) + newDelay;
                                        station->FirstChildElement("arrivalDelay")->SetText(
                                                std::to_string(currentDelay).c_str());
                                        if (std::strcmp(station->FirstChildElement("departureTime")->GetText(),
                                                        "Finish") !=
                                            0) {
                                            newData = station->FirstChildElement("departureTime")->GetText();
                                            station->FirstChildElement("departureTime")->SetText(
                                                    Time::subtractMinutes(newData, newDelay).c_str());
                                            currentDelay =
                                                    atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                    newDelay;
                                            station->FirstChildElement("departureDelay")->SetText(
                                                    std::to_string(currentDelay).c_str());
                                        }
                                    } else {
                                        newData = station->FirstChildElement("arrivalTime")->GetText();
                                        station->FirstChildElement("arrivalTime")->SetText(
                                                Time::addMinutes(newData, newDelay).c_str());
                                        currentDelay =
                                                atoi(station->FirstChildElement("arrivalDelay")->GetText()) + newDelay;
                                        station->FirstChildElement("arrivalDelay")->SetText(
                                                std::to_string(currentDelay).c_str());
                                        if (std::strcmp(station->FirstChildElement("departureTime")->GetText(),
                                                        "Finish") !=
                                            0) {
                                            newData = station->FirstChildElement("departureTime")->GetText();
                                            station->FirstChildElement("departureTime")->SetText(
                                                    Time::addMinutes(newData, newDelay).c_str());
                                            currentDelay =
                                                    atoi(station->FirstChildElement("departureDelay")->GetText()) +
                                                    newDelay;
                                            station->FirstChildElement("departureDelay")->SetText(
                                                    std::to_string(currentDelay).c_str());
                                        }
                                    }
                                }
                                station = station->NextSiblingElement("station");
                            }
                        } else {
                            station = station->NextSiblingElement("station");
                            std::cout << 8;
                        }
                    }
                }
                train = train->NextSiblingElement("train");
            }
        }
    }
    tinyxml2::XMLError saveResult = doc.SaveFile("../XmlClass/data.xml");
    Xml::parseXml(trains);
}