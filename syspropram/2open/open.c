#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//open() 函数的测试，以五种方式打开文件
int main(){
	int fd = -1;

	//以只读的方式打开一个文件
	//fd = open("txt", O_RDONLY);
	
	//以只写的方式，打开一个文件，如果文件不存在就创建一个文件，创建的文件权限为：0644
	//fd = open ("txt", O_WRONLY | O_CREAT, 0644);
	
	//以只写的方式，打开一个文件，如果文件不存在就创建一个文件，创建的文件权限为：0644
	//O_CREAT 和 O_EXCL 同时存在，若文件存在就报错
	//fd = open("txt", O_WRONLY | O_CREAT | O_EXCL, 0644); 
	
	//以只写的方式打开文件，如果文件存在，就清空文件
	//fd = open("txt", O_WRONLY | O_TRUNC);

	//以只写的方式，打开一个文件，以追加的方式对文件进行追加
	fd = open("txt", O_WRONLY | O_APPEND);
	if(-1 == fd){
		printf("errno:%d\n",errno);
		printf("open:%s\n",strerror(errno));
		perror("open");
		printf("\n");
		return 1;
	}
	
	//打印文件描述符号
	printf("fd:%d\n",fd);

	//关闭文件
	close(fd);
	return 0;
}
