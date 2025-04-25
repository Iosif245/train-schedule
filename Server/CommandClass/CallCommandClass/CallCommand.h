#pragma once
#include <iostream>
#include<vector>
#include <map>
#include "../Command.h"
#include "../GetArrivalInfoCommandClass/GetArrivalInfo.h"
#include "../GetDepartureInfoCommandClass/GetDepartureInfo.h"
#include "../LoginCommandClass/Login.h"
#include "../LogoutCommandClass/Logout.h"
#include "../AddArrivalDelayCommandClass/AddArrivalDelay.h"
#include "../AddDepartureDelayCommandClass/AddDepartureDelay.h"
#include "../GetTrainsInfoCommandClass/GetTrainsInfo.h"

class CallCommand {
public:
    std::map<int,Command*> commands;
    CallCommand(){
        commands[1] = new GetTrainsInfo();
        commands[2] = new GetArrivalInfo();
        commands[3] = new GetArrivalInfo();
        commands[4] = new GetDepartureInfo();
        commands[5] = new GetDepartureInfo();
        commands[6] = new AddArrivalDelay();
        commands[7] = new AddDepartureDelay();
        commands[8] = new Login();
        commands[9] = new Logout();
    };
    void executeCommand(Command_input &data);
};
