#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

#define SIZE 64

int main(){
    int ret = -1;
   
    //获取当前文件的路径
    char buf[SIZE];
    memset(buf, 0, strlen(buf));
    if(NULL == getcwd(buf, SIZE)){
        perror("getcwd");
        return 1;
    }
    printf("getcwd : %s\n",buf);

    //打开一个目录
    DIR *dir = NULL;
    dir = opendir("txt");
    if(NULL == dir){
        perror("opendir");
        return 1;
    }
    printf("opendir is successful\n");

    //读一个目录
    struct dirent *d;
    d = readdir(dir);
    printf("file name: %s\n",d->d_name);
    printf("d_ino: %ld\n",d->d_ino);

    //关闭一个目录
    ret = closedir(dir);
    if(-1 == ret){
        perror("closedir");
        return 1;
    }
    return 0;
}
