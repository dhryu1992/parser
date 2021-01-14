#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>           // printf 함수, gets_s 함수를 사용하기 위해!
#include <string.h>          // strlen 함수를 사용하기 위해!
#include <malloc.h>          // malloc 함수, free 함수를 사용하기 위해!
#include <stdlib.h>
#include "variable.h"
#include "cairo_variable.h"
#include "example.h"
#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>

char *arr[126] = {0,};
char *output;

int main(int argc, char *argv[])
{   
    int a = 1;
    int *order = &a;
    int t_num;
    int b = 0; 
    int c = 0;
    int i = 0;
    char buffer[MAX_LENGTH] = {0, };
    char *temp = malloc(sizeof(char));
    char *element = malloc(sizeof(char));
    char *tagname = malloc(sizeof(char));
    char *context = malloc(sizeof(char)*MAX_LENGTH*2);
    char *text = malloc(sizeof(char));
    char *attname = malloc(sizeof(char));
    char *value = malloc(sizeof(char));
    for(i = 0; i<126; i++){
        arr[i] = malloc(sizeof(char));
    }
 
    *context = 0;   *text = 0;
    *element = 0;   *tagname = 0;
    *attname = 0;   *value = 0;
    *temp = 0;
    
    if(argc > 2)
        printf("입력오류 (main.o 파일명)\n");
    else{
        FILE *fp = fopen(argv[1],"r");
        if (fp == NULL) {
            fclose(fp);
            return 1;
        }

        while((feof(fp)) == 0)  //파일 끝까지 1바이트씩 buffer로 읽어온 후 context로 이동
        {
            fread(&buffer,sizeof(char),1,fp);
            if(feof(fp)==0) // 파일의 포인터가 파일의 끝이 아닐때 
                strcat(context, buffer); // buffer을 context 뒤에 이어붙힘.
        }
        fclose(fp);
    }
    sptr=context;
    ptr=&sptr[1];
    eptr = &ptr[0];
    printf("--Parsing-- \n");
    while(strncmp(ptr,"\0",1)!=0){
        ptr=&ptr[1]; 
        if(strncmp(ptr,">",1)==0){//<태그>태그 확인
            
            docParsing(element, attname, value);
            headParsing(element, text, tagname, temp);
            bodyParsing(element, text, tagname, value, temp, attname);
			
        }
        else if(strncmp(ptr,"<",1)==0){// <검출 위의 if문과 합쳐져서 태그 획득
            sptr=&ptr[0];
        }       
    }
    printf("--TreeNode-- \n");
    while(1){
        if(strcmp(arr[b],"\0")==0){
            b = *order;
            // printf("break;\n");
            // printf("%d %d\n",b, *order);
            break;
        }
        
        createDom(arr,order,&t_num);
        b = *order;
        // c = *t_num;
        // printf("%d\n",b);
        // printf("%s\n",output);
    }
    printf("--Dom Tree-- \n");
    showTree(t_num);
    freeNode();
    // while(strcmp(arr[i],"\0")!=0){
    //     printf("arr[%d] %s\n",i, arr[i]);
    // }
    for(i = 0; i<126; i++){
        free(arr[i]);
    }
    free(context);  free(element);
    free(text);     free(tagname);
    free(attname);  free(temp);
    free(value);  
	
	//printf("cairo_text: %s", cairo_text);
    //-----Cairo---------------------------------------------------------------
struct {
    cairo_surface_t *image;
} glob;

void do_drawing(cairo_t *cr) {
//-----------------------------text--------------------
	int text_term = 30;

	cairo_set_source_rgb(cr, 0.1, 0.1, 0.1);

	cairo_select_font_face(cr, "Purisa",
			CAIRO_FONT_SLANT_NORMAL,
			CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(cr, 13);

	for(int t = 0; t <= 3; t++) {
		cairo_move_to(cr, 20, text_term);
		cairo_show_text(cr, cairo_text[t]);
		text_term = text_term + 30;
	    }
//--------------------------------image------------------
    int hight = text_term;
    for(int imgCount = 0; imgCount < 2; imgCount++) {
        if(img[k] == NULL) {
            printf("There is no image");
        } else {
        glob.image = cairo_image_surface_create_from_png(cairo_img[0]);

        cairo_set_source_surface(cr, glob.image, atoi(cairo_img[2]), atoi(cairo_img[3]));
        cairo_paint(cr);
            }
		}
    }

gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	do_drawing(cr);

	return FALSE;
}
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

	gtk_window_set_default_size(GTK_WINDOW(window), 1300, 1000);

	gtk_window_set_title(GTK_WINDOW(window), "Viewer");

	gtk_widget_show_all(window);

	gtk_main();

    cairo_surface_destroy(glob.image);

    return 0;    
}
