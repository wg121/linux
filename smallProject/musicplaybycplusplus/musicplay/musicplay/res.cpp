#include "res.h"
#include <string>

map<int, string> Res::music;

Res* Res::GetRes()
{
	static Res* p = new Res;
	return p;
}

//�ж�һ���ַ����Ľ�β�� .mp3
bool Res::isMusic(const string& name)
{
	int len = name.size();
	return name.substr(len - 4) == ".mp3";	//substr ��ȡ���4λ�ж��ǲ��� .mp3
}

//�����ֵĿո��滻Ϊ�»���
string Res::GetName(string name)
{
	for (int i = 0; i < name.size(); ++i) {
		if (name[i] == ' ')
			name[i] = '_';
	}
	return name;
}

//�������е��ļ�
void Res::TraverseAllfile()
{
	cout << "���������ֿ��URL:" << endl;
	string url_name;
	cin >> url_name;

	//filesystem ���°汾C++�� �ļ�������

	filesystem::path url(url_name);
	if (!filesystem::exists(url)) {//�ж�·���Ƿ����
		cout << "��ʼ��ʧ�ܣ�URL error��" << endl;
		exit(0);
	}

	//�õ����е������ļ� -- C++�±�׼��·������filesystem��
	//c++������
	int pos = 1;
	string oldname, newname;
	filesystem::directory_iterator begin(url);
	for (filesystem::directory_iterator end; begin != end; ++begin) {
		//��ʱ�ļ���ʱ��
		if (!filesystem::is_directory(begin->path())) {
			//�ж��ǲ���.mp3�ļ�
			if (isMusic(begin->path().filename().string())) {
				//�������ļ�������
				oldname = url_name + "/" + begin->path().filename().string();
				newname = GetName(oldname);
				int result = rename(oldname.c_str(), newname.c_str());//string ת��Ϊ char*  ��string��.c_str()
				music[pos++] = newname;//map
			}
		}
	}
	cout << "���ֿ���سɹ�..." << endl;
}

Res::Res() {
	cout << "��ʼ�����ֿ�...." << endl;
	TraverseAllfile();
}