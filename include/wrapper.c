#include "wrapper.h"
#include "unistd.h"
#define MAX_SIZE_OF_MSG 1024
#define MAX_NUMBER_OF_MSG 10
#define QUEUE_PERMISSION 0600
int MQcreate (mqd_t * mq, char * name){
    //Construct attributes struct
    struct mq_attr att;
    att.mq_msgsize = MAX_SIZE_OF_MSG;
    att.mq_maxmsg = MAX_NUMBER_OF_MSG;

    /* Creates a mailbox with the specified name.*/
    mqd_t queue = mq_open(name, O_CREAT | O_NONBLOCK , QUEUE_PERMISSION, &att);
    if(queue == -1){
        perror("MQcreate");
        return 0;
    }
    *mq = queue;
    return 1;
}
int MQconnect (mqd_t * mq, char * name, int noblock){
    /* Connect to mailbox with specified name */
    mqd_t queue;
    if(noblock){
        queue = mq_open(name, O_RDWR | O_NONBLOCK);
    }else{
        queue = mq_open(name, O_RDWR);
    }
   if(queue ==(mqd_t) -1) {
       perror("MQconnect");
       return 0;
    }
    *mq = queue;
    return 1;
}
int MQread (mqd_t * mq, void ** refBuffer){
    /*Read from mailbox*/
    int bytes = (int)mq_receive(*mq,(char *)refBuffer, MAX_SIZE_OF_MSG, 0);
    if(bytes ==(mqd_t) -1){
        return 0;
    }
    return bytes;
}
int MQwrite (mqd_t * mq, void * sendBuffer){
    /* Write message from mailbox*/
    planet_type* dataPack = sendBuffer;
    int bytes =mq_send(*mq, (const char *)(dataPack), sizeof(*dataPack),0);
    if(bytes == -1){
        perror("MQwrite");
        return 0;
    }
    return sizeof(*dataPack);
}
int MQclose(mqd_t * mq, char * name){
    /*Close mailbox*/
    if (mq_close(*mq) == 0) {
//        mq_unlink(name);
        return 1;
    }
    perror("MQclose");
    return 0;
}


