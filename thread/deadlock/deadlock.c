#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>

//申请两个锁的资源
pthread_mutex_t mutex1, mutex2;

void *fun1(void *arg){

	//加锁1 和 锁2
    pthread_mutex_lock(&mutex1);
    printf("one doing...\n");
    pthread_mutex_lock(&mutex2);
    
    printf("one doing...\n");
    
	//解锁1 和 锁2
    pthread_mutex_unlock(&mutex1);
    printf("one doing...\n");
    pthread_mutex_unlock(&mutex2);
    return NULL;
}

void *fun2(void *arg){

    pthread_mutex_lock(&mutex2);
    printf("two doing...\n");
    pthread_mutex_lock(&mutex1);

    printf("two doing...\n");
    
    pthread_mutex_unlock(&mutex2);
    printf("two doing...\n");
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main(){
    int ret = -1;
    pthread_t tid1 = 0, tid2 = 0;

	//初始化 锁1 和 锁2
    ret = pthread_mutex_init(&mutex1, NULL);
    if(0 != ret){
        printf("pthread_mutex_init failed...\n");
        return 1;
    }
    ret = pthread_mutex_init(&mutex2, NULL);
    if(0 != ret){
        printf("pthread_mutex_init failed...\n");
        return 1;
    }

	//创建 线程1 和 线程2
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

	//回收线程资源 1 2 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

	//销毁 锁1 2
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}
