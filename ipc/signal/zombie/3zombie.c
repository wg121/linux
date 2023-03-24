#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    pid_t pid = -1;

    signal(SIGCHLD, SIG_IGN);

    pid = fork();
    if(-1 == pid){
    	perror("fork");
	return 1;
    }
    
    if(0 == pid){
	    printf("this is child process\n");
        sleep(3);
    	exit(0);
    }
    else{
        while (1)
        {
            printf("this is father process\n");
            sleep(2);
        }
        
	    
    }

    return 0;
}
