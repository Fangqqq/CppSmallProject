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

//����ݽ�������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//չʾ�˵�
	void show_Menu();

	//�˳�ϵͳ
	void exit_Sys();

	//��ʼ������ 
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	//���Ʊ�������
	void startSpeech();

	//��ǩ
	void drawSpeech();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//��ʾ�����¼
	void showRecord();

	//����ļ�
	void clearRecord();


	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>>m_Record;

	//��������
	~SpeechManager();

	//��Ա����
	vector<int> v1;//��һ��
	vector<int> v2;//�ڶ���
	vector<int> v3;//ʤ��ǰ����
	map<int, Speaker> m_Speaker;//���ѡ�ּ�����
	int m_Index;//��¼��������
};