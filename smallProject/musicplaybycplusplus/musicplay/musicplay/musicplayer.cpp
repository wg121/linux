#include "musicplayer.h"
#include "res.h"

MusicPlayer::MusicPlayer()
{
	Res::GetRes();
	currIndex = 1;//�ӵ�һ�����ֿ�ʼ
	cmd.push_back("open ");
	cmd.push_back("play ");
	cmd.push_back("pause ");
	cmd.push_back("resume ");
	cmd.push_back("close ");
}

void MusicPlayer::Menu()
{
	cout << "--------���ֲ�����------------" << endl;
	cout << "\t0.�˳�" << endl;
	cout << "\t1.��������" << endl;
	cout << "\t2.��ͣ" << endl;
	cout << "\t3.����" << endl;
	cout << "\t4.��һ��" << endl;
	cout << "\t5.��һ��" << endl;
	cout << "\t6.�������" << endl;
	cout << "-----------------------------" << endl;
}

void MusicPlayer::KeyDown()
{
	int keyval = 0;
	//��ʾ�赥
	ShowMusic();
	cout << "�������������" << endl;
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
	cout << "�赥��" << endl;
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
	//����
	string openCmd = cmd[CMD::Open] + Res::music[currIndex];
	mciSendString(openCmd.c_str(), 0, 0, 0);//��
	string playCmd = cmd[CMD::Play] + Res::music[currIndex];
	mciSendString(playCmd.c_str(), 0, 0, 0);//����
}

void MusicPlayer::PauseMusic()
{
	string pauseCmd = cmd[CMD::Pause] + Res::music[currIndex];
	mciSendString(pauseCmd.c_str(), 0, 0, 0);//����
}

void MusicPlayer::ResumeMusic()
{
	string resumeCmd = cmd[CMD::Resume] + Res::music[currIndex];
	mciSendString(resumeCmd.c_str(), 0, 0, 0);//����
}

void MusicPlayer::NextMusic()
{
	string closeCmd = cmd[CMD::Close] + Res::music[currIndex];
	mciSendString(closeCmd.c_str(), 0, 0, 0);//�رյ�ǰ������
	//���ֵ��±�++
	currIndex == Res::music.size() ? currIndex = 1 : currIndex++;
	string openCmd = cmd[CMD::Open] + Res::music[currIndex];
	mciSendString(openCmd.c_str(), 0, 0, 0);//��
	string playCmd = cmd[CMD::Play] + Res::music[currIndex];
	mciSendString(playCmd.c_str(), 0, 0, 0);//����
}

void MusicPlayer::PreMusic()
{
	string closeCmd = cmd[CMD::Close] + Res::music[currIndex];
	mciSendString(closeCmd.c_str(), 0, 0, 0);//�رյ�ǰ������
	//���ֵ��±�--
	currIndex == 1 ? currIndex = Res::music.size() : currIndex--;
	string openCmd = cmd[CMD::Open] + Res::music[currIndex];
	mciSendString(openCmd.c_str(), 0, 0, 0);//��
	string playCmd = cmd[CMD::Play] + Res::music[currIndex];
	mciSendString(playCmd.c_str(), 0, 0, 0);//����
}

//
void MusicPlayer::RandMusic()
{
	string closeCmd = cmd[CMD::Close] + Res::music[currIndex];
	mciSendString(closeCmd.c_str(), 0, 0, 0);//�رյ�ǰ������
	//��������±�
	currIndex = rand() % Res::music.size() + 1;
	string openCmd = cmd[CMD::Open] + Res::music[currIndex];
	mciSendString(openCmd.c_str(), 0, 0, 0);//��
	string playCmd = cmd[CMD::Play] + Res::music[currIndex];
	mciSendString(playCmd.c_str(), 0, 0, 0);//����
}
