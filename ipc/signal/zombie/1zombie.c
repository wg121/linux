#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid = -1;

    pid = fork();
    if(-1 == pid){
    	perror("fork");
	return 1;
    }
    
    if(0 == pid){
	    printf("this is child process\n");
    	exit(0);
    }
    else{
   	    //wait(NULL);
        waitpid(-1, NULL, 0); 
	    printf("this is father process\n");
    }


    return 0;
}
