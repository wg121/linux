#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

//创建以的进程
//会显示出打印三次 hello
int main(){
    pid_t pid = -1;

    printf("hello concurrence\n");
    
    pid = fork();

    printf("hello concurrence\n");
    
    return 0;
}
