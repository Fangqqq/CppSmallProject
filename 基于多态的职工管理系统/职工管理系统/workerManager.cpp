#include "workerManager.h"


workerManager::workerManager()
{
	//��ʼ������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1.�ļ����������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//2.�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ����ڣ���������" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����м�¼
	int num = this->get_EmpNum();
	//cout << "�Ѵ���ְ������Ϊ��" << num << endl;//test
	this->m_EmpNum = num;//���³�Ա����

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//��������
	this->init_Emp();
}

void workerManager::show_Menu()
{
	cout << "********************************" << endl;
	cout << "******��ӭʹ��ְ������ϵͳ******" << endl;
	cout << "********0.�˳�����ϵͳ**********" << endl;
	cout << "********1.����ְ����Ϣ**********" << endl;
	cout << "********2.��ʾְ����Ϣ**********" << endl;
	cout << "********3.ɾ����ְְ��**********" << endl;
	cout << "********4.�޸�ְ����Ϣ**********" << endl;
	cout << "********5.����ְ����Ϣ**********" << endl;
	cout << "********6.���ձ������**********" << endl;
	cout << "********7.��������ĵ�**********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

//���ְ��
void workerManager::add__Emp()
{
	cout << "���������ְ��������" << endl;

	int addNum = 0;//�����û���������
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		int newSize = this->m_EmpNum + addNum;//�����¿ռ��С
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//����ԭ���ռ��е�����
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;//���
			string name;//����
			int dSelect;//����ѡ��

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�յı�־
		this-> m_FileIsEmpty = false;

		//�������ݵ��ļ���
		this->save();

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
	}
	else
	{
		cout << "������������" << endl;
	}
	//����
	system("pause");
	system("cls");
}

void workerManager::exitSystem()
{
	cout << "�����˳�ϵͳ����ӭ�´�ʹ��" << endl;
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

//��ʼ��Ա��
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

//��ʾְ��
void workerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	//����
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ���ڣ����ڷ���λ�ã������ڷ���-1
int workerManager::isExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index=i;//�ҵ�
			break;
		}
	}
	return index;
}


//ɾ��ְ��
void workerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "��������Ҫɾ���ı�ţ�" << endl;
		int id = 0;
		cin >> id;

		int index=this->isExit(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				//ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//���¸���
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�����ɾ���˱�ŵ�ְ��" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ������ڴ˱�ŵ�ְ��" << endl;
		}
	}
	//����
	system("pause");
	system("cls");
}

//�޸�ְ��
void workerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵı�ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExit(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�������µ�ְ���ţ�";
			cin >> newId;
			cout << "�������µ�������";
			cin >> newName;
			cout << "�������µĸ�λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			cout << "�޸ĳɹ������޸Ĵ˱�ŵ�ְ��" << endl;
		}
		else
		{
			cout << "�޸�ʧ�ܣ������ڴ˱�ŵ�ְ��" << endl;
		}
	}
	//����
	system("pause");
	system("cls");
}

//����ְ��
void workerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "��������Ҫ���ҵı�ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExit(id);
		if (index != -1)
		{
			cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
			this->m_EmpArray[index]->showInfo();
		}
		else
		{
			cout << "����ʧ�ܣ������ڴ˱�ŵ�ְ��" << endl;
		}
	}
	//����
	system("pause");
	system("cls");
}

void workerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
		//����
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.����ְ���Ž�������" << endl;
		cout << "2.����ְ���Ž��н���" << endl;

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
						if (select == 1)//����
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
				cout << "����ɹ����������Ϊ��" << endl;
				this->show_Emp();
				break;
			}
			else
			{

				
				cout << "�����������������" << endl;
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
	cout << "ȷ��Ϊ�գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

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
		cout << "��ճɹ�" << endl;
	}
	//����
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