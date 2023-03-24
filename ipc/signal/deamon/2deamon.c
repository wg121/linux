#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define SIZE 128

//守护进程的实现
//打印：年月日时分秒输出到当前目录下的	data.log
int main(){
	pid_t pid = -1;
    int ret = -1;
    char buf[SIZE];
    time_t t = -1;
    struct tm *PT = NULL;

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
	while (1)
    {
        t = time(NULL);//get time
        if(-1 == t){
            perror("time");
            return 1;
        }

        PT = localtime(&t);
        if(NULL == PT){
            printf("localtime failed...\n");
            return 1;
        }
        memset(buf, 0, SIZE);
        sprintf(buf, "%s %d %d %d-%d:%d:%d","echo",PT->tm_year + 1900,PT->tm_mon + 1,
            PT->tm_mday, PT->tm_hour,PT->tm_min, PT->tm_sec);
        //printf("%s")
        strcat(buf, " >> /home/wmt/code/linux_c++/ipc/signal/deamon/data.log");
        //system("buf >> /home/wmt/code/linux_c++/ipc/signal/deamon/data.log");
        system(buf);
        sleep(2);
    }
    
    return 0;
}
