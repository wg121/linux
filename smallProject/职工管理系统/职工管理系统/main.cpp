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
		cout << "������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:                  //�˳�ϵͳ
			obj->exit_project();
			break;
		case 1:                   //����ְԱ��Ϣ
			obj->add_person();
			break;
		case 2:                  //��ʾְԱ��Ϣ
			obj->show_woker();
			break;
		case 3:                  //ɾ����ְԱ��
			obj->delete_person();
			break;
		case 4:                  //�޸ĳ�Ա
			obj->modification_person();
			break;
		case 5:                    //���ҳ�Ա
			obj->seek_person();
			break;
		case 6:                    //��id�����Ա
			obj->sort_worker();
			break;
		case 7:                    //����ļ��Լ�Ա��
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