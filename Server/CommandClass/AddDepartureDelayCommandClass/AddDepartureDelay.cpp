#include "AddDepartureDelay.h"

void AddDepartureDelay::execute(Command_input &data) {
    std::cout<<"The thread with ID "<<data.threadId<<" started executing add_departure_delay command."<<std::endl;
    if(data.connected){
        if(Toolkit::checkTrainId(data.trainId , data.trains)){
            if(Toolkit::checkStationName(data.stationName , data.trains)){
                Xml::updateXml( data.trains, data.delay, 2 , data.trainId, data.stationName);
            }
            else {
                std::cout<<"The station with name "<<data.stationName<<" does not exist."<<std::endl;
            }
        }else{
            std::cout<<"The train with ID "<<data.trainId<<" does not exist."<<std::endl;
        }
    }
    else{
        std::cout<<"You need to be logged in to execute this command";
    }
    std::cout<<"The thread with ID "<<data.threadId<<" finished executing add_departure_delay command."<<std::endl;
}