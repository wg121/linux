#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
//创建一个子进程，
//父进程给子进程发送 15 号信号，杀死子进程
int main(){
    int ret = -1;
    pid_t pid = -1;

    pid = fork();
    if(-1 == pid){
        perror("fork");
        return 1;
    }

    if(0 == pid){
        while (1)
        {
            sleep(1);
            printf("child process...\n");
        }
    }
    else
    {
        sleep(3);
        kill(pid, SIGTERM);
    }

    return 0;
}
