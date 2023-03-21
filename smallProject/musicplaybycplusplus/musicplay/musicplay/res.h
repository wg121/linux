#pragma once
#include "common.h"
//资源文件
//单例模式
class Res {
public:
	static Res* GetRes();	//提供接口
	
	static bool isMusic(const string &name);//--  .mp3
	static string GetName(string name);//处理 空格 更改为 下划线
	static void TraverseAllfile();//遍历所有的文件


	static map<int, string> music;//管理资源
private:
	Res();//单例模式--构造函数私有化

};