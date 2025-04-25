#include "GetArrivalInfo.h"

void GetArrivalInfo::execute(Command_input &data){
    std::cout<<"The thread with ID "<<data.threadId<<" started executing get_arrival_info command."<<std::endl;
    std::string msg;
    if(data.command == 2){
            for(auto &train :data.trains){
                for(auto &station:train.trainStations){
                    if(Time::checkIfTimeIsInCurrentHour(station.arrivalTime) && (station.arrivalTime != "Start"))
                    {
                        msg+="The train with ID " + train.trainId + ", " + train.trainName + ", has " + train.trainFreeSeats+ " free seats and arrive at " + station.cityName + " at ";
                        if(station.arrivalDelay == 0)
                            msg+=station.arrivalTime + " according to schedule.\n";
                        else if(station.arrivalDelay > 0)
                            msg+=station.arrivalTime + " with delay of " + std::to_string(station.arrivalDelay) + " minutes.\n";
                        else
                            msg+=station.arrivalTime + " with advance of " + std::to_string(station.arrivalDelay) + " minutes.\n";
                    }
                }
            }
            if(msg.empty())
                msg = "No trains arrive in next hour.\n";
    }else if(data.command == 3){
        if(Toolkit::checkStationName(data.stationName, data.trains)){
            for(auto &train :data.trains){
                for(auto &station:train.trainStations ){
                    if(Time::checkIfTimeIsInCurrentHour(station.arrivalTime) && (station.cityName == data.stationName) && (station.arrivalTime != "Start"))
                    {
                        msg+="The train with ID " + train.trainId + ", " + train.trainName + ", has " + train.trainFreeSeats+ " free seats and arrive at " + station.cityName + " at ";
                        if(station.arrivalDelay == 0)
                            msg+=station.arrivalTime + " according to schedule.\n";
                        else if(station.arrivalDelay > 0)
                            msg+=station.arrivalTime + " with delay of " + std::to_string(station.arrivalDelay) + " minutes.\n";
                        else
                            msg+=station.arrivalTime + " with advance of " + std::to_string(station.arrivalDelay) + " minutes.\n";
                    }
                }
            }
            if(msg.empty())
                msg = "No trains arrive in next hour.\n";
        }
        else
            msg = "No trains arrive at " + data.stationName + " station.\n";
    }
    std::cout<<msg<<std::endl;
    std::cout<<"The thread with ID "<<data.threadId<<" finished executing get_arrival_info command."<<std::endl;
}