#include "GTKWrapper.h"

static void do_drawing(cairo_t *cr);

static void do_drawing(cairo_t *cr)
{
	cairo_set_source_rgb(cr, 0, .555, .100);

	cairo_rectangle(cr, 0, 0, CELL_WEIGHT, CELL_WEIGHT);
	cairo_rectangle(cr, (CELL_WEIGHT + CELL_SPACING), 0, CELL_WEIGHT, CELL_WEIGHT);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);
	
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

void show_window(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *darea;

	gtk_init(&argc, &argv);

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
