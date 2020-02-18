#include <cairo.h>
#include <gtk/gtk.h>
#include <pthread.h>
#include "wrapper.h"
#include "linkedList.h"
#include "math.h"
#define SERVERCONNECTMQ "/serverconnectionMQlab3"
#define MAX_CLIENTS 10
#define G_CONSTANT 6.67259e-11
#define DT 10
#define draw_circle 2*3.1415
#define BOUNDARY_X 800
#define BOUNDARY_Y 600

/*FUNCTION DECLARATION*/
static void do_drawing(cairo_t *);

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);

static void do_drawing(cairo_t *cr);

void Graphical_Interface(int argc, char *argv[]);

GtkTickCallback on_frame_tick(GtkWidget * widget, GdkFrameClock * frame_clock, gpointer user_data);

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);

void *recieveConnections();

void *recievePlanets();

void* planet_Physics(planet_type* planet);

typedef struct connection_type{
    int id;
    mqd_t mqPlanet;
    mqd_t mqMessage;
}connection_type;

//Global variables
GtkWidget *window;
GtkWidget *darea;
pthread_t thread_ID;
mqd_t messageQueue;
connection_type connections[MAX_CLIENTS];
planet_type* data;
pthread_mutex_t dataChange_mutex;

int main(int argc, char *argv[]){
    for(int i = 0; i < MAX_CLIENTS; i++){
        connections[i].id = 0;
    }
    data = NULL;
    pthread_mutex_init(&dataChange_mutex,NULL);
    void *status;
//  Draw GTK window
	Graphical_Interface(argc,argv);
//	create thread for receiving connections
	pthread_create(&thread_ID, NULL,recieveConnections , NULL);
//	create thread for receiving planets
	pthread_create(&thread_ID, NULL, recievePlanets, NULL);
//	Call gtk_main which handles basic GUI functionality
	gtk_main();
//	Let threads finish before exiting
	pthread_join(thread_ID,&status);
	printf("Exiting program\n");
	return 0;
}
//Draw event for cairo, will be triggered each time a draw event is executed
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data){
    do_drawing(cr); //Launch the actual draw method
    return FALSE; //Return something
}
//Do the drawing against the cairo surface area cr
static void do_drawing(cairo_t *cr){
//	Set rgb colors for planets
    double rgb_color_x = 0,rgb_color_y= 0,rgb_color_z= 0;
    pthread_mutex_lock(&dataChange_mutex);
//    Check if data exists
    if (data != NULL) {
//    	Check if other other threads want to use database
//        	flag added user of database
	        planet_type *nextPlanet = data;
//	        Check linked list if nextPlanet exists
        double radius_circle = nextPlanet->mass;
        while (nextPlanet != NULL) {
            if(nextPlanet->mass < 1e9) {
                radius_circle = nextPlanet->mass / (2e6);
                rgb_color_x = 255;
                rgb_color_y = 191;
                rgb_color_z = 0;
            }
            if(nextPlanet->mass < 1001) {
                radius_circle = nextPlanet->mass / (50);
                rgb_color_x = 150;
                rgb_color_y = 0;
                rgb_color_z = 0;
            }
            if(nextPlanet->mass > 1001 && nextPlanet->mass < 1e6) {
                radius_circle = nextPlanet->mass / (50);
                rgb_color_x = 0;
                rgb_color_y = 50;
                rgb_color_z = 50;
            }
//	        add planet position x-axis
            double pos_x = (nextPlanet)->sx;
//	        	add planet position y-axis
            double pos_y = (nextPlanet)->sy;
//		    set planet color
            cairo_set_source_rgb(cr, rgb_color_x, rgb_color_y, rgb_color_z);
	        //Create cairo shape: Parameters: Surface area, x pos, y pos, radius, Angle 1, Angle 2
            cairo_arc(cr, pos_x, pos_y, radius_circle, 0, draw_circle);
//          Fill color of planet
            cairo_fill(cr);
//          Update drawing for next planet
            nextPlanet = nextPlanet->next;
//	        reached end of list
        }
    }
    pthread_mutex_unlock(&dataChange_mutex);
}
//Draw graphical window
void Graphical_Interface(int argc, char *argv[]){
    //GUI stuff, don't touch unless you know what you are doing, or if you talked to me
    //Initialize GTK environment
    gtk_init(&argc, &argv);
    //Create a new window which will serve as your top layer
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //Create draw area, which will be used under top layer window
    darea = gtk_drawing_area_new();
    //add draw area to top layer window
    gtk_container_add(GTK_CONTAINER(window), darea);
    //Connect callback function for the draw event of darea
    g_signal_connect(G_OBJECT(darea), "draw",G_CALLBACK(on_draw_event), NULL);
    //Destroy event, not implemented yet, altough not needed
    g_signal_connect(window, "destroy",G_CALLBACK(gtk_main_quit), NULL);
    //Set position of window
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    //Set size of window
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    //Title
    gtk_window_set_title(GTK_WINDOW(window), "Basic space program");
    //Show window
    gtk_widget_show_all(window);
    //Add timer callback functionality for darea
    gtk_widget_add_tick_callback(darea, on_frame_tick, NULL, 1);
    //GUI stuff, don't touch unless you know what you are doing, or if you talked to me
//    gtk_main();//Call gtk_main which handles basic GUI functionality
}
//Iterate connections and addElement
void *recievePlanets(){
    /* Codes goes here */
}
//Receive planets from messageQueue
void *recieveConnections(){
    /* Code goes here */
}
//Handle physics for planets
void* planet_Physics(planet_type* planet) {
    /* Code goes here */
}
//Tick handler to update the frame
	GtkTickCallback on_frame_tick(GtkWidget *widget, GdkFrameClock *frame_clock, gpointer user_data) {
		gdk_frame_clock_begin_updating(frame_clock); //Update the frame clock
		gtk_widget_queue_draw(darea); //Queue a draw event
		gdk_frame_clock_end_updating(frame_clock); //Stop updating frame clock
	}
