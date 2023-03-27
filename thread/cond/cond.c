#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

//条件变量
//利用条件变量每3秒钟，让线程2跑一次
int flag = 0;

void *fun1(void *arg){
    while(1){
		//加锁
		pthread_mutex_lock(&mutex);
		flag = 1;
		//解锁
		pthread_mutex_unlock(&mutex);
		//发送信号
		pthread_cond_signal(&cond);
		printf("fun1 end...\n");
		sleep(3);
	}
    return NULL;
}

void *fun2(void *arg){
    while(1){
		//加锁
		pthread_mutex_lock(&mutex);
		
		if(0 == flag){
			pthread_cond_wait(&cond, &mutex);

		}
		
		printf("fun2 start doing\n");
		flag = 0;
		//解锁
		pthread_mutex_unlock(&mutex);
	}
    return NULL;
}

int main(){
    int ret = -1;
    pthread_t tid1 = 0, tid2 = 0;

    ret = pthread_mutex_init(&mutex, NULL);
    if(0 != ret){
        printf("pthread_mutex_init failed...\n");
        return 1;
    }
	
	ret = pthread_cond_init(&cond, NULL);
	if(0 != ret){
		printf("pthread_cond_init failed...\n");
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

    pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

    return 0;
}
