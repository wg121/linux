#pragma once
/*
 *  ����һ����̬��Ҳ�Ǹ��࣬�����У�
 *  1.Boss��
 *  2.manager��
 *  3.employee��
 */

#include <iostream>
class Worker {
public:
	int		Id;       //���
	std::string	Name; //����
	int		DeptId;  //ְ�����ڲ��ű��
public:
	virtual void show_All() = 0;        //��ʾ������Ϣ
	virtual std::string get_DeptName() = 0;  //��ȡ��λ����
	virtual ~Worker();					//��������Ϊ���������������������������
};