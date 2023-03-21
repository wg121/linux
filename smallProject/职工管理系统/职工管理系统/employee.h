#pragma once
#include <iostream>
#include <string>
#include "worker.h"

class Employee :public Worker {
public:
	Employee(int id, std::string name,int deptid);
	void show_All();
	std::string get_DeptName();
};