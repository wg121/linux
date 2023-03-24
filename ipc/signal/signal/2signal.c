#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

//定时器触发信号，以定时三秒，每隔两秒定时启动定时器，定时器定时结束，发送信号SIGALRM

//typedef void (*sighander_t)(int);
void fun(int signum){
    printf("receive SIGALRM signum:%d\n",signum);
}

int main(){
    void* ret = NULL;
    int ret2 = -1;
    struct itimerval newVal;
    newVal.it_interval.tv_sec = 3;
    newVal.it_interval.tv_usec = 0;

    newVal.it_value.tv_sec = 2;
    newVal.it_value.tv_usec = 0;

    //timer
    ret = signal(SIGALRM, fun);
    if(SIG_ERR == ret){
        perror("signal");
        return 1;
    }

    ret2 = setitimer(ITIMER_REAL, &newVal, NULL);
    if(-1 == ret2){
        perror("setitimer");
        return 1;
    }

    printf("输入回车退出程序！");
    getchar();
    return 0;
}
