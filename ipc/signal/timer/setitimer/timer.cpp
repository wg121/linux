#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/time.h>

//settimer
int main(){
    int ret = -1;

    struct itimerval newVal;
    newVal.it_interval.tv_sec = 3;
    newVal.it_interval.tv_usec = 0;

    newVal.it_value.tv_sec = 2;
    newVal.it_value.tv_usec = 0;

    ret = setitimer(ITIMER_REAL, &newVal, NULL);
    if(-1 == ret){
        perror("setitimer");
        return 1;
    }

    printf("puse continue...\n");
    getchar();
    return 0;
}
