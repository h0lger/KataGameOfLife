#ifndef UTILS_H
#define UTILS_H
#include "Grid.h"
#define DEF_GRID_SIZE_SIMPLE 40
#define DEF_GRID_SIZE_TEXTURE 20

void Menu();

Grid *GetSimple(unsigned short);
Grid *GetGlider(unsigned short);
Grid *GetBlinker(unsigned short);

void ClearTerminal();

#endif