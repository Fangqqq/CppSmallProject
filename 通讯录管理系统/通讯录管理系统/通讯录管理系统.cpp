#include <iostream>
using namespace std;
#include<string>
#define MAX 1000

//������ϵ�˽ṹ��
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string  m_Phone;
	string m_Addr;
};

//����ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

//�����ϵ����Ϣ
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex=0;
		cout << "�������Ա�(����1Ϊ�У�����2ΪŮ):" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������:" << endl;
		}

		int age = 0;
		cout << "����������(1~120):" << endl;
		while (true)
		{
			cin >> age;
			if (age>=0 && age<= 120)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "�����������������:" << endl;
		}

		string phone;
		cout << "������绰:" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "�������ַ:" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//��������
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

//��ʾ��ϵ����Ϣ
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ϵ���б�" << endl;
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name <<"\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex==1?"��":"Ů")<< "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone<< "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << "\t";
			cout << endl;
		}

	}
	system("pause");
	system("cls");
}

//����Ƿ���ڣ�����ʱ���ؾ���λ��
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

//ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "������Ҫɾ����ϵ�˵�����" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�ɾ��ʧ��" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size-1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}

	system("pause");
	system("cls");
}

//�޸���Ϣ
void changePerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸���ϵ�˵�����" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴��ˣ��޸�ʧ��" << endl;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = 0;
		cout << "�������Ա�(����1Ϊ�У�����2ΪŮ):" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������:" << endl;
		}

		int age = 0;
		cout << "����������(1~120):" << endl;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "�����������������:" << endl;
		}

		string phone;
		cout << "������绰:" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "�������ַ:" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
	}

	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "������Ҫ������ϵ�˵�����" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴��ˣ��޸�ʧ��" << endl;
	}
	else
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << "\t";
		cout << endl;
	}
	system("pause");
	system("cls");
}

//�߼����ͨѶ¼
void cleanAddressbooks(Addressbooks* abs)
{
	int select = 0;
	cout << "ȷ��Ҫ���������ϵ����(����0Ϊ��ȷ��������12345Ϊȷ��):" << endl;
	cin >> select;
	while (true)
	{
		if (select == 0)
		{
			cout << "�ѳ�����ղ���" << endl;
			break;
		}
		else if (select == 12345)
		{
			abs->m_Size = 0;
			cout << "ͨѶ¼�����" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//չʾ�˵�
void Show_Menu()
{
	cout << "********************************" << endl;
	cout << "******��ӭʹ��ͨѶ¼����ϵͳ******" << endl;
	cout << "********0.�˳�����ϵͳ**********" << endl;
	cout << "********1.������ϵ����Ϣ**********" << endl;
	cout << "********2.��ʾ��ϵ����Ϣ**********" << endl;
	cout << "********3.ɾ����ϵ����Ϣ**********" << endl;
	cout << "********4.�޸���ϵ����Ϣ**********" << endl;
	cout << "********5.������ϵ����Ϣ**********" << endl;
	cout << "********6.���������ϵ����Ϣ**********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}



int main()
{
	Addressbooks abs;
	abs.m_Size = 0;

	int choice = 0;//�����洢�û���ѡ��

	while (true)
	{
		Show_Menu();

		cout << "����������ѡ��" << endl;
		cin >> choice;//�����û���ѡ��

		switch (choice)
		{
		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		case 1://����
			addPerson(&abs);
			break;
		case 2://��ʾ
			showPerson(&abs);
			break;
		case 3://ɾ��
			deletePerson(&abs);
			break;
		case 4://�޸�
			changePerson(&abs);
			break;
		case 5://����
			findPerson(&abs);
			break;
		case 6://�������
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
