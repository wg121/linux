#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
	int fd = -1,  newfd = -1;
	
	//同dup1
	fd = open("txt", O_WRONLY | O_CREAT, 0644);
	if(-1 == fd){
		perror("open");
		return 1;
	}
	printf("fd : %d\n",fd);

	//复制一个新的文件描述符
	//新的文件描述符是根据自己编写的文件描述符
	newfd = dup2(fd,100);
	if(-1 == newfd){
		perror("dup");
		return 1;
	}
	printf("newfd : %d\n",newfd);
	
	close(fd);
	close(newfd);
	return 0;
}
