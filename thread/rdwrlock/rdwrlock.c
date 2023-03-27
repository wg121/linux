#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

//创建是个线程
//3个是写
//7个是读
const int SIZE = 10;
pthread_rwlock_t rwlock;

//读、写数字num
int num = 2;

void *funR(void *arg){
    pthread_rwlock_rdlock(&rwlock);

    printf("read num : %d\n",num);

    pthread_rwlock_unlock(&rwlock);
    return NULL;
}

void *funW(void *arg){
    pthread_rwlock_wrlock(&rwlock);

    printf("write num : %d\n",++num);

    pthread_rwlock_unlock(&rwlock);
    return NULL;
}

//现成的创建
int main(){
    int ret = -1;
    pthread_t tid[10];
//初始化读写锁
    ret = pthread_rwlock_init(&rwlock, NULL);
    if(0 != ret){
        printf("thread_utex_init failed...\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if(i < 3){
            ret = pthread_create(&tid[i], NULL, funW, NULL);
            if(0 != ret){
            printf("pthread_ceate failed...\n");
            return 1;
            }
        }
        else{
            ret = pthread_create(&tid[i], NULL, funR, NULL);
            if(0 != ret){
            printf("pthread_ceate failed...\n");
            return 1;
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        pthread_join(tid[i], NULL);
    }

    //销毁读写锁
    pthread_rwlock_destroy(&rwlock);

    return 0;
}
