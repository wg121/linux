#pragma once
#include "common.h"
//��Դ�ļ�
//����ģʽ
class Res {
public:
	static Res* GetRes();	//�ṩ�ӿ�
	
	static bool isMusic(const string &name);//--  .mp3
	static string GetName(string name);//���� �ո� ����Ϊ �»���
	static void TraverseAllfile();//�������е��ļ�


	static map<int, string> music;//������Դ
private:
	Res();//����ģʽ--���캯��˽�л�

};