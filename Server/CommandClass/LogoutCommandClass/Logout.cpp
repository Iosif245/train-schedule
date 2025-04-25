#include "Logout.h"

void Logout::execute(Command_input &data){
    std::cout<<"The thread with ID "<<data.threadId<<" started executing logout command."<<std::endl;
    if(data.connected){
        data.connected = false;
        std::cout<<"Logout successfully"<<std::endl;
    }
    else
        Toolkit::Error("You are already logged out!");
    std::cout<<"The thread with ID "<<data.threadId<<" finished executing logout command."<<std::endl;
}
