#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//同wait函数
int main(){
    pid_t pid = -1;
    int ret = -1;

    pid = fork();
    if(-1 == pid){
    	perror("fork");
	return 1;
    }
    
    if(0 == pid){
    	sleep(3);
	printf("the chile process die...\n");
	exit(0);
    }
    else{
    	ret = waitpid(-1, NULL, 0);
	if(-1 == ret){
		perror("waitpid");
		return 1;	
	}

	if(pid == ret){
		printf("the father process recyle the chile process\n");
	}
    }
    
    return 0;
}
