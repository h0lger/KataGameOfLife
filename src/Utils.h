#ifndef UTILS_H
#define UTILS_H
#include "Grid.h"
#define ANIMATION_SPEED 500000

//Iterate generations
void IterateGens(Grid *gPtr, unsigned short n);

void Menu();

Grid *GetSimple();
Grid *GetGlider();
Grid *GetBlinker();

void ClearTerminal();

#endif