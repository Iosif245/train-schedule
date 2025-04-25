#include "Socket.h"

void Socket::writeToClient(int socket, std::string &msg) {
    unsigned long msgSize = msg.length();
    long sendMsgSize = send(socket, &msgSize, sizeof(long), 0);
    if (sendMsgSize == -1) {
        std::cout << "Error: Couldn't send the message to client." << std::endl;
    }
    char* msgToSend = new char[msgSize];
    strcpy(msgToSend, msg.c_str());
    msgToSend[msgSize] = '\0';
    long sendMsg = send(socket, msgToSend, msgSize +1 , 0);
    if (sendMsg == -1) {
        std::cout << "Error: Couldn't send the message to client." << std::endl;
    }
}

void::Socket::readFromClient(int socket){
    int command;
    int receiveCommand = recv(socket, &command, sizeof(int), 0);
    if (receiveCommand == -1) {
        std::cout << "Error: Couldn't receive the message to client." << std::endl;
    }
    command = ntohl(command);

    if(command == 3 || command == 5 || command == 6 || command == 7 || command == 8){
        std::cout<<"trb sa iau msg";
    }
}
