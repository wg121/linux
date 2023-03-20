#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//
int main(){
	int fd = -1;
	
	//打印文件描述符值
	printf("fileno(stdin):%d\n",fileno(stdin));
	printf("fileno(stdout):%d\n",fileno(stdout));
	printf("fileno(stderr):%d\n",fileno(stderr));

	//以只读的方式打开文件，文件不存在返回-1
	fd = open("txt", O_RDONLY);
	if(-1 == fd){
		//以不同的方式根据错去码打印错误信息
		printf("errno:%d\n",errno);
		printf("open: %s\n",strerror(errno));
		perror("open");
		printf("\n");
		return 1;
	}

	//关闭文件
	close(fd);
	return 0;
}
