#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

const int SIZE = 20;

//先先输入，在使用lseek 偏移文件指针的位置到开头
//再写入数据。
//相当于写入数据，再覆盖。
int main(){
	int fd = -1;		//文件描述符
	int ret = -1;		//返回值
	off_t off = -1;		//偏移量
	char buf[SIZE]; 	//申请的数组

	//打开文件,以只读的方式打开文件，如果文件不存在就创建文件，权限为0644
	//打开文件失败则返回-1，输出错误信息，并返回错误。
	fd = open("txt", O_WRONLY | O_CREAT, 0644);
	if(-1 == fd){
		perror("open");
		return 1;
	}
	
	//清空数组，清空，拷贝赋值 
	memset(buf, 0, strlen(buf));
	strcpy(buf, "the new massage!");
	ret = write(fd, buf, strlen(buf));
	if(-1 == ret){
		perror("write");
		return 1;
	}

	//偏移文件的偏移量，文件到开头
	off = lseek(fd, 0, SEEK_SET);
	if(-1 == off){
		perror("lseek");
	}
	
	//重新写数据，从文件起始位置开始写数据
	memset(buf, 0, strlen(buf));
	strcpy(buf, "the lseek project!");
	ret = write(fd, buf, strlen(buf));
	if(-1 == ret){
		perror("write");
		return 1;
	}
	
	//关闭文件
	close(fd);
	return 0;
}
