#pragma once
#include <iostream>
using namespace std;
#include <fstream>     //实现文件的交互
#define FILENAME  "file.txt"

#include <string>
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
class workerManager {
public:
	int file_number;       //记录中的文件人数
	Worker** worker_arry;  //指向员工数组的指针
	bool file_is_empty;    //检测文件是否为空

	workerManager();   //构造函数

	void show_muen();  //菜单页面

	void exit_project();  //退出函数

	void add_person();   //添加成员函数

	void file_save();   //保存到文件，文件交互

	int get_file_number();    //获取文件人数

	void init_employee();    //初始化员工----初始化workerManager中的Worker ** m_EmpArray 指针

	void show_woker();    //显示员工

	void delete_person();   //删除员工

	int is_exist(int id);   //id是否存在   存在返回该值，否则返回-1

	void modification_person();   //修改成员

	void seek_person();       //查找成员

	void sort_worker();      //排序员工

	void clean_worker();    //清空员工

	~workerManager();  //析构函数
};