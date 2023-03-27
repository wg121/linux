#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *head = NULL;

sem_t sem_produce, sem_custom;

void *producer(void *arg){
    Node *pnew = NULL;
    while (1)
    {
        sem_wait(&sem_produce);
        
        pnew = (Node *)malloc(sizeof(Node));
        if(NULL == pnew){
            printf("malloc failed...\n");
            return NULL;
        }
        memset(pnew, 0, sizeof(Node));

        pnew->data = rand() % 1000;
        pnew->next = NULL;
        printf("produce : %d\n", pnew->data);

        pnew->next = head;
        head = pnew;

        sem_post(&sem_custom);
        sleep(rand() % 3);
    }
    return NULL;
}

void *customer(void *arg){
    Node *tmp = NULL;

    while(1){
        sem_wait(&sem_custom);

        tmp = head;
        head = tmp->next;
        printf("customer : %d\n", tmp->data);
        free(tmp);

        sem_post(&sem_produce);
        sleep(rand() % 2);
    }
    
    return NULL;
}

int main(){
    int ret = -1;
    pthread_t tid1 = 0, tid2 = 0;

    srandom(getpid());

    ret = sem_init(&sem_produce, 0, 5);
    if(0 != ret){
        printf("sen_init failed...\n");
        return 1;
    }
    ret = sem_init(&sem_custom, 0, 0);
    if(0 != ret){
        printf("sen_init failed...\n");
        return 1;
    }

    ret = pthread_create(&tid1, NULL, producer, NULL);
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }
    ret = pthread_create(&tid2, NULL, customer, NULL);
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&sem_produce);
    sem_destroy(&sem_custom);

    return 0;
}
