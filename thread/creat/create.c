#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

void *fun1(void *arg){
    printf("child pthread...\n");
    return NULL;
}

void *fun2(void *arg){
    int i = (int)(long)arg;
    
    printf("child pthread arg:%d\n",i);
    
    return NULL;
}

void *fun3(void *arg){
    int *i = ((int *)arg);
    
    printf("child pthread arg:%d\n", *i);
    
    return NULL;
}

//现成的创建
int main(){
    int ret = -1;
    pthread_t tid = 0;

    //无参的子线程创建，调用
    /*
    ret = pthread_create(&tid, NULL, fun1, NULL);
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }
    */
   
    //有参的子线程创建调用
    //ret = pthread_create(&tid, NULL, fun2, (void *)0xA);
    
    int *p = NULL, value = 0XF;
    p = &value;
    ret = pthread_create(&tid, NULL, fun3, (void *)p);//
    if(0 != ret){
        printf("pthread_ceate failed...\n");
        return 1;
    }
    getchar();

    return 0;
}
