#pragma once
#include <iostream>
#include <string>
#include "worker.h"

class Manager :public Worker {
public:
	Manager(int id, std::string name, int deptid);
	void show_All();
	std::string get_DeptName();
};