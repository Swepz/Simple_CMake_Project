#include "main.h"
#include "linkedList/linkedList.c"
#include "wrapper/wrapper.c"

int main(){
    printf("Math Working: sqrt(5)=%f\n", sqrt(5));
    printf("Hello from main\n");
    helloFromWrapper();
    helloFromLinkedList();
    return 0;
}
