#pragma once //��ֹͷ�ļ��ظ�����
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
	//���캯��
	workerManager();
	//չʾ�˵�����
	void show_Menu();
	//�˳�����
	void exitSystem();

	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArray;
	//����ְ����Ϣ
	void add__Emp();

	//������Ϣ���ļ�
	void save();

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void show_Emp();

	//ɾ��ְ��
	void del_Emp();

	//�ж��Ƿ����
	int isExit(int id);

	//�޸�ְ��
	void mod_Emp();

	//����ְ��
	void find_Emp();

	//����ְ��
	void sort_Emp();

	//���ְ��
	void clean_File();

	//��������
	~workerManager();
};