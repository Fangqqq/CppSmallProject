#include <iostream>
using namespace std;
#include<string>
#define MAX 1000

//定义联系人结构体
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string  m_Phone;
	string m_Addr;
};

//定义通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

//添加联系人信息
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex=0;
		cout << "请输入性别(输入1为男，输入2为女):" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入:" << endl;
		}

		int age = 0;
		cout << "请输入年龄(1~120):" << endl;
		while (true)
		{
			cin >> age;
			if (age>=0 && age<= 120)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入错误，请重新输入:" << endl;
		}

		string phone;
		cout << "请输入电话:" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "请输入地址:" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新人数
		abs->m_Size++;

		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}

//显示联系人信息
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		cout << "联系人列表" << endl;
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name <<"\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女")<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone<< "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << "\t";
			cout << endl;
		}

	}
	system("pause");
	system("cls");
}

//检测是否存在，存在时返回具体位置
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//删除指定联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入要删除联系人的名字" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人，删除失败" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size-1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}

	system("pause");
	system("cls");
}

//修改信息
void changePerson(Addressbooks* abs)
{
	cout << "请输入要修改联系人的名字" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人，修改失败" << endl;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = 0;
		cout << "请输入性别(输入1为男，输入2为女):" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入:" << endl;
		}

		int age = 0;
		cout << "请输入年龄(1~120):" << endl;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入错误，请重新输入:" << endl;
		}

		string phone;
		cout << "请输入电话:" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "请输入地址:" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}

	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入要查找联系人的名字" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人，修改失败" << endl;
	}
	else
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << "\t";
		cout << endl;
	}
	system("pause");
	system("cls");
}

//逻辑清空通讯录
void cleanAddressbooks(Addressbooks* abs)
{
	int select = 0;
	cout << "确定要清空所有联系人吗？(输入0为不确定，输入12345为确定):" << endl;
	cin >> select;
	while (true)
	{
		if (select == 0)
		{
			cout << "已撤销清空操作" << endl;
			break;
		}
		else if (select == 12345)
		{
			abs->m_Size = 0;
			cout << "通讯录已清空" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//展示菜单
void Show_Menu()
{
	cout << "********************************" << endl;
	cout << "******欢迎使用通讯录管理系统******" << endl;
	cout << "********0.退出管理系统**********" << endl;
	cout << "********1.增加联系人信息**********" << endl;
	cout << "********2.显示联系人信息**********" << endl;
	cout << "********3.删除联系人信息**********" << endl;
	cout << "********4.修改联系人信息**********" << endl;
	cout << "********5.查找联系人信息**********" << endl;
	cout << "********6.清空所有联系人信息**********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}



int main()
{
	Addressbooks abs;
	abs.m_Size = 0;

	int choice = 0;//用来存储用户的选项

	while (true)
	{
		Show_Menu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;//接收用户的选项

		switch (choice)
		{
		case 0://退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1://增加
			addPerson(&abs);
			break;
		case 2://显示
			showPerson(&abs);
			break;
		case 3://删除
			deletePerson(&abs);
			break;
		case 4://修改
			changePerson(&abs);
			break;
		case 5://查找
			findPerson(&abs);
			break;
		case 6://清空所有
			cleanAddressbooks(&abs);
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
