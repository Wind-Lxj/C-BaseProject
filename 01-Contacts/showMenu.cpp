#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

#define Max 1000;


//ͨѶ¼���ܽ���
void showMenu()
{
	cout << "********************************" << endl;
	cout << "*******  1�������ϵ��  ********" << endl;
	cout << "*******  2����ʾ��ϵ��  ********" << endl;
	cout << "*******  3��ɾ����ϵ��  ********" << endl;
	cout << "*******  4��������ϵ��  ********" << endl;
	cout << "*******  5���޸���ϵ��  ********" << endl;
	cout << "*******  6�������ϵ��  ********" << endl;
	cout << "*******  0���˳�ͨѶ¼  ********" << endl;
	cout << "********************************" << endl;
}
//��ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//ͨѶ¼�ṹ��
struct Addressbook
{
	Person personArr[1000]; 
	int m_Size;
};
//�����ϵ��
void addPerson(Addressbook* abs)
{
	if (abs->m_Size >= 1000)
	{
		cout << "ͨѶ¼�ڴ��������޷���ӡ�����" << endl;
	}
	else
	{
		//��������
		string name;
		cout << "��������ϵ��������";
		cin >> name;
		abs->personArr[abs->m_Size].m_Name = name;

		//�����Ա�
		int sex;
		cout << "��������ϵ���Ա�" << endl;
		cout << "1--���ԣ�" << endl;
		cout << "0--Ů�ԣ�" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 0) 
			{
				abs->personArr[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�Ա�������������������:" ;
				cin >> sex;
			}
		}
		
		//��������
		int age;
		cout << "��������ϵ�����䣺";
		cin >> age;
		abs->personArr[abs->m_Size].m_Age = age;

		//������ϵ�˺���
		string phone;
		cout << "��������ϵ���ֻ��ţ�";
		cin >> phone;
		while (true)
		{
			if (phone.size() == 11)	
			{
				abs->personArr[abs->m_Size].m_Phone = phone;
				break;
			}
			else 
			{
				cout << "����ĺ��벻��ȷ������������:";
				cin >> phone;
			}
		}
		
		//������ϵ��סַ
		string addr;
		cout << "��������ϵ��סַ��";
		cin >> addr;
		abs->personArr[abs->m_Size].m_Addr = addr;

		//������ϵ������
		abs->m_Size++;

		cout << "�����ϵ�˳ɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//��ʾ��ϵ��
void showPerson(Addressbook* abs)
{
	if (abs->m_Size == 0)	
	{
		cout << "ͨѶ¼��ϵ��Ϊ�գ����������ϵ�ˡ�����" << endl;
		showMenu();
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "ͨѶ¼��ϵ����Ϣ��" <<endl
				<< "������ " << abs->personArr[i].m_Name
				<< "\t�Ա�" << abs->personArr[i].m_Sex
				<< "\t���䣺" << abs->personArr[i].m_Age
				<< "\t����:" << abs->personArr[i].m_Phone
				<< "\t��ַ��" << abs->personArr[i].m_Addr << endl;
				
		}
		cout << "������" << abs->m_Size << endl;
	}
	system("pause");
	system("cls");

}
//�ж���ϵ���Ƿ����
int isExist(Addressbook* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArr[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//ɾ��ָ����ϵ��
void deletePerson(Addressbook* abs)
{
	
	string name;
	while (true)
	{
		cout << "������ɾ������ϵ��������";
		cin >> name;
		int ret = isExist(abs, name);
		if (ret != -1)
		{
			//��ϵ�˴���
			for (int i = ret; ret < abs->m_Size; ret++)
			{
				abs->personArr[i] = abs->personArr[i + 1];
			}
			abs->m_Size--;
			cout << "��ϵ��ɾ���ɹ�������" << endl;
			break;
		}
		else
		{
			cout << "��ϵ�˲����ڣ���ȷ�ϡ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findPerson(Addressbook* abs)
{
	string name;
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArr[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArr[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArr[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArr[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArr[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴��ˡ�����" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyPerson(Addressbook* abs)
{
	string name;//�޸ĵ�����
	cout << "������Ҫ�޸ĵ���ϵ�˵����֣�" << endl;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//�޸��Ա�
		int sex;
		cout << "��������ϵ���Ա�" << endl;
		cout << "1--���ԣ�" << endl;
		cout << "0--Ů�ԣ�" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 0)
			{
				abs->personArr[ret].m_Sex = sex;
			}
			else
			{
				cout << "�Ա�������������������:";
			}
		}

		//�޸�����
		int age;
		cout << "��������ϵ�����䣺";
		cin >> age;
		abs->personArr[ret].m_Age = age;

		//�޸��ֻ���
		string phone;
		cout << "��������ϵ���ֻ��ţ�";
		cin >> phone;
		while (true)
		{
			if (phone.size() == 11)
			{
				abs->personArr[ret].m_Phone = phone;
				break;
			}
			else
			{
				cout << "����ĺ��벻��ȷ������������:";
				cin >> phone;
			}
		}

		//�޸�סַ
		string addr;
		cout << "��������ϵ��סַ��";
		cin >> addr;
		abs->personArr[ret].m_Addr = addr;

		cout << "�޸ĳɹ�������" << endl;
	}
	else
	{
		cout << "���޴��ˣ��޸�ʧ�ܡ�����" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void clearPerson(Addressbook* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼����ա�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select;
	Addressbook abs;
	abs.m_Size = 0;

	while (true)
	{
		showMenu();
		cout << "�����빦�ܺ��루0~6����";
		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);
			break;

		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;

		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;

		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;

		case 6://�����ϵ��
			clearPerson(&abs);
			break;

		case 0 ://�˳�ͨѶ¼
			cout << "�˳����ܡ�����" << endl;
			return 0;
			break;
			
		default:
			cout << "�����ڸù��ܡ�����" << endl;
			break;
		}
	}
	
	
	
	
	
	system("pause");
	return 0;
}



