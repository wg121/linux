#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

//创建两个线程A B 
//一个打印小写字母
//一个打印大写字母

//打印小写字母
void *fun1(void *arg){
    for (char i = 'a'; i < 'z'; i++)
    {
        putchar(i);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
    return NULL;
}

//打印大写字母
void *fun2(void *arg){
    for (char i = 'A'; i < 'Z'; i++)
    {
        putchar(i);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
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
