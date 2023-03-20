#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//exec	函数族中的execl和execlp函数的测试
//再linux写使用：ls -l /home
int main(){
	int ret = -1;

	//ret = execl("/bin/ls","ls","-l","/home/wmt/code",NULL);
	ret = execlp("ls", "ls", "-l", "/home", NULL);
	if(-1 == ret){
		perror("execl");
		return 1;
	}

	
	return 0;
}
