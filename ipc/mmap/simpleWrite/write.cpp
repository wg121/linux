#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

//在txt文件中写入1234567890
int main(){
    int fd = -1;
    void *addr = NULL;
    
//1.open txt 以只读的方式打开一个文件
    fd = open("txt", O_RDWR);
    if(-1 == fd){
        perror("open");
        return 1;
    }
//2. mmap  -- 文件映射
    addr = mmap(NULL, 1024, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if(addr == MAP_FAILED){
        perror("mmap");
        return 1;
    }
    printf("mmap success\n");
    printf("addr:%s\n",(char *)addr);

//3.close -- 关闭文件
    close(fd);
    printf("close success\n");

//4.memcpy -- 写内存
    memcpy(addr, "1234567890", 10);
    printf("memcpy success\n");

//5.munmap -- 文件映射断开
    munmap(addr, 1024);
    return 0;
}
