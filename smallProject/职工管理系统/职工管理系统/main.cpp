#include <iostream>
using namespace std;
#include "workerManager.h"

int main() {
	workerManager* obj = new workerManager;
	int choice;
	while (true)
	{	
		system("cls");
		obj->show_muen();
		cout << "请输入选项" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:                  //退出系统
			obj->exit_project();
			break;
		case 1:                   //增加职员信息
			obj->add_person();
			break;
		case 2:                  //显示职员信息
			obj->show_woker();
			break;
		case 3:                  //删除离职员工
			obj->delete_person();
			break;
		case 4:                  //修改成员
			obj->modification_person();
			break;
		case 5:                    //查找成员
			obj->seek_person();
			break;
		case 6:                    //按id排序成员
			obj->sort_worker();
			break;
		case 7:                    //清空文件以及员工
			obj->clean_worker();
			break;
		default:
			system("cls");
		break;
		}
	}	
	delete obj;
	system("pause");
	return 0;
}