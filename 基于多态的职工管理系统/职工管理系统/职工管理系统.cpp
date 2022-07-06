#include <iostream>
using namespace std;

#include "workerManager.h"

int main()
{
	workerManager wm;

	int choice = 0;//用来存储用户的选项

	while (true)
	{
		wm.show_Menu();//展示菜单
		cout << "请输入您的选择：" << endl;
		cin >> choice;//接收用户的选项

		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://增加职工
			wm.add__Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.del_Emp();
			break;
		case 4://修改职工
			wm.mod_Emp();
			break;
		case 5://查找职工
			wm.find_Emp();
			break;
		case 6://编号排序
			wm.sort_Emp();
			break;
		case 7://清空文档
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}
