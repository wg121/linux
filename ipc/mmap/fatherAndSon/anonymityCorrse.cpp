#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SIZE 128

//父子进程间使用匿名mmap通信
int main(){
    int ret = -1;
    pid_t pid = -1;
    int fd = -1;
    void *addr = NULL;
    char buf[SIZE];

//2. mmap -- 使用匿名的内存映射出文件，虚拟的文件 ，
//  注意的是：MAP_ANONYMOUS 和 fd = -1
//  可以实现匿名的内存映射

    addr = mmap(NULL, 1024, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if(addr == MAP_FAILED){
        perror("mmap");
        return 1;
    }
    printf("mmap success\n");
    printf("addr:%s\n",(char *)addr);


    pid = fork();
    if(-1 == pid){
        perror("fork");
        return 1;
    }

//child
    if(0 == pid){
        int i = 0;
        while(1){
            memset(buf, 0, SIZE);
            sprintf(buf, "mmap ANONYMOUS %d\n",i++);
            memcpy(addr, buf, 1024);
            sleep(1);
        }
    }
//father
    else{
        while (1)
        {
            sleep(1);
            printf("father read:%s\n",(char *)addr);
        }
    }

    munmap(addr, 1024);
    return 0;
}
