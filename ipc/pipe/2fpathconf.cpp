#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

//使用 fpathconf 方法输出：
//管道的缓存区大小
//管道名字的最大值
int main(){
	long ret = -1;
	int fd[2];
	ret = pipe(fd);
	if(-1 == ret){
		perror("pipe");
		return 1;
	}

	ret = fpathconf(fd[0],_PC_PIPE_BUF);
	printf("pipe buf:%ld\n",ret);

	ret = fpathconf(fd[0],_PC_NAME_MAX);
	printf("pipe name max:%ld\n",ret);
	return 0;
}
