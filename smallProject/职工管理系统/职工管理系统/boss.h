#pragma once
#include <iostream>
#include "worker.h"
#include <string>

class Boss :public Worker {
public:
	Boss(int id, std::string name, int deptid);	//BOSS�Ĺ��캯��
	void show_All();							//��д��show����
	std::string get_DeptName();					//��ȡ��������
};