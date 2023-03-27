#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

/* 加锁后双线程打印大、小写字母
 * */

//
pthread_mutex_t mutex;

void *fun1(void *arg){
	//加锁
    pthread_mutex_lock(&mutex);
    for (char i = 'a'; i < 'z'; i++)
    {
        putchar(i);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *fun2(void *arg){
    pthread_mutex_lock(&mutex);
    for (char i = 'A'; i < 'Z'; i++)
    {
        putchar(i);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

//现成的创建
int main(){
    int ret = -1;
    pthread_t tid1 = 0, tid2 = 0;

    ret = pthread_mutex_init(&mutex, NULL);
    if(0 != ret){
        printf("thread_utex_init failed...\n");
        return 1;
    }

    //无参的子线程创建，调用
    ret = pthread_create(&tid1, NULL, fun1, NULL);
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }
   
    //有参的子线程创建调用
    ret = pthread_create(&tid2, NULL, fun2, NULL);
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    pthread_mutex_destroy(&mutex);

    printf("the process end...\n");

    return 0;
}
