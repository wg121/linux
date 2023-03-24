#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void fun(int signum){
    pid_t pid = -1;
    //any child process 
    //not block
    while ((pid = waitpid(-1, NULL, WNOHANG)) > 0)
    {
        printf("the child process is die...\n");
        printf("receive SIGSTOP signum:%d\n",signum);
    }
}

int main(){
    pid_t pid = -1;
    int ret = -1;
    struct sigaction sig;
    sig.sa_handler = fun;
    sig.sa_flags = 0;

    ret = sigaction(SIGCHLD, &sig, NULL);
    if(-1 == ret){
        perror("sigaction");
        return 1;
    }

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
