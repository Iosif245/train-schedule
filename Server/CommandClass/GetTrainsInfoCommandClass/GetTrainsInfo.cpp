#include "GetTrainsInfo.h"

void GetTrainsInfo::execute(Command_input &data){
    std::cout<<"The thread with ID "<<data.threadId<<" started executing get_trains_info command."<<std::endl;
    std::string msg="The trains running today are:\n";
    std::string currentDate = Time::getCurrentDate();
    for(auto &train:data.trains){
        if(train.date == currentDate){
            msg+="The train with ID " + train.trainId + ", " + train.trainName + ", has " + train.trainFreeSeats + " free seats and the schedule is:\n";
            for(auto &station:train.trainStations){
                if(station.arrivalTime == "Start"){
                    msg+="The train starts from " + station.cityName + " at" + station.departureTime;
                    if(station.departureDelay == 0)
                        msg+=" according to schedule.\n";
                    else
                        msg+=" with a delay of " + std::to_string(station.departureDelay) + " minutes.\n";
                }
                else if(station.departureTime == "Finish"){
                    msg+="The train arrives at " + station.cityName + " at" + station.arrivalTime;
                    if(station.arrivalDelay == 0)
                        msg+=" according to schedule.\n";
                    else if(station.arrivalDelay > 0)
                        msg+=" with a delay of " + std::to_string(station.arrivalDelay) + " minutes.\n";
                    else
                        msg+=" with an advance of " + std::to_string(station.arrivalDelay) + " minutes.\n";
                }
                else{
                    msg+="The train arrives at " + station.cityName + " at" + station.arrivalTime;
                    if(station.arrivalDelay == 0)
                        msg+=" according to schedule.\n";
                    else if(station.arrivalDelay > 0)
                        msg+=" with a delay of " + std::to_string(station.arrivalDelay) + " minutes.\n";
                    else
                        msg+=" with an advance of " + std::to_string(station.arrivalDelay) + " minutes.\n";
                    msg+="The train starts from " + station.cityName + " at" + station.departureTime;
                    if(station.departureDelay == 0)
                        msg+=" according to schedule.\n";
                    else if(station.departureDelay > 0)
                        msg+=" with a delay of " + std::to_string(station.departureDelay) + " minutes.\n";
                    else
                        msg+=" with an advance of " + std::to_string(station.departureDelay) + " minutes.\n";
                }
            }
        }

    }
    std::cout<<msg<<std::endl;
    std::cout<<"The thread with ID " << data.threadId << " finished executing get_trains_info command."<<std::endl;
}