#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../../Types/Train/Train.h"
#include "../../Types/Station/Station.h"
#include "../Command.h"
#include <fstream>
#include <algorithm>
#include <cerrno>
#include <cstring>
#include "../../TimeClass/Time.h"
#include "../../ToolkitClass/Toolkit.h"

class GetArrivalInfo:public Command {
public:
    void execute(Command_input &data) override;
};

