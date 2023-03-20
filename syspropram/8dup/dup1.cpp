#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

//复制文件描述符的两种方式
int main(){
	int fd = -1, newfd = -1;
	
	//以只写的方式打开文件，文件不存在就创建文件
	fd = open("txt", O_WRONLY | O_CREAT, 0644);
	if(-1 == fd){
		perror("open");
		return 1;
	}
	printf("fd : %d\n",fd);

	//根据旧的文件描述符，复制一个新的文件描述符
	//新的文件描述符是：可使用的最小的编号的文件描述符
	newfd = dup(fd);
	if(-1 == newfd){
		perror("dup");
		return 1;
	}
	printf("newfd : %d\n",newfd);
	
	close(fd);
	close(newfd);
	return 0;
}
