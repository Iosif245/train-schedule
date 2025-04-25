#include "CallCommand.h"

void CallCommand::executeCommand(Command_input &data) {
    for(auto &pair:commands){
        if(pair.first == data.command) {
            Command *commandToExecute = pair.second;
            commandToExecute->execute(data);
            break;
        }
    }
}