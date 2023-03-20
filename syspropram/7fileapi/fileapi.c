#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//checkout about file api
//文件相关的api
int main(){
	int ret = -1;
	
	//access ，检测文件的是否存在
	ret = access("Makefile",R_OK);
	if(-1 == ret){
		printf("Makefile has not R 权限\n");
	}
	else if(0 == ret){
		printf("Makefile has R 权限\n");
	}
	
	//chmod 修改文件权限
	ret = chmod("Makefile", 0744);
	if(-1 == ret){
		printf("chmod fail\n");
	}
	else if(0 == ret){
		printf("chmod success Makefile 权限为0744 \n");
	}

	//truncate

	//link

	//symlink

	//其他文件的权限类似，就不编写了


	return 0;
}
