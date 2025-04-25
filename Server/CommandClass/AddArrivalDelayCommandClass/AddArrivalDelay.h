#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../../Types/Train/Train.h"
#include "../../Types/Station/Station.h"
#include "../Command.h"
#include "../../ToolkitClass/Toolkit.h"
#include "../../XmlClass/Xml.h"

class AddArrivalDelay:public Command {
public:
    void execute(Command_input &data) override;
};
