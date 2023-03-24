处理僵尸进程的三种方法
1.wait和waitpid会造成主线程的阻塞
2.通过子线程终止发送SIGSTOP信号，配合signal函数使用
3.通过signal(SIGCHLD, SIG_IN),通知内核完成回收
