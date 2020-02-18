#include "wrapper.h"
#include <unistd.h>
#define SERVERCONNECTMQ "/serverconnectionMQlab3"
//Buffer for names
char name[30];
char receiveMQ_Name[30];
char sendMQ_Name[30];
mqd_t serverConnect, sendPlanetMQ, recieveMessageMQ;
pthread_t recieveThread;
int createPlanet(char *name,double mass,
                 double pos_x, double pos_y,double vel_x,double vel_y,int life);
int SetupMQ();
void* recieveMessages();
void terminalInterface();

void terminalInterface(){
	double mass, pos_x, pos_y, vel_x, vel_y;
	char name[20];
	int life;
	while (getchar() != '\n');
	printf("Add planet name:\n");
	fgets(name, 20, stdin);
	printf("Add planet mass:\n"); scanf("%lf",&mass);
	printf("Add planet position x-axis (0-800):\n");scanf("%lf", &pos_x);
	printf("Add planet position y-axis (0-600):\n");scanf("%lf", &pos_y);
	printf("Add planet velocity x-axis:\n");scanf("%lf", &vel_x);
	printf("Add planet velocity y-axis:\n");scanf("%lf", &vel_y);
	printf("Add life to planet:\n"); scanf("%d", &life);
	createPlanet(name, mass, pos_x, pos_y, vel_x, vel_y, life);
//	getchar();
}
pthread_t recieveThread;

//Setup the Message queues and make connections with server
int main(){
	int input =0;
	SetupMQ();
	pthread_create(&recieveThread, NULL, recieveMessages, NULL);
	createPlanet("Planet1", 1e8, 300, 300, 0, 0, 1000);
	createPlanet("Planet2", 1000, 200, 300, 0, 0.008, 10000);
//	createPlanet("Planet3", 1505, 250, 300, 0, .008, 20);

	while (1) {
		printf("Add planet press [1]:\n");
		printf("Exit program press [2]:\n");
		scanf("%d", &input);
		switch (input) {
			case 1:
				terminalInterface();
				break;
			case 2:
				mq_unlink(receiveMQ_Name);
				mq_unlink(sendMQ_Name);
//				stop = 1;
				return 0;
			default:
				printf("Invalid option");
		}
	}
	pthread_exit(NULL);
}

int SetupMQ(){
    /* Codes goes here */
}
// check new messages every 5 seconds
void* recieveMessages(){
    while(1) {
        char* message = malloc(sizeof(char)*30);

        MQread(&recieveMessageMQ,(void**)message);
        printf("%s\n",message);
        sleep(5);
    }
}
// CreatePlanet with values
int createPlanet(char *name,double mass,
                 double pos_x, double pos_y,double vel_x,double vel_y,int life){
    /* Code goes here */

    // End of function
	MQwrite(&sendPlanetMQ,&current_planet);
	printf("SendPlanet\n");
}
