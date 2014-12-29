#include "GTKWrapper.h"
#include "Grid.h"

Grid *_gPtr = NULL;
ushort _iter = 0; //Number of iterations
struct timespec _timReq, _timRem;

static void do_drawing(cairo_t *);
static void iterate(cairo_t *);

static void iterate(cairo_t *cr)
{
	Cell **tmpC = _gPtr->GetCells();
	ushort xOffset = 0;
	ushort yOffset = 0;
	
	for (size_t r = 0; r < _gPtr->ArrSize(); r++) //rows
	{
		Cell *rCell = tmpC[r];
		for (size_t c = 0; c < _gPtr->ArrSize(); c++) //cells
		{
			if (rCell[c].IsAlive())
			{
				cairo_rectangle(cr, xOffset, yOffset, CELL_WEIGHT, CELL_WEIGHT);				
				cairo_stroke_preserve(cr);
				cairo_fill(cr);
			}
			//increase x offset for every cell
			xOffset += CELL_WEIGHT + CELL_SPACING;
		}
			//increase y offset for every row
			yOffset += CELL_WEIGHT + CELL_SPACING;
			xOffset = 0;
		}
}

static void do_drawing(cairo_t *cr)
{
	cairo_set_source_rgb(cr, 0, .555, .100);
	
	iterate(cr); //if _iter == 0 just for showing
	
	for(size_t i = 0;i < _iter;i++)
	{
		//nanosleep(&_timReq, &_timRem);
		_gPtr->NextGeneration();
		iterate(cr);		
	}
		
		
	// cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	// cairo_set_font_size(cr, 40.0);
	// cairo_move_to(cr, 10.0, 50.0);
	// cairo_show_text(cr, "Hello David");

}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
	do_drawing(cr);

	return false;
}

void render_iterations(Grid *gPtr, ushort n)
{
	GtkWidget *window;
	GtkWidget *darea;
	
	//Initialize some members
	_gPtr = gPtr;
	_iter = n;
	_timReq.tv_sec = 0;
	_timReq.tv_nsec = ANIMATION_SPEED_MS * 1000000;
	
	gtk_init(NULL, NULL);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);

	g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(on_draw_event), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), DEF_SCREEN_X, DEF_SCREEN_Y);
	gtk_window_set_title(GTK_WINDOW(window), "KataGameOfLife");
	gtk_widget_override_background_color(darea, GTK_STATE_FLAG_NORMAL, &color_dark);

	gtk_widget_show_all(window);
	gtk_main();	
}