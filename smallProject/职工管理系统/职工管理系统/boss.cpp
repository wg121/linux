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
	cout << "ְ����ţ� " << this->Id
		<< "\t������ " << this->Name
		<< "\t���ţ� " << this->get_DeptName()
		<< "\t��λְ���·�����" << endl;
}

string Boss::get_DeptName()
{
	return string("�ϰ�");
}
