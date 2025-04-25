#include "../Command.h"
#include <iostream>
#include <string>
#include <vector>
#include "../../Types/Train/Train.h"
#include "../../Types/Station/Station.h"
#include "../../TimeClass/Time.h"

class GetTrainsInfo:public Command {
public:
    void execute(Command_input &data) override;
};

