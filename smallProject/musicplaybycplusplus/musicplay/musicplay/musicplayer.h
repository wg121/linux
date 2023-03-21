#pragma once
#include "common.h"
//音乐播放器模块
class MusicPlayer {
private:
	int currIndex;			//当前音乐的下标
	vector<string> cmd;		//转存为字符串，便于做音乐播放的时候，指令链接
public:
	//避免出现O 1下标，出现枚举
	enum CMD{Open,Play,Pause,Resume,Close};//打开，播放，暂停，

	MusicPlayer();
	void Menu();
	void KeyDown();

	void ShowMusic();
	void PlayMusic();
	void PauseMusic();
	void ResumeMusic();//继续音乐
	void NextMusic();
	void PreMusic();
	void RandMusic();
};