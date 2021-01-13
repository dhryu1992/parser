#include "example.h"
#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>
struct {
    cairo_surface_t *image;
} glob;

static void do_drawing(cairo_t *);

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	do_drawing(cr);

	return FALSE;
}

static void do_drawing(cairo_t *cr) {
	int text_term = 30;

	cairo_set_source_rgb(cr, 0.1, 0.1, 0.1);

	cairo_select_font_face(cr, "Purisa",
			CAIRO_FONT_SLANT_NORMAL,
			CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(cr, 13);

	for(int t = 0; t < 10; t++) {
		cairo_move_to(cr, 50, text_term);
		cairo_show_text(cr, text[t]);
		text_term = text_term + 30;
	    }
    
    int hight = text_term;
    for(int k = 0; k < 10; k++) {
        if(img[k] == NULL) { 
            printf("There is no image");
        } else {
        glob.image = cairo_image_surface_create_from_png(img[k]);
        cairo_set_source_surface(cr, glob.image, 200, hight);
        cairo_paint(cr);
            }
        }
    }


int main (int argc, char *argv[])
{
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
	
	gtk_window_set_default_size(GTK_WINDOW(window), 1300, 10000);	
	
	gtk_window_set_title(GTK_WINDOW(window), "Viewer");
	
	gtk_widget_show_all(window);

	gtk_main();

    cairo_surface_destroy(glob.image);

	return 0;
}
