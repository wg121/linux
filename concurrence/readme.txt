并发编程

1.创建线程，包含的函数有:fork(),
2.父子进程，if(pid == 0)子进程
3.使用wait()回收子进程的资源 ,wait函数阻塞

2fork文件中说明:
	fork()前后初始化变量，在父子进程中使用是：写时拷贝，读时共享
	无论是前还是后，变量都不会公用

后续在ipc中使用信号的处理函数，可以在使用waitpid()，不阻塞
	当子进程结束时发送一个信号，就可以捕捉到，进而进行waitpid的清理

4.使用exec函数族
