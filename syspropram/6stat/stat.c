#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//stat(...)
int main(){
	struct stat buf;
	int ret = -1;
	
	//查看文件的某些属性
	ret = stat("Makefile", &buf);
	if(-1 == ret){
		perror("stat");
		return 1;
	}	

	//打印文件的编号和节点数
	printf("文件编号:%ld\n",buf.st_dev);
	printf("文件的节点数:%ld\n",buf.st_ino);
	//...还可以打印其他信息


	//文件的类型、权限	
	//文件的类型方式一：
	if((buf.st_mode & S_IFMT) == S_IFREG){
		printf("这是普通文件\n");
	}
	if((buf.st_mode & S_IFMT) == S_IFSOCK){
		printf("这是接口\n");
	}
	if((buf.st_mode & S_IFMT) == S_IFBLK){
		printf("这是块文件\n");
	}
	if((buf.st_mode & S_IFMT) == S_IFDIR){
		printf("目录\n");
	}
	//还有：管道，套接字。软连接
	
	//...方式二
	if(S_ISDIR(buf.st_mode)){
		printf("dir\n");
	}
	if(S_ISREG(buf.st_mode)){
		printf("这是普通文件\n");
	}
	if(S_ISSOCK(buf.st_mode)){
		printf("这是接口\n");
	}
	if(S_ISBLK(buf.st_mode)){
		printf("这是块文件\n");
	}
	//...
	

	//文件的权限
	//所有者：读、写、执行的权限
	if(buf.st_mode & S_IRUSR){
		printf("R");
	}
	if(buf.st_mode & S_IWUSR){
		printf("W");
	}
	if(buf.st_mode & S_IXUSR){
		printf("X");
	}

	printf("\n");
	return 0;
}
