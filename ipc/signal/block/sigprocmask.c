#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <signal.h>

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

//sigprocemask
//
int main(){
    int ret = -1;			//返回参数
    sigset_t set, set2;	//信号集的集合
    
	sigemptyset(&set);		//置空信号集
    sigaddset(&set, 20);	//添加20号信号进入信号集
    dispSig(&set);			//显示信号集

	//添加信号集，添加到阻塞信号集中
    ret = sigprocmask(SIG_BLOCK, &set, NULL);
    if(-1 == ret){
        perror("sigprocmask");
        return 1;
    }
	
	//读取当前进程的未决信号集
    ret = sigpending(&set2);
    if(-1 == ret){
        perror("sigpending");
        return 1;
    }
    dispSig(&set2);

    return 0;
}
