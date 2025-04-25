#include <iostream>
#include <vector>
#include <string>
#include "../Command.h"
#include "../../ToolkitClass/Toolkit.h"

class Logout:public Command{
public:
    void execute(Command_input &data) override;
};
