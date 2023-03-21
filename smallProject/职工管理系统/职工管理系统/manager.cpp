#include "manager.h"
using namespace std;

Manager::Manager(int id, string name, int deptid)
{
	this->Name = name;
	this->Id = id;
	this->DeptId = deptid;
}

void Manager::show_All()
{
	cout << "职工编号： " << this->Id
		<< "\t姓名： " << this->Name
		<< "\t部门： " << this->get_DeptName()
		<< "\t岗位职责：完成老板交给的任务" << endl;
}

string Manager::get_DeptName()
{
	return string("经理");
}
