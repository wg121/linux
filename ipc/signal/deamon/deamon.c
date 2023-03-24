#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

//守护进程的实现
int main(){
	pid_t pid = -1;
    int ret = -1;
    //int count = 0;
    
	//1.创建子线程，父线程退出
    pid = fork();
    if(-1 == pid){
        perror("fork");
        return 1;
    }

    if(pid > 0){
        printf("father exit...\n");
        exit(0);
    }
	//2.子线程创建新的对话
	pid = setsid();
    if(pid == -1){
        perror("setsid");
        return 1;
    }
    //3.改变当前的路径为根目录
	ret = chdir("/");
    if(-1 == ret){
        perror("chdir");
        return 1;
    }
    //4.重新设置文件掩码
	umask(0);//this fun is always success.
    //5.关闭文件描述符
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
	//6.开始执行守护进程的核心工作
    int count = 0;
	while (1)
    {
        //printf("this is deamon %d\n",count++);//无法打印，因为无法控制终端
        system("date >> /home/wmt/code/linux_c++/ipc/signal/deamon/txt.log");
        sleep(2);
    }
    
    return 0;
}
