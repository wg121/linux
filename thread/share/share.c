#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

/* 验证 全局变量 在同一进程不要线程间是数据共享的
 * */

int count = 0;

void *fun1(void *arg){
    printf("child pthread count:%d\n",++count);
    return NULL;
}

void *fun2(void *arg){
    printf("child pthread count:%d\n",++count);
    return NULL;
}

//现成的创建
int main(){
    int ret = -1;
    pthread_t tid1 = 0, tid2 = 0;

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
    getchar();

    return 0;
}
