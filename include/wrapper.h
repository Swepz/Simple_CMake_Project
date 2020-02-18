#ifndef WRAPPER_H
#define WRAPPER_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>
#include <pthread.h>



// Mailslot handling:
extern int MQcreate (mqd_t * mq, char * name);
extern int MQconnect (mqd_t * mq, char * name, int nonblock);
extern int MQread (mqd_t * mq, void ** refBuffer);
extern int MQwrite (mqd_t * mq, void * data);
int MQclose(mqd_t * mq, char * name);


// Struct for planet data will be used in lab 2 and 3 !!!!!
// Just ignore in lab1 or you can try to send it on your mailslot, 
// will be done in lab 2 and 3

typedef struct pt {
	char		name[20];	// Name of planet
	double		sx;			// X-axis position
	double		sy;			// Y-axis position
	double		vx;			// X-axis velocity
	double		vy;			// Y-axis velocity
	double		mass;		// Planet mass
	struct pt*	next;		// Pointer to next planet in linked list
	struct pt*  previous;   // Pointer to previous planet in linked list
	int			life;		// Planet life
	int			pid;	// String containing ID of creating process
} planet_type;

#endif /* WRAPPER_H */
