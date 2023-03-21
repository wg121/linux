#include "musicplayer.h"
#include "res.h"

MusicPlayer::MusicPlayer()
{
	Res::GetRes();
	currIndex = 1;//从第一首音乐开始
	cmd.push_back("open ");
	cmd.push_back("play ");
	cmd.push_back("pause ");
	cmd.push_back("resume ");
	cmd.push_back("close ");
}

void MusicPlayer::Menu()
{
	cout << "--------音乐播放器------------" << endl;
	cout << "\t0.退出" << endl;
	cout << "\t1.播放音乐" << endl;
	cout << "\t2.暂停" << endl;
	cout << "\t3.继续" << endl;
	cout << "\t4.上一曲" << endl;
	cout << "\t5.下一曲" << endl;
	cout << "\t6.随机播放" << endl;
	cout << "-----------------------------" << endl;
}

void MusicPlayer::KeyDown()
{
	int keyval = 0;
	//显示歌单
	ShowMusic();
	cout << "请输入你的先择" << endl;
	cin >> keyval;
	switch (keyval)
	{
	case 0:exit(0);
		break;
	case 1:PlayMusic();
		break;
	case 2:PauseMusic();
		break;
	case 3:ResumeMusic();
		break;
	case 4:PreMusic();
		break;
	case 5:NextMusic();
		break;
	case 6:RandMusic();
		break;
	default:
		break;
	}
}

void MusicPlayer::ShowMusic()
{
	cout << "歌单：" << endl;
	for (auto v : Res::music) {
		if (v.first == currIndex) {
			cout << v.first << "\t" << v.second << "\t<----" << endl;
		}
		else {
			cout << v.first << "\t" << v.second << endl;
		}
	}
}

void MusicPlayer::PlayMusic()
{
	//播放
	string openCmd = cmd[CMD::Open] + Res::music[currIndex];
	mciSendString(openCmd.c_str(), 0, 0, 0);//打开
	string playCmd = cmd[CMD::Play] + Res::music[currIndex];
	mciSendString(playCmd.c_str(), 0, 0, 0);//播放
}

void MusicPlayer::PauseMusic()
{
	string pauseCmd = cmd[CMD::Pause] + Res::music[currIndex];
	mciSendString(pauseCmd.c_str(), 0, 0, 0);//播放
}

void MusicPlayer::ResumeMusic()
{
	string resumeCmd = cmd[CMD::Resume] + Res::music[currIndex];
	mciSendString(resumeCmd.c_str(), 0, 0, 0);//播放
}

void MusicPlayer::NextMusic()
{
	string closeCmd = cmd[CMD::Close] + Res::music[currIndex];
	mciSendString(closeCmd.c_str(), 0, 0, 0);//关闭当前的音乐
	//音乐的下标++
	currIndex == Res::music.size() ? currIndex = 1 : currIndex++;
	string openCmd = cmd[CMD::Open] + Res::music[currIndex];
	mciSendString(openCmd.c_str(), 0, 0, 0);//打开
	string playCmd = cmd[CMD::Play] + Res::music[currIndex];
	mciSendString(playCmd.c_str(), 0, 0, 0);//播放
}

void MusicPlayer::PreMusic()
{
	string closeCmd = cmd[CMD::Close] + Res::music[currIndex];
	mciSendString(closeCmd.c_str(), 0, 0, 0);//关闭当前的音乐
	//音乐的下标--
	currIndex == 1 ? currIndex = Res::music.size() : currIndex--;
	string openCmd = cmd[CMD::Open] + Res::music[currIndex];
	mciSendString(openCmd.c_str(), 0, 0, 0);//打开
	string playCmd = cmd[CMD::Play] + Res::music[currIndex];
	mciSendString(playCmd.c_str(), 0, 0, 0);//播放
}

//
void MusicPlayer::RandMusic()
{
	string closeCmd = cmd[CMD::Close] + Res::music[currIndex];
	mciSendString(closeCmd.c_str(), 0, 0, 0);//关闭当前的音乐
	//产生随机下标
	currIndex = rand() % Res::music.size() + 1;
	string openCmd = cmd[CMD::Open] + Res::music[currIndex];
	mciSendString(openCmd.c_str(), 0, 0, 0);//打开
	string playCmd = cmd[CMD::Play] + Res::music[currIndex];
	mciSendString(playCmd.c_str(), 0, 0, 0);//播放
}
