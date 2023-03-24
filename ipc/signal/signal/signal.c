#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

//typedef void (*sighander_t)(int);
void fun1(int signum){
    printf("receive SIGKILL signum:%d\n",signum);
}

void fun2(int signum){
    printf("receive SIGQUIT signum:%d\n",signum);
}

int main(){
    void* ret = NULL;

    //Ctrl + C
    ret = signal(SIGINT, fun1);
    if(SIG_ERR == ret){
        perror("signal");
        return 1;
    }

    //Ctrl + "\"
    ret = signal(SIGQUIT, fun2);
    if(SIG_ERR == ret){
        perror("signal");
        return 1;
    }

    printf("输入回车退出程序！");
    getchar();
    
    return 0;
}
