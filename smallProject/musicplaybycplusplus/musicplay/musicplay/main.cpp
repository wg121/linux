#include "common.h"
#include "musicplayer.h"

int main() {
	srand((unsigned int)time(NULL));//随机数的种子----为了产生随机播放效果

	MusicPlayer* p = new MusicPlayer;
	while (1) {
		p->Menu();
		p->KeyDown();
		system("cls");
	}
	
	int i = getchar();
	return (0);
}