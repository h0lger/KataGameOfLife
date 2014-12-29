#ifndef GTK_WRAPPER_H
#define GTK_WRAPPER_H
#include <cairo.h>
#include <gtk/gtk.h>
#include "Grid.h"
#define DEF_SCREEN_X 400
#define DEF_SCREEN_Y 400
#define CELL_WEIGHT 5
#define CELL_SPACING 3
#define ANIMATION_SPEED_MS 500 //milliseconds 
static GdkRGBA color_dark = {.105, .105, .105, 1.0};

void render_iterations(Grid *, ushort);

#endif



