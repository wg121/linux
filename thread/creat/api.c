#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

//线程相关的一些api
int main(){
    int ret = -1;
    pthread_t tid = 0;

    //获取当前线程id
    tid = pthread_self();
    printf("self:%lu\n",tid); 
    
    //判断两个线程送否相等
    //相等返回非0，不相等返回0
    ret = pthread_equal(tid, pthread_self());
    if(0 != ret){
        printf("equal...\n");
    }
    else{
        printf("not equal...\n");
    }
    return 0;
}
