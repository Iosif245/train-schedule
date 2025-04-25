#pragma once
#include <iostream>
#include <vector>
#include <queue>

class NotificationStruct{
public:
    int socket=-1;
    std::vector <int>* previousCommands;
    explicit NotificationStruct(std::vector<int>* vec) : previousCommands(vec) {
    }
};
