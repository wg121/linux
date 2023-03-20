#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//验证变量放在fork前后，是否会公用数据
//答案是：不会
int main(){
    pid_t pid = -1;
    //int a = 10;

    pid = fork();
    int a = 10;
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
