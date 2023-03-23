#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SIZE 128
//进程间使用mmap通信
int main(){
    int ret = -1;
    pid_t pid = -1;
    int fd = -1;
    void *addr = NULL;
    char buf[128];

//1.open txt
    fd = open("txt", O_RDWR);
    if(-1 == fd){
        perror("open");
        return 1;
    }
//2. mmap
    addr = mmap(NULL, 1024, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if(addr == MAP_FAILED){
        perror("mmap");
        return 1;
    }
    printf("mmap success\n");
    printf("addr:%s\n",(char *)addr);
//3.close
    close(fd);
    printf("close success\n");
//4.memcpy
    while (1)
    {
        printf("processB read:%s\n",(char *)addr);
        sleep(1);
    }
    
//5.
    munmap(addr, 1024);
    return 0;
}
