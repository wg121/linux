#include "common.h"
#include "musicplayer.h"

int main() {
	srand((unsigned int)time(NULL));//�����������----Ϊ�˲����������Ч��

	MusicPlayer* p = new MusicPlayer;
	while (1) {
		p->Menu();
		p->KeyDown();
		system("cls");
	}
	
	int i = getchar();
	return (0);
}