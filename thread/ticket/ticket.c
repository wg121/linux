#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

int ticketNum = 200;

void *fun1(void *arg){
    while (ticketNum > 0)
    {
        printf("one buy ticket.have : %d tickets\n",ticketNum);
        ticketNum--;
    }
    
    return NULL;
}

void *fun2(void *arg){
    while (ticketNum > 0)
    {
        printf("two buy ticket.have : %d tickets\n",ticketNum);
        ticketNum--;
    }
    return NULL;
}

int main(){
    int ret = -1;
    pthread_t tid1 = 0, tid2 = 0;

    ret = pthread_create(&tid1, NULL, fun1, NULL);
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }
    ret = pthread_create(&tid2, NULL, fun2, NULL);
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
