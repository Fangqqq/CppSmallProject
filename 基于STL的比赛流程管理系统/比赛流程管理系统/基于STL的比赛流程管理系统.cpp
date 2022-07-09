#include <iostream>
using namespace std;
#include"speechManager.h"

int main()
{
	SpeechManager sm;
	int choice;
	//随机数种子
	srand((unsigned int)time(NULL));
	while (true)
	{
		sm.show_Menu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看记录
			sm.showRecord();
			break;
		case 3://清空记录
			sm.clearRecord();
			break;
		case 0://退出系统
			sm.exit_Sys();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}