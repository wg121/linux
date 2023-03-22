#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>


#define SIZE 16
//使用无名管道进行父子间进程通信
int main(){
	int ret = -1;
	pid_t waitid = -1;
	int status = -1;
	pid_t pid = -1;
	const char *buf = "hello pipe";
	char buff[SIZE];
	int pipefd[2];


//此处创建管道，可以保证正常的通信
//创建管道
	ret = pipe(pipefd);
	if(-1 == ret){
		perror("pipe");
		return 1;
	}

//创建进程
	pid = fork();
	if(-1 == pid){
		perror("fork");
		return 1;
	}

/*	此处创建管道，会造成写时出现问题  
//创建管道
	ret = pipe(pipefd);
	if(-1 == ret){
		perror("pipe");
		return 1;
	}
*/


//子进程
	if(0 == pid){
	//child process
		close(pipefd[0]);
		ret = write(pipefd[1], buf, strlen(buf));
		if(-1 == ret){
			perror("write");
			return 1;
		}
		
		printf("write %d byte\n",ret);

		close(pipefd[1]);
		exit(0);
	}
//father process
	else{
		close(pipefd[1]);
		waitid = wait(&status);
		if(-1 == waitid){
			perror("wait");
			return 1;
		}
		printf("status:%d\n",status);
		memset(buff, 0, SIZE);
		ret = read(pipefd[0], buff, SIZE);
		if(-1 == ret){
			perror("read");
			return 1;
		}
		printf("readed:%s\n",buff);
		close(pipefd[0]);
	}
	return 0;
}
