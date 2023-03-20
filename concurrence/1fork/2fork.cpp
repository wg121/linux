#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

//创建一个子进程
//父子进程打印不同的信息
int main(){
    pid_t pid = -1;

    pid = fork();
    if(0 > pid){
        perror("fork");
        return 1;
    }
    
    if(0 == pid){
        printf("child id %d\n",getpid());
        printf("i am child.my parent id is %d\n",getppid());
        exit(1);
    }
    else if(0 < pid){
        for(int i = 0; i < 10; ++i){
            printf("i am father.my id is %d\n",getpid());
            sleep(1);
        }
    }

    return 0;
}
