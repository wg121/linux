#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

//detach后不能打印信息，因为已经脱离了终端
//线程分离
//方式一:pthread_detach()
//方式二：在 pthread_create() 的第二个参数，设置为 分离模式
void *fun1(void *arg){
    int count = 3;
    while (count--)
    {
        sleep(1);
        printf("child thread doing %d\n",count);
    }
    printf("child thread die...\n");
    return NULL;
}

int main(){
    int ret = -1;
    pthread_t tid1 = 0;	

	pthread_attr_t attr;
	ret = pthread_attr_init(&attr);
	
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	ret = pthread_create(&tid1, &attr, fun1, NULL);


    //ret = pthread_create(&tid1, NULL, fun1, NULL);
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }

	pthread_attr_destroy(&attr);

    // ret = pthread_detach(tid1);
    // if(0 != ret){
    //     printf("pthread_detach failed..\n");
    //     return 1;
    // }

	//需要等待 线程 结束，进程才能结束
    getchar();

// detach后的线程，不能再别join会报错
    // ret = pthread_join(tid1, NULL);
    // if(0 != ret){
    //     printf("pthread_join failed...\n");
    //     return 1;
    // }

    return 0;
}
