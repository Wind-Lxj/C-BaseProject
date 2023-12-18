#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

#define Max 1000;


//通讯录功能界面
void showMenu()
{
	cout << "********************************" << endl;
	cout << "*******  1、添加联系人  ********" << endl;
	cout << "*******  2、显示联系人  ********" << endl;
	cout << "*******  3、删除联系人  ********" << endl;
	cout << "*******  4、查找联系人  ********" << endl;
	cout << "*******  5、修改联系人  ********" << endl;
	cout << "*******  6、清空联系人  ********" << endl;
	cout << "*******  0、退出通讯录  ********" << endl;
	cout << "********************************" << endl;
}
//联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//通讯录结构体
struct Addressbook
{
	Person personArr[1000]; 
	int m_Size;
};
//添加联系人
void addPerson(Addressbook* abs)
{
	if (abs->m_Size >= 1000)
	{
		cout << "通讯录内存已满，无法添加···" << endl;
	}
	else
	{
		//输入姓名
		string name;
		cout << "请输入联系人姓名：";
		cin >> name;
		abs->personArr[abs->m_Size].m_Name = name;

		//输入性别
		int sex;
		cout << "请输入联系人性别：" << endl;
		cout << "1--男性：" << endl;
		cout << "0--女性：" << endl;
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
				cout << "性别输入有误，请重新输入:" ;
				cin >> sex;
			}
		}
		
		//输入年龄
		int age;
		cout << "请输入联系人年龄：";
		cin >> age;
		abs->personArr[abs->m_Size].m_Age = age;

		//输入联系人号码
		string phone;
		cout << "请输入联系人手机号：";
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
				cout << "输入的号码不正确，请重新输入:";
				cin >> phone;
			}
		}
		
		//输入联系人住址
		string addr;
		cout << "请输入联系人住址：";
		cin >> addr;
		abs->personArr[abs->m_Size].m_Addr = addr;

		//更新联系人数量
		abs->m_Size++;

		cout << "添加联系人成功" << endl;
		system("pause");
		system("cls");
	}
}
//显示联系人
void showPerson(Addressbook* abs)
{
	if (abs->m_Size == 0)	
	{
		cout << "通讯录联系人为空，请先添加联系人···" << endl;
		showMenu();
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "通讯录联系人信息：" <<endl
				<< "姓名： " << abs->personArr[i].m_Name
				<< "\t性别：" << abs->personArr[i].m_Sex
				<< "\t年龄：" << abs->personArr[i].m_Age
				<< "\t号码:" << abs->personArr[i].m_Phone
				<< "\t地址：" << abs->personArr[i].m_Addr << endl;
				
		}
		cout << "人数：" << abs->m_Size << endl;
	}
	system("pause");
	system("cls");

}
//判断联系人是否存在
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
//删除指定联系人
void deletePerson(Addressbook* abs)
{
	
	string name;
	while (true)
	{
		cout << "请输入删除的联系人姓名：";
		cin >> name;
		int ret = isExist(abs, name);
		if (ret != -1)
		{
			//联系人存在
			for (int i = ret; ret < abs->m_Size; ret++)
			{
				abs->personArr[i] = abs->personArr[i + 1];
			}
			abs->m_Size--;
			cout << "联系人删除成功···" << endl;
			break;
		}
		else
		{
			cout << "联系人不存在，请确认···" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(Addressbook* abs)
{
	string name;
	cout << "请输入需要查找的联系人：" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArr[ret].m_Name << "\t";
		cout << "性别：" << abs->personArr[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArr[ret].m_Age << "\t";
		cout << "电话：" << abs->personArr[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArr[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人···" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyPerson(Addressbook* abs)
{
	string name;//修改的名字
	cout << "请输入要修改的联系人的名字：" << endl;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//修改性别
		int sex;
		cout << "请输入联系人性别：" << endl;
		cout << "1--男性：" << endl;
		cout << "0--女性：" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 0)
			{
				abs->personArr[ret].m_Sex = sex;
			}
			else
			{
				cout << "性别输入有误，请重新输入:";
			}
		}

		//修改年龄
		int age;
		cout << "请输入联系人年龄：";
		cin >> age;
		abs->personArr[ret].m_Age = age;

		//修改手机号
		string phone;
		cout << "请输入联系人手机号：";
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
				cout << "输入的号码不正确，请重新输入:";
				cin >> phone;
			}
		}

		//修改住址
		string addr;
		cout << "请输入联系人住址：";
		cin >> addr;
		abs->personArr[ret].m_Addr = addr;

		cout << "修改成功···" << endl;
	}
	else
	{
		cout << "查无此人，修改失败···" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void clearPerson(Addressbook* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空···" << endl;
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
		cout << "请输入功能号码（0~6）：";
		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);
			break;

		case 2://显示联系人
			showPerson(&abs);
			break;

		case 3://删除联系人
			deletePerson(&abs);
			break;

		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;

		case 6://清空联系人
			clearPerson(&abs);
			break;

		case 0 ://退出通讯录
			cout << "退出功能···" << endl;
			return 0;
			break;
			
		default:
			cout << "不存在该功能···" << endl;
			break;
		}
	}
	
	
	
	
	
	system("pause");
	return 0;
}



