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
	cout << "ְ����ţ� " << this->Id
		<< "\t������ " << this->Name
		<< "\t���ţ� " << this->get_DeptName()
		<< "\t��λְ������ϰ彻��������" << endl;
}

string Manager::get_DeptName()
{
	return string("����");
}
