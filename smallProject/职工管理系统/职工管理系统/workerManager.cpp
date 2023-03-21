#include "workerManager.h"

workerManager::workerManager()
{
	this->file_number = 0;
	this->worker_arry = NULL;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在状况
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->file_is_empty = true;
		this->file_number = 0;
		this->worker_arry = NULL;
		ifs.close();
		return;
	}
	//文件存在，但没有记录时
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->file_is_empty = true;
		this->file_number = 0;
		this->worker_arry = NULL;
		ifs.close();
		return;
	}

	int num = this->get_file_number();
	//cout << "员工人数为：" << num << endl;  //测试代码
	this->file_number = num;                //更新文件人数

	this->worker_arry = new Worker * [this->file_number];
	this->init_employee();
	
	//测试代码
	/*
		for (int i = 0; i < this->file_number; i++) {
		cout << "职工号：" << worker_arry[i]->Id << '\t'
			<< "姓名：" << worker_arry[i]->Name << '\t'
			<< "岗位编号" << worker_arry[i]->DeptId << endl;
	}
	*/

}

void workerManager::show_muen()
{

	cout << "********************************************" << endl;
	cout << "********* 欢迎使用职工管理系统！ **********" << endl;
	cout << "************* 0.退出管理程序 *************" << endl;
	cout << "************* 1.增加职工信息 *************" << endl;
	cout << "************* 2.显示职工信息 *************" << endl;
	cout << "************* 3.删除离职职工 *************" << endl;
	cout << "************* 4.修改职工信息 *************" << endl;
	cout << "************* 5.查找职工信息 *************" << endl;
	cout << "************* 6.按照编号排序 *************" << endl;
	cout << "************* 7.清空所有文档 *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workerManager::exit_project()
{
	system("cls");
	cout << "即将推出系统" << endl;
	system("pause");
	exit(1);
}

void workerManager::add_person()
{
	cout << "请输入需要添加多少成员" << endl;

	int add_number;
	cin >> add_number;

	if (add_number > 0) {
		//计算新空间的大小，分配新的空间
		int new_size = this->file_number + add_number;
		Worker** new_space = new Worker * [new_size];
		//将原有的数据保存在新的空间，
		if (this->worker_arry != NULL) {
			for (int i = 0; i < this->file_number; i++) {
				new_space[i] = this->worker_arry[i];
			}
		}
		//将新数据，添加在新空间里。
		for (int j = 0; j < add_number; j++) {
			int new_id;
			string new_name;
			int new_deptid;
			cout << "请输入第" << j + 1 << "个新员工编号： ";
			cin >> new_id;
			cout << endl;

			cout << "请输入第" << j + 1 << "个新员工姓名： ";
			cin >> new_name;
			cout << endl;

			cout << "请输入第" << j + 1 << "个新员工部门编号： " << endl;
			cout << "1.老板" << endl;
			cout << "2.经理" << endl;
			cout << "3.员工" << endl;
			cin >> new_deptid;
			cout << endl;

			Worker* new2_woker = NULL;
			switch (new_deptid)
			{
			case 1:new2_woker = new Boss(new_id, new_name, 1);        //老板--Boss类
				break;
			case 2:new2_woker = new Manager(new_id, new_name, 2);     //经理--Manager类
				break;
			case 3:new2_woker = new Employee(new_id, new_name, 3);    //员工--employee类

			default:
				break;
			}
			//添加新成员
			new_space[this->file_number + j] = new2_woker;
		}
		//释放原有空间；
		delete[] this->worker_arry;
		//更改原有员工
		this->worker_arry = new_space;
		//更改原有员工人数
		this->file_number = new_size;
		//更改文件不为空
		this->file_is_empty = false;

		cout << "成功录入" << add_number << "个人" << endl;

		//保存到文件操作
		this->file_save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");

}

void workerManager::file_save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->file_number; i++) {
		ofs << this->worker_arry[i]->Id << "\t"
			<< this->worker_arry[i]->Name << "\t"
			<< this->worker_arry[i]->DeptId << endl;
	}
}

int workerManager::get_file_number()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int get_id;
	string get_name;
	int get_dept_id;

	int number = 0;
	while (ifs >> get_id && ifs >> get_name && ifs >> get_dept_id) {
		number++;
	}
	ifs.close();
	return number;
}

void workerManager::init_employee()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int get_id;
	string get_name;
	int get_dept_id;

	int index = 0;
	while (ifs >> get_id && ifs >> get_name && ifs >> get_dept_id) {
		Worker* worker = NULL;
		if (get_dept_id == 1) {
			worker = new Boss(get_id, get_name, get_dept_id);
		}
		else if (get_dept_id == 2) {
			worker = new Manager(get_id, get_name, get_dept_id);
		}
		else if (get_dept_id == 3) {
			worker = new Employee(get_id, get_name, get_dept_id);
		}
		this->worker_arry[index] = worker;
		index++;
	}
	ifs.close();
}

void workerManager::show_woker()
{
	if (this->file_is_empty) {
		cout << "文件为空" << endl;
	}
	else {
		for (int i = 0; i < this->file_number; i++) {
			this->worker_arry[i]->show_All();
		}
	}
	system("pause");
	system("cls");
}

void workerManager::delete_person()
{
	if (this->file_is_empty) {
		cout << "文件为空" << endl;
	}
	else {
		cout << "请输入要删除的人的id号：" << endl;
		int moment_num;
		cin >> moment_num;
		int index = this->is_exist(moment_num);

		if (index != -1) {
			for (int i = index; i < this->file_number; i++) {
				this->worker_arry[i] = this->worker_arry[i + 1];
			}
			//文件人数减一
			this->file_number--;
			//保存文件到  .txt
			this->file_save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "未找到该id的成员，删除失败" << endl;
		}
	}
	system("pause");
	system("cls");
}

int workerManager::is_exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->file_number; i++) {
		if (this->worker_arry[i]->Id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void workerManager::modification_person()
{
	if (this->file_is_empty) {
		cout << "文件为空" << endl;
	}
	else {
		cout << "请输入要修改的人的id号：" << endl;
		int moment_num;
		cin >> moment_num;
		int index = this->is_exist(moment_num);
		
		if (index != -1) {
			cout << "原有的信息：" << endl;
			this->worker_arry[index]->show_All();

			delete this->worker_arry[index];

			int new_id;
			string new_name;
			int new_dept_id;

			cout << "已查到" << index + 1 << "号职工，请输入该职工的新id号：" << endl;
			cin >> new_id;

			cout << "请输入该职工的新姓名：" << endl;
			cin >> new_name;

			cout << "请输入该职工的新部门编号：" << endl;
			cin >> new_dept_id;

			Worker* worker = NULL;
			switch (new_dept_id)
			{
			case 1:worker = new Boss(new_id, new_name, new_dept_id);
				break;
			case 2:worker = new Manager(new_id, new_name, new_dept_id);
				break;
			case 3:worker = new Employee(new_id, new_name, new_dept_id);
				break;
			default:
				break;
			}
			//更改id为index的人，修改信息
			this->worker_arry[index] = worker;
			//保存到文件
			this->file_save();
			cout << "修改成功" << endl;
		}
		else {
			cout << "查无此人，修改失败" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::seek_person()
{
	if (this->file_is_empty) {
		cout << "文件为空" << endl;
	}
	else {
		cout << "请输入查找方式：" << endl;
		cout << "1.按id号查找" << endl;
		cout << "2.按姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1) {
			int seek_id;
			cout << "请输入需要查找的id号：" << endl;
			cin >> seek_id;

			int ret = this->is_exist(seek_id);
			if (ret != -1) {
				cout << "查找成功！该职工信息如下：" << endl;
				this->worker_arry[ret]->show_All();
			}
			else {
				cout << "未找到该id号的员工!" << endl;
			}
		}
		else if (select == 2) {
			string seek_name;
			cout << "请输入需要查找的姓名：" << endl;
			cin >> seek_name;
			//标志位，标志是否存在
			bool flage = false;
			for (int i = 0; i < this->file_number; i++) {
				if (this->worker_arry[i]->Name == seek_name) {
					cout << "查找成功！该职工的信息如下：" << endl;
					this->worker_arry[i]->show_All();
					//更改标志位，代表存在
					flage = true;
				}
				
			}
				if (flage == false) {
					cout << "查无此人！" << endl;
				}
		}
		else
		{
			cout << "输入有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::sort_worker()
{
	if (this->file_is_empty) {
		cout << "文件为空！" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "该排序默认为冒泡排序，时间复杂度为n²，空间复杂度为1，稳定性强" << endl;
		cout << "请选择排序的顺序：" << endl;
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;

		int select = -1;
		cin >> select;

		if (select == 1) {
			for (int i = 0; i < this->file_number - 1; i++) {
				for (int j = 0; j < this->file_number - i - 1; j++) {
					if (this->worker_arry[j]->Id > this->worker_arry[j+1]->Id) {
						Worker* temp = this->worker_arry[j];
						this->worker_arry[j] = this->worker_arry[j + 1];
						this->worker_arry[j + 1] = temp;
					}
				}
			}
		}

		else if (select == 2) {		
			for (int i = 0; i < this->file_number - 1; i++) {
				for (int j = 0; j < this->file_number - i - 1; j++) {
					if (this->worker_arry[j]->Id < this->worker_arry[j+1]->Id) {
						Worker* temp = this->worker_arry[j];
						this->worker_arry[j] = this->worker_arry[j + 1];
						this->worker_arry[j + 1] = temp;
					}
				}
			}	
		}
		else {
				cout << "请规范输入正确排序方式！" << endl;
			}

		this->file_save();
		cout << "排序完成，下面显示排序后的员工" << endl;
		this->show_woker();
	}
}

void workerManager::clean_worker()
{
	cout << "是否要清空文件？" << endl;
	cout << "1.清空问价以及员工" << endl;
	cout << "2.不清空文件以及员工" << endl;

	int choice = -1;
	cin >> choice;
	if (choice == 1) {
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		if (this->worker_arry != NULL) {
			for (int i = 0; i < this->file_number; i++) {
				if (this->worker_arry[i] != NULL) {
					delete this->worker_arry[i];
				}
			}
			delete[]this->worker_arry;
			this->file_is_empty = true;
			this->file_number = 0;
			this->worker_arry = NULL;
		}
		cout << "清空成功！" << endl;
		system("pause");
	}
	else {
		system("pause");
		system("cls");
	}
}

workerManager::~workerManager()
{
	if (worker_arry != NULL) {
		delete[]worker_arry;
	}
}