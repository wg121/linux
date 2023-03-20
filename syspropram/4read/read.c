#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//规定读取的最大字节数为：16个字节
const int MAXSIZE = 16;

int main(){
	int fd = -1;	
	int ret = -1;
	char buf[MAXSIZE];	
	
	//以只读的方式打开文件，来读取文件
	fd = open ("txt", O_RDONLY);
	if(-1 == fd){
		perror("open");
		return 1;
	}

	//单次读取文件
	/*
	memset(buf, 0, MAXSIZE);
	ret = read(fd, buf, MAXSIZE);
	if(-1 == ret){
		perror("read");
		return 1;
	}

	printf("the content is :%s\n",buf);
	*/


	//循环读取文件
	while(1){
		memset(buf, 0, MAXSIZE);
		ret = read(fd, buf, MAXSIZE);
		if(0 >= ret){
			perror("read");
			return 1;
		}
		printf("the content is:%s\n",buf);
	}

	close(fd);
	return 0;
}
