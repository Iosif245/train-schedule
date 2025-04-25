#pragma once

#include "../Types/Command_Input/Command_input.h"

class Command{
public:
    virtual void execute(Command_input &data) = 0;
};
