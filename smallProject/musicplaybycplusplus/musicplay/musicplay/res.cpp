#include "res.h"
#include <string>

map<int, string> Res::music;

Res* Res::GetRes()
{
	static Res* p = new Res;
	return p;
}

//判断一个字符串的结尾是 .mp3
bool Res::isMusic(const string& name)
{
	int len = name.size();
	return name.substr(len - 4) == ".mp3";	//substr 截取最后4位判断是不是 .mp3
}

//把名字的空格替换为下划线
string Res::GetName(string name)
{
	for (int i = 0; i < name.size(); ++i) {
		if (name[i] == ' ')
			name[i] = '_';
	}
	return name;
}

//遍历所有的文件
void Res::TraverseAllfile()
{
	cout << "请输入音乐库的URL:" << endl;
	string url_name;
	cin >> url_name;

	//filesystem 是新版本C++的 文件操作集

	filesystem::path url(url_name);
	if (!filesystem::exists(url)) {//判断路径是否存在
		cout << "初始化失败（URL error）" << endl;
		exit(0);
	}

	//得到所有的音乐文件 -- C++新标准的路径管理（filesystem）
	//c++迭代器
	int pos = 1;
	string oldname, newname;
	filesystem::directory_iterator begin(url);
	for (filesystem::directory_iterator end; begin != end; ++begin) {
		//当时文件的时候
		if (!filesystem::is_directory(begin->path())) {
			//判断是不是.mp3文件
			if (isMusic(begin->path().filename().string())) {
				//把所有文件重命名
				oldname = url_name + "/" + begin->path().filename().string();
				newname = GetName(oldname);
				int result = rename(oldname.c_str(), newname.c_str());//string 转换为 char*  （string）.c_str()
				music[pos++] = newname;//map
			}
		}
	}
	cout << "音乐库加载成功..." << endl;
}

Res::Res() {
	cout << "初始化音乐库...." << endl;
	TraverseAllfile();
}