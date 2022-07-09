#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "speaker.h"
#include <map>
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>

//设计演讲管理类
class SpeechManager
{
public:
	//构造函数
	SpeechManager();

	//展示菜单
	void show_Menu();

	//退出系统
	void exit_Sys();

	//初始化属性 
	void initSpeech();

	//创建12名选手
	void createSpeaker();

	//控制比赛流程
	void startSpeech();

	//抽签
	void drawSpeech();

	//比赛
	void speechContest();

	//显示得分
	void showScore();

	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//显示往届记录
	void showRecord();

	//清空文件
	void clearRecord();


	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>>m_Record;

	//析构函数
	~SpeechManager();

	//成员属性
	vector<int> v1;//第一轮
	vector<int> v2;//第二轮
	vector<int> v3;//胜出前三名
	map<int, Speaker> m_Speaker;//存放选手及其编号
	int m_Index;//记录比赛轮数
};