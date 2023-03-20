#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//验证父子进程对：读时共享、写时拷贝的验证
int main(){
    pid_t pid = -1;
    int a = 10;

    pid = fork();
    if(-1 == pid){
    	perror("fork");
	return 1;
    }
    
    if(0 == pid){
	    printf("this is child process a = %d\n",++a);
    	exit(0);
    }
    else{
   	    wait(NULL); 
	    printf("this is father process a = %d\n",++a);
    }


    return 0;
}
