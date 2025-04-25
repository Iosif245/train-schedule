#include "Login.h"

void Login::execute(Command_input &data){
    std::cout<<"The thread with ID "<<data.threadId<<" started executing login command."<<std::endl;
    if(data.connected)
        Toolkit::Error("You are already connected!");
    else{
        data.connected = Toolkit::searchUser(data.username, data.users);
        if(data.connected)
            std::cout<<"The user "<<data.username<<" was successfully logged!";
        else
            Toolkit::Error("The user " + data.username + "not found");
    }
    std::cout<<"The thread with ID "<<data.threadId<<" finished executing login command."<<std::endl;
}