#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>

//获取进程所属的会话ID
int main(){
	pid_t pid = -1;

	pid = getsid(getpid());
	printf("getsid:%d\n",pid);

    return 0;
}
