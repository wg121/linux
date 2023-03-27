#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

//线程的资源回收
//
void *fun1(void *arg){
    printf("child thread doing...\n");
    sleep(3);
    return (void *)0xa;
}

int main(){
    int ret = -1;
    pthread_t tid1 = 0;

    ret = pthread_create(&tid1, NULL, fun1, NULL);
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }

    void *retval = NULL;
    ret = pthread_join(tid1, &retval);
    if(0 != ret){
        printf("pthread_join failed...\n");
        return 1;
    }
    printf("retval:%d\n", (int)(long)retval);
    
    return 0;
}
