#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t sem;

void *fun1(void *arg){
    sem_wait(&sem);
    for (char i = 'A'; i < 'Z'; i++)
    {
        putchar(i);
        fflush(stdout);
        usleep(100000);
    }
    putchar('\n');
    fflush(stdout);
    sem_post(&sem);
    return NULL;
}

void *fun2(void *arg){
    sem_wait(&sem);
    for (char i = 'a'; i < 'z'; i++)
    {
        putchar(i);
        fflush(stdout);
        usleep(100000);
    }
    putchar('\n');
    fflush(stdout);
    sem_post(&sem);
    return NULL;
}

int main(){
    int ret = -1;
    pthread_t tid1 = 0, tid2 = 0;

    ret = sem_init(&sem, 0, 1);
    if(0 != ret){
        printf("sen_init failed...\n");
        return 1;
    }

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

    sem_destroy(&sem);

    return 0;
}
