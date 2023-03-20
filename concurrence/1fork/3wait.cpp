#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//父进程使用wait函数阻塞进程，
//等待子进程运行完毕，后回收子进程的资源
int main(){
    pid_t pid = -1;
    pid_t waitid = -1;
    int status = -1;

    //创建一个进程
    pid = fork();
    if(0 > pid){
        perror("fork");
        return 1;
    }
    
    //子进程
    if(0 == pid){
        printf("child id %d\n",getpid());
        printf("i am child.my parent id is %d\n",getppid());
        exit(1);
    }

    //父进程
    else if(0 < pid){
        waitid = wait(&status);		//等待子进程运行结束
        printf("i am father.my id is %d\n",getpid());	//父进程的进程号
        printf("the status id is %d\n",status);		//子进程退出时的状态：1
        printf("the waitid id is %d\n",waitid);		//返回子进程的id,成功的话
        sleep(1);
    }

    return 0;
}
