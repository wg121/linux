#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define SIZE 16
//使用无名管道进行父子间进程通信
int main(){
	int ret = -1;
	pid_t pid = -1;
	const char *buf = "hello pipe"; //子进程写的数据
	char buff[SIZE];		//父进程存储的缓存区
	int pipefd[2];

	//创建管道
	ret = pipe(pipefd);
	if(-1 == ret){
		perror("pipe");
		return 1;
	}

	//创建个进程
	pid = fork();
	if(-1 == pid){
		perror("fork");
		return 1;
	}
	//child process -- 子进程
	if(0 == pid){
		close(pipefd[0]);//close read pipe -- 关闭读管道
		ret = write(pipefd[1], buf, strlen(buf));
		if(-1 == ret){
			perror("write");
			return 1;
		}
		
		printf("write %d byte\n",ret);
		close(pipefd[1]);	//close write -- 关闭写管道
		exit(0);
	}
	//father process -- 父进程
	else{
		close(pipefd[1]);	//close write -- 关闭写管道
		memset(buff, 0, SIZE);
		ret = read(pipefd[0], buff, SIZE);
		if(-1 == ret){
			perror("read");
			return 1;
		}

		printf("readed:%s\n",buff);
		close(pipefd[0]);	//close read -- 关闭读管道
	}
	return 0;
}
