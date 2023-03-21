#pragma once
#include "common.h"
//���ֲ�����ģ��
class MusicPlayer {
private:
	int currIndex;			//��ǰ���ֵ��±�
	vector<string> cmd;		//ת��Ϊ�ַ��������������ֲ��ŵ�ʱ��ָ������
public:
	//�������O 1�±꣬����ö��
	enum CMD{Open,Play,Pause,Resume,Close};//�򿪣����ţ���ͣ��

	MusicPlayer();
	void Menu();
	void KeyDown();

	void ShowMusic();
	void PlayMusic();
	void PauseMusic();
	void ResumeMusic();//��������
	void NextMusic();
	void PreMusic();
	void RandMusic();
};