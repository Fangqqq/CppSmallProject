#pragma once //��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;
#include<string>

//ְ��������
class Worker
{
public:

	//��ʾ������Ϣ-���麯�������κ�ʵ��
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;

	//��ȡ��λְ��
	virtual string getResponsibility()=0;

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//���ű��
};
