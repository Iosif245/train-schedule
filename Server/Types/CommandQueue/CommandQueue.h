#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <pthread.h>
#include "../Command_Input/Command_input.h"
#include "../../CommandClass/CallCommandClass/CallCommand.h"

class CommandQueue {
public:
    static void* runQueue(void*);
};

