#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *head = NULL;

pthread_mutex_t mutex;
pthread_cond_t cond;

// 条件变量
// 利用条件变量和互斥锁模拟生产者消费者的问题

void *producer(void *arg)
{
    while (1)
    {
        Node *pnew = (Node *)malloc(sizeof(Node));

        pnew->data = rand() % 1000;
        pthread_mutex_lock(&mutex);

        pnew->next = head;
        head = pnew;

        printf("produce :%lu, %d\n", pthread_self(), pnew->data);

        pthread_mutex_unlock(&mutex);

        pthread_cond_signal(&cond);
        sleep(rand() % 3);
    }
    return NULL;
}

void *customer(void *arg)
{
    while (1)
    {

        pthread_mutex_lock(&mutex);
        if (NULL == head)
        {
            pthread_cond_wait(&cond, &mutex);
        }

        Node *tmp = head;
        head = tmp->next;
        printf("customer :%lu, %d\n", pthread_self(), tmp->data);
        free(tmp);

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    int ret = -1;
    pthread_t tid1 = 0, tid2 = 0;

    ret = pthread_mutex_init(&mutex, NULL);
    if (0 != ret)
    {
        printf("pthread_mutex_init failed...\n");
        return 1;
    }

    ret = pthread_create(&tid1, NULL, producer, NULL);
    if (0 != ret)
    {
        printf("pthread_ceate failed...\n");
        return 1;
    }
    ret = pthread_create(&tid2, NULL, customer, NULL);
    if (0 != ret)
    {
        printf("pthread_ceate failed...\n");
        return 1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
