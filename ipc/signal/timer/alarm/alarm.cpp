#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

//alarm
int main(){
    unsigned int sec = 100;
    alarm(sec);

    sleep(2);
    sec = alarm(0);

    printf("sec:%d\n",sec);
    return 0;
}
