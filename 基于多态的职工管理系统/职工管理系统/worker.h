#pragma once //防止头文件重复包含
#include <iostream>
using namespace std;
#include<string>

//职工抽象类
class Worker
{
public:

	//显示个人信息-纯虚函数不作任何实现
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0;

	//获取岗位职责
	virtual string getResponsibility()=0;

	int m_Id;//职工编号
	string m_Name;//职工姓名
	int m_DeptId;//部门编号
};
