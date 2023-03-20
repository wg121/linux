#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//同wait和waitpid
//test waitpid()
int main(){
	pid_t pid = -1;
    pid_t waitid = -1;
    int status = -1;

    pid = fork();
    if(0 > pid){
        perror("fork");
        return 1;
    }
    
    if(0 == pid){
        printf("child id %d\n",getpid());
        printf("i am child.my parent id is %d\n",getppid());
        exit(1);
    }
    else if(0 < pid){
        waitid = waitpid(pid, &status, 0);
        printf("i am father.my id is %d\n",getpid());
        printf("the status id is %d\n",status);
        printf("the waitid id is %d\n",waitid);
        sleep(1);
    }

	return 0;
}
