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
	cout << "ְ����ţ� " << this->Id
		<< "\t������ " << this->Name
		<< "\t���ţ� " << this->get_DeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::get_DeptName()
{
	return string("Ա��");
}
