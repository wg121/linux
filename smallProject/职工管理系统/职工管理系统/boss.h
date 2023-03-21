#pragma once
#include <iostream>
#include "worker.h"
#include <string>

class Boss :public Worker {
public:
	Boss(int id, std::string name, int deptid);	//BOSS的构造函数
	void show_All();							//重写的show方法
	std::string get_DeptName();					//获取部门名称
};