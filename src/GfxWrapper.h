#ifndef GFX_WRAPPER_H

#include "Grid.h"
#include <SFML/Graphics.hpp>

#define GFX_WRAPPER_H
#define DEF_SCREEN_X 500 //default x
#define DEF_SCREEN_Y 500 //default y
#define CELL_WEIGHT 6
#define CELL_SPACING 3
#define ANIMATION_SPEED_MS 200 //milliseconds
#define DEF_ANTIALAISING 8

static sf::Color BACKGROUND(35, 35, 35);
static sf::Color RECT_COLOR(0, 145, 100);


void render_iterations(Grid *, ushort);

#endif



