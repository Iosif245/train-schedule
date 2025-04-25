#include "GetDepartureInfo.h"

void GetDepartureInfo::execute(Command_input &data){
    std::cout<<"The thread with ID "<<data.threadId<<" started executing get_departure_info command."<<std::endl;
    std::string msg;
    if(data.command == 4){
        for(auto &train :data.trains){
            for(auto &station:train.trainStations){
                if(Time::checkIfTimeIsInCurrentHour(station.departureTime) && (station.departureTime != "Finish"))
                {
                    msg+="The train with ID " + train.trainId + ", " + train.trainName + ", has " + train.trainFreeSeats+ " free seats and departure at " + station.cityName + " at ";
                    if(station.departureDelay == 0)
                        msg+=station.departureTime + " according to schedule.\n";
                    else if(station.departureDelay > 0)
                        msg+=station.departureTime + " with delay of " + std::to_string(station.departureDelay) + " minutes.\n";
                    else
                        msg+=station.departureTime + " with advance of " + std::to_string(station.departureDelay) + " minutes.\n";
                }
            }
        }
        if(msg.empty())
            msg = "No trains departure in next hour.\n";
    }else if(data.command == 5){
        if(Toolkit::checkStationName(data.stationName, data.trains)){
            for(auto &train :data.trains){
                for(auto &station:train.trainStations){
                    if(Time::checkIfTimeIsInCurrentHour(station.departureTime) && (station.cityName == data.stationName) && (station.departureTime != "Finish"))
                    {
                        msg+="The train with ID " + train.trainId + ", " + train.trainName + ", has " + train.trainFreeSeats+ " free seats and departure at " + station.cityName + " at ";
                        if(station.departureDelay == 0)
                            msg+=station.departureTime + " according to schedule.\n";
                        else if(station.departureDelay > 0)
                            msg+=station.departureTime + " with delay of " + std::to_string(station.departureDelay) + " minutes.\n";
                        else
                            msg+=station.departureTime + " with advance of " + std::to_string(station.departureDelay) + " minutes.\n";
                    }
                }
            }
            if(msg.empty())
                msg = "No trains departure in next hour.\n";
        }
        else
            msg = "No trains departure at " + data.stationName + " station.\n";
    }
    std::cout<<msg<<std::endl;
    std::cout<<"The thread with ID "<<data.threadId<<" finished executing get_departure_info command."<<std::endl;
}