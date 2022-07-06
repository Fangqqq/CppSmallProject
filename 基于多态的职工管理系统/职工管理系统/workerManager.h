#pragma once //防止头文件重复包含
#include <iostream>
using namespace std;
#include "worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class workerManager
{
public:
	//构造函数
	workerManager();
	//展示菜单界面
	void show_Menu();
	//退出功能
	void exitSystem();

	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;
	//增加职工信息
	void add__Emp();

	//保存信息到文件
	void save();

	//标志文件是否为空
	bool m_FileIsEmpty;

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void show_Emp();

	//删除职工
	void del_Emp();

	//判断是否存在
	int isExit(int id);

	//修改职工
	void mod_Emp();

	//查找职工
	void find_Emp();

	//排序职工
	void sort_Emp();

	//清空职工
	void clean_File();

	//析构函数
	~workerManager();
};