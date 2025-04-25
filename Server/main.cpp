#include "ToolkitClass/Toolkit.h"
#include "XmlClass/Xml.h"
#include "Types/CommandQueue/CommandQueue.h"
#include "Types/ThreadStruct/ThreadStruct.h"
#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 2048

static void* treat(void * arg) {
    ThreadData tdL;
    tdL= *((struct ThreadData*)arg);
    std::cout<<"Thread "<<tdL.threadId<<": Started working."<<std::endl;

    pthread_detach(pthread_self());

    std::cout<<"Thread "<<tdL.threadId<<": Finished working."<<std::endl;
    close ((intptr_t)arg);
    return(nullptr);
}

int main(){
    std::vector<std::string> users;
    Toolkit::getUsers(users);
//    for(auto &user:users){
//        std::cout<<user<<std::endl;
//    }
//    std::string user = "admin";
//    bool result = Toolkit::searchUser(user,users);
//    std::cout<<result;
    std::vector<Train> trains;
    Xml::parseXml(trains);
//    for(auto &train:trains){
//        std::cout<<train.trainId<<" "<<train.trainName<<" "<<train.trainFreeSeats<<std::endl;
//        for(auto &station:train.trainStations){
//            std::cout<<station.cityName<<" "<<station.arrivalTime<<" "<<station.arrivalDelay<<" "<<station.departureTime<<" "<<station.departureDelay<<std::endl;
//        }
//    };
//    std::string trainId = "CFR001";
//    std::string stationName = "Bacau";
//    Xml::updateXml(trains,-20,2,trainId,stationName);
//    for(auto &train:trains){
//        std::cout<<train.trainId<<" "<<train.trainName<<" "<<train.trainFreeSeats<<std::endl;
//        for(auto &station:train.trainStations){
//            std::cout<<station.cityName<<" "<<station.arrivalTime<<" "<<station.arrivalDelay<<" "<<station.departureTime<<" "<<station.departureDelay<<std::endl;
//        }
//    };
    CommandQueue queue;
    pthread_t id ;
    pthread_create (&id, NULL, &queue.runQueue, &id);

    struct sockaddr_in server;
    struct sockaddr_in from;
    int i = 0;
    int socketDescriptor;
    pthread_t th[100];

    // Socket initialization
    if ((socketDescriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "ERROR: Failed to create socket.\n");
        exit(1);
    }

    int on=1;
    setsockopt(socketDescriptor ,SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    bzero(&server, sizeof(server));
    bzero(&from, sizeof(from));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    if (bind(socketDescriptor, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1) {
        fprintf(stderr, "ERROR: Failed to bind.\n");
        exit(1);
    }

    if (listen (socketDescriptor, 2) == -1) {
        fprintf(stderr, "ERROR: Failed at listen.\n");
        exit(1);
    }
    std::cout<<"Waiting at port "<<PORT<<std::endl;
    while (1) {
        int client;
        ThreadData * td;
        socklen_t length = sizeof(from);

        if ((client = accept (socketDescriptor, (struct sockaddr *)&from, &length)) < 0) {
            fprintf(stderr, "ERROR: Failed to connect.\n");
            continue;
        }

        td=(struct ThreadData*)malloc(sizeof(struct ThreadData));
        td->threadId=i++;
        td->client=client;
        pthread_create(&th[i], NULL, &treat, td);
    }
    return 0;
}