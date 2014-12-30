#ifndef GTK_WRAPPER_H
#define GTK_WRAPPER_H
#include <cairo.h>
#include <gtk/gtk.h>
#include "Grid.h"
#include <SFML/Graphics.hpp>
#define DEF_SCREEN_X 400
#define DEF_SCREEN_Y 400
#define CELL_WEIGHT 5
#define CELL_SPACING 3
#define ANIMATION_SPEED_MS 500 //milliseconds
static sf::Color BACKGROUND(35, 35, 35);
static sf::Color RECT_COLOR(0, 145, 100);
static GdkRGBA color_dark = {.105, .105, .105, 1.0};

void render_iterations(Grid *, ushort);
void render_sfml();

#endif



