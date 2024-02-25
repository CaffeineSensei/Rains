#include "util.h"
#include <iostream>
bool shouldExit = false;

void ut::exitLoop()
{
    getchar();
    shouldExit = true;
}
