#pragma once
#include "../Command.h"
#include "../../ToolkitClass/Toolkit.h"

class Login: public Command {
public:
    void execute(Command_input &data) override;
};

