#include "boss.h"
using namespace std;

Boss::Boss(int id, string name, int deptid)
{
	this->Name = name;
	this->Id = id;
	this->DeptId = deptid;
}

void Boss::show_All()
{
	cout << "职工编号： " << this->Id
		<< "\t姓名： " << this->Name
		<< "\t部门： " << this->get_DeptName()
		<< "\t岗位职责：下发任务" << endl;
}

string Boss::get_DeptName()
{
	return string("老板");
}
