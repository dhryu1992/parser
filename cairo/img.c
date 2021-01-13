#include "example.h"
#include <cairo.h> 
#include <gtk/gtk.h> 

int main(int argc, char *argv[]) {

struct { 
	cairo_surface_t *image; 
} glob; 

//void do_drawing(cairo_t *); 
void do_drawing(cairo_t *cr) {
	int h = 50;
	
	for(int k = 0; k < 2; k++) {  	
		if(img[k] != NULL) {
			glob.image = cairo_image_surface_create_from_png(img[k]); 
			cairo_set_source_surface(cr, glob.image, 10, 250);
			cairo_paint(cr);
			//h = atoi(height[k]) + h;
		}else{
			printf("No image\n");
		}
	}	
}

gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	do_drawing(cr); 

    return FALSE; 
}


	GtkWidget *window;
    GtkWidget *darea;
	//Array();	
	
	//glob.image = cairo_image_surface_create_from_png(img[0]); 

	gtk_init(&argc, &argv); 

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 

	darea = gtk_drawing_area_new(); 
	gtk_container_add(GTK_CONTAINER (window), darea); 

	g_signal_connect(G_OBJECT(darea), "draw", 
            G_CALLBACK(on_draw_event), NULL); 
	
    g_signal_connect(window, "destroy", 
            G_CALLBACK (gtk_main_quit), NULL);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); 

	gtk_window_set_default_size(GTK_WINDOW(window), 1250, 800); 

	gtk_window_set_title(GTK_WINDOW(window), "Image"); 

	gtk_widget_show_all(window);
    
    gtk_main(); 

	cairo_surface_destroy(glob.image); 

	return 0; 
}
