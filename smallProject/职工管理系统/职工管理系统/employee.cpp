#include "employee.h"
using namespace std;

Employee::Employee(int id, string name, int deptid)
{
	this->Name = name;
	this->Id = id;
	this->DeptId = deptid;
}

void Employee::show_All()
{
	cout << "职工编号： " << this->Id
		<< "\t姓名： " << this->Name
		<< "\t部门： " << this->get_DeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::get_DeptName()
{
	return string("员工");
}
