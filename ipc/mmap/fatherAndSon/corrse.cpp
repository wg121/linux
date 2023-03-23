#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SIZE 128

//父子进程间使用mmap通信

int main(){
    int ret = -1;		//返回值类型判断
    pid_t pid = -1;
    int fd = -1;
    void *addr = NULL;
    char buf[SIZE];

//1.open txt -- 打开有个文件
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
    printf("close txt success -- mmap map success\n");

//创建进程
    pid = fork();
    if(-1 == pid){
        perror("fork");
        return 1;
    }

//child -- 子进程  给映射文件写数据
    if(0 == pid){
        int i = 0;
        while(1){
            memset(buf, 0, SIZE);
            sprintf(buf, "mmap %d\n",i++);
            memcpy(addr, buf, 1024);
            sleep(1);
        }
    }

//father -- 父进程向映射文件读数据
    else{
        while (1)
        {
            sleep(1);
            printf("father read:%s",(char *)addr);
        }
        
    }

//关闭映射
    munmap(addr, 1024);
    return 0;
}
