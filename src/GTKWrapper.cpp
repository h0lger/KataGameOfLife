#include "GTKWrapper.h"

//static void do_drawing(cairo_t *cr);

static void do_drawing(cairo_t *cr)
{
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr, 40.0);
	cairo_move_to(cr, 10.0, 50.0);
	cairo_show_text(cr, "Hello David");

}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
	do_drawing(cr);

	return false;
}
