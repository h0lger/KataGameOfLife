#ifndef UTILS_H
#define UTILS_h
#include "Grid.h"
#define ANIMATION_SPEED 200

//Iterate generations
void IterateGens(Grid *gPtr, unsigned short n);

void Menu();

Grid *GetSimple();
Grid *GetGlider();
Grid *GetBlinker();

#endif