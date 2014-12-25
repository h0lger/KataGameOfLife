#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include "Grid.h"

bool UnitTest_Print();
bool UnitTest_NextGen_Glider();
bool UnitTest_NextGen_Blinker();
Grid *GetSimple();
Grid *GetGlider();
Grid *GetBlinker();

#endif