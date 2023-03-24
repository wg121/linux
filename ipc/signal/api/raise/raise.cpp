#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//给调用者发送一个信号

int main(){
    int i = 0;
    while (1)
    {
        sleep(1);
        printf("process doing...%d\n", i);
        i++;
        if(4 == i){
            //程序结束信号 -- 与 SIGKILL 不同，这个信号不能被阻塞和处理
			raise(SIGTERM);
        }
    }
    
    return 0;
}
