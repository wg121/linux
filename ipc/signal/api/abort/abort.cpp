#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//发送一个信号杀死自己 等价于 raise(SIGTERM) == abort()
int main(){
    int i = 0;
    while (1)
    {
        sleep(1);
        printf("process doing...%d\n", i);
        i++;
        if(4 == i){
            abort();
        }
    }
    
    return 0;
}
