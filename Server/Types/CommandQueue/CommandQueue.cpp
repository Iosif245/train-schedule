#include "CommandQueue.h"

void* CommandQueue::runQueue(void*){
    pthread_mutex_t commandQueueLock = PTHREAD_MUTEX_INITIALIZER;
    std::queue<Command_input> commandQueue;
    CallCommand currentCommand;
    while(1){
        if(commandQueue.empty())
            continue;
        pthread_mutex_lock(&commandQueueLock);
        Command_input command = commandQueue.front();
        currentCommand.executeCommand(command);
        commandQueue.pop();
        pthread_mutex_unlock(&commandQueueLock);
    }

    return nullptr;
}