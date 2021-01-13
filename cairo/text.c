//#include "example.h"
#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>
char *text[10] = {"abcd", "efgh"};
static void do_drawing(cairo_t *);
static void do_drawing(cairo_t *cr) {
	int a = 30;

	cairo_set_source_rgb(cr, 0.1, 0.1, 0.1);

	cairo_select_font_face(cr, "Purisa",
			CAIRO_FONT_SLANT_NORMAL,
			CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(cr, 13);

	for(int t = 0; t < 10; t++) {
		cairo_move_to(cr, 20, a);
		cairo_show_text(cr, text[t]);
		a = a + 30;
	    }
}


static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,
		gpointer user_data)
{
	do_drawing(cr);

	return FALSE;
}

int main (int argc, char *argv[])
{
	


	//printf("1\n");
	//Array();	
	//printf("2\n");
	GtkWidget *window;
	GtkWidget *darea;


	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);
	
	g_signal_connect(G_OBJECT(darea), "draw",
			G_CALLBACK(on_draw_event), NULL);
	
	g_signal_connect(G_OBJECT(window), "destroy",
			G_CALLBACK(gtk_main_quit), NULL);
	

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	gtk_window_set_default_size(GTK_WINDOW(window), 1000, 1000);	
	
	gtk_window_set_title(GTK_WINDOW(window), "Viewer");
	
	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
