#pragma once
#include <iostream>
using namespace std;
#include <fstream>     //ʵ���ļ��Ľ���
#define FILENAME  "file.txt"

#include <string>
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
class workerManager {
public:
	int file_number;       //��¼�е��ļ�����
	Worker** worker_arry;  //ָ��Ա�������ָ��
	bool file_is_empty;    //����ļ��Ƿ�Ϊ��

	workerManager();   //���캯��

	void show_muen();  //�˵�ҳ��

	void exit_project();  //�˳�����

	void add_person();   //��ӳ�Ա����

	void file_save();   //���浽�ļ����ļ�����

	int get_file_number();    //��ȡ�ļ�����

	void init_employee();    //��ʼ��Ա��----��ʼ��workerManager�е�Worker ** m_EmpArray ָ��

	void show_woker();    //��ʾԱ��

	void delete_person();   //ɾ��Ա��

	int is_exist(int id);   //id�Ƿ����   ���ڷ��ظ�ֵ�����򷵻�-1

	void modification_person();   //�޸ĳ�Ա

	void seek_person();       //���ҳ�Ա

	void sort_worker();      //����Ա��

	void clean_worker();    //���Ա��

	~workerManager();  //��������
};