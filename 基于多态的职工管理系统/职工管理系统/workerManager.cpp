#include "workerManager.h"


workerManager::workerManager()
{
	//初始化属性
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1.文件不存在情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//2.文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件存在，但无数据" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//3.文件存在，并有记录
	int num = this->get_EmpNum();
	//cout << "已存在职工个数为：" << num << endl;//test
	this->m_EmpNum = num;//更新成员属性

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//存入数组
	this->init_Emp();
}

void workerManager::show_Menu()
{
	cout << "********************************" << endl;
	cout << "******欢迎使用职工管理系统******" << endl;
	cout << "********0.退出管理系统**********" << endl;
	cout << "********1.增加职工信息**********" << endl;
	cout << "********2.显示职工信息**********" << endl;
	cout << "********3.删除离职职工**********" << endl;
	cout << "********4.修改职工信息**********" << endl;
	cout << "********5.查找职工信息**********" << endl;
	cout << "********6.按照编号排序**********" << endl;
	cout << "********7.清空所有文档**********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

//添加职工
void workerManager::add__Emp()
{
	cout << "请输入添加职工数量：" << endl;

	int addNum = 0;//保存用户输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		int newSize = this->m_EmpNum + addNum;//计算新空间大小
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//拷贝原来空间中的数据
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//编号
			string name;//姓名
			int dSelect;//部门选择

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;

			cout << "请选择该职工岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[]this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空的标志
		this-> m_FileIsEmpty = false;

		//保存数据到文件中
		this->save();

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	//清屏
	system("pause");
	system("cls");
}

void workerManager::exitSystem()
{
	cout << "您已退出系统，欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	ifs.close();

	return num;
}

//初始化员工
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, 1);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, 2);
		}
		else
		{
			worker = new Boss(id, name, 3);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//显示职工
void workerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	//清屏
	system("pause");
	system("cls");
}

//判断职工是否存在，存在返回位置，不存在返回-1
int workerManager::isExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index=i;//找到
			break;
		}
	}
	return index;
}


//删除职工
void workerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请输入想要删除的编号：" << endl;
		int id = 0;
		cin >> id;

		int index=this->isExit(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				//前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新个数
			this->m_EmpNum--;
			this->save();
			cout << "删除成功，已删除此编号的职工" << endl;
		}
		else
		{
			cout << "删除失败，不存在此编号的职工" << endl;
		}
	}
	//清屏
	system("pause");
	system("cls");
}

//修改职工
void workerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请输入想要修改的编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExit(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "请输入新的职工号：";
			cin >> newId;
			cout << "请输入新的姓名：";
			cin >> newName;
			cout << "请输入新的岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId,newName,dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			this->m_EmpArray[index] = worker;
			this->save();
			cout << "修改成功，已修改此编号的职工" << endl;
		}
		else
		{
			cout << "修改失败，不存在此编号的职工" << endl;
		}
	}
	//清屏
	system("pause");
	system("cls");
}

//查找职工
void workerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请输入想要查找的编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExit(id);
		if (index != -1)
		{
			cout << "查找成功，该职工信息如下：" << endl;
			this->m_EmpArray[index]->showInfo();
		}
		else
		{
			cout << "查找失败，不存在此编号的职工" << endl;
		}
	}
	//清屏
	system("pause");
	system("cls");
}

void workerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
		//清屏
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按照职工号进行升序" << endl;
		cout << "2.按照职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		while (true)
		{
			if (select == 1 || select == 2)
			{
				for (int i = 0; i < m_EmpNum; i++)
				{
					int minOrmax = i;
					for (int j = i + 1; j < m_EmpNum; j++)
					{
						if (select == 1)//升序
						{
							if (m_EmpArray[minOrmax]->m_Id > m_EmpArray[j]->m_Id)
							{
								minOrmax = j;
							}
						}
						else
						{
							if (m_EmpArray[minOrmax]->m_Id < m_EmpArray[j]->m_Id)
							{
								minOrmax = j;
							}
						}
					}

					if (i != minOrmax)
					{
						Worker* temp = m_EmpArray[i];
						m_EmpArray[i] = m_EmpArray[minOrmax];
						m_EmpArray[minOrmax] = temp;
					}
				}
				cout << "排序成功，排序后结果为：" << endl;
				this->show_Emp();
				break;
			}
			else
			{

				
				cout << "输入错误，请重新输入" << endl;
				system("pause");
				system("cls");
				break;
			}
		}

		this->save();
	}
}

void workerManager::clean_File()
{
	cout << "确认为空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	//清屏
	system("pause");
	system("cls");
}

workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}