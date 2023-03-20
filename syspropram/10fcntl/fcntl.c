#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

//利用 fcntl 方法模仿dup.. 复制文件描述符
int main(){
	int fd = -1;
	int newfd = -1;
	//
	fd = open("txt", O_WRONLY | O_CREAT, 0644);
	if(-1 == fd){
		perror("open");
		return 1;
	}
	printf("fd : %d\n",fd);
	
	//newfd = fcntl(fd,F_DUPFD);
	newfd = fcntl(fd,F_DUPFD, 100);
	//newfd = fcntl(fd,F_GETFD);
	if(-1 == newfd){
		perror("fcntl");
		return 1;
	}
	printf("newfd : %d\n",newfd);
	
	close(fd);
	close(newfd);
	return 0;
}
