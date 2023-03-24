#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <signal.h>
#include <unistd.h>

void fun(int signum){
    printf("receive sig:%d\n",signum);
}

int main(){
    int ret = -1;
    struct sigaction sig;
    sig.sa_flags = 0;
    sig.sa_handler = fun;

    ret = sigaction(SIGINT, &sig, NULL);
    if(-1 == ret){
        perror("sigaction");
        return 1;
    }

    getchar();
    return 0;
}
