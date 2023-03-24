#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <signal.h>
#include <unistd.h>

//打印信号集的标识
void dispSig(sigset_t *set){
    for (int i = 0; i < 32; i++)
    {
        if(sigismember(set, i)){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    putchar('\n');
}

int main(){
    sigset_t set;
	
	//清空信号集	
    sigemptyset(&set);
    dispSig(&set);

	//添加第15号信号，进入信号集
    sigaddset(&set, 15);
    dispSig(&set);

	//将所有信号加入到信号集种
    sigfillset(&set);
    dispSig(&set);

	//将20号信号，从信号集中取出
    sigdelset(&set, 20);
    dispSig(&set);
    return 0;
}
