#include "CharacterControl.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
void CharacterControl::ExpressMan(ExpressTable& Table)
{
	while (true) 
	{
		system("cls");
		cout << "选择操作：" << endl;
		cout << "0.返回主界面" << endl << "1.放入快递" << endl;
		//界面控制


		string op;
		getline(cin, op);

		if (op == "1")
		{
			//判断快递柜是否已满
			int Index = Table.IsFull();
			//返回-1说明满了
			if (Index == -1)
			{
				cout << "对不起，快递柜已满！" << endl;
				Sleep(1000);
				return;
			}
			else 
			{
				cout << "请输入快递收件人号码、收件人姓名和快递公司名,用空格隔开" << endl;

				if (Table.PlaceExpress(Index)) 
				{
					cout << "放入成功！" << endl;
					Sleep(1000);
				}
				else 
				{
					cout << "放入失败！" << endl;
					//暂停1秒便于用户看清提示信息
					Sleep(1000);
				}
			}
		}
		//返回主界面
		else if (op == "0")
		{
			return;
		}
		else
		{
			system("cls");
			cout << "请输入正确的操作数！";
			//暂停以便于用户看清楚错误信息
			Sleep(1000);
			system("cls");
		}
	}
}
void CharacterControl::Receiver(ExpressTable& Table) 
{
	while (true)
	{
		system("cls");
		cout << "选择操作" << endl;
		cout << "0.返回主界面" << endl << "1.取出快递" << endl;
		//界面控制

		//操作数
		string op;
		getline(cin, op);
		if (op == "1")
		{
			system("cls");

			//代表取出快递的数量
			int flag = 0;

			cout << "请输入姓名" << endl;
			//姓名和电话号码
			char name[10], phonenumber[20];

			cin.getline(name, 10);
			cout << "请输入电话号码" << endl;
			
			cin.getline(phonenumber, 20);

			for (int i = 0; i < 500; i++)
			{
				if (Table.TakeExpress(i, phonenumber, name))
				{
					cout << "取出成功" << endl;
					Sleep(1000);
					flag++;
				}
			}

			//表示未找到快递
			if (flag == 0)
			{
			    cout << "未找到与您信息相匹配的快递" << endl << "请确认您输入的信息是否正确" << endl;
				Sleep(1000);
				system("cls");
			
			}
		}
		//返回主界面
		else if (op == "0")
		{
			return;
		}
		else
		{
			system("cls");
			cout << "请输入正确的操作数！";

			//暂停以便于用户看清楚错误信息
			Sleep(1000);
			system("cls");
		}
	}
}

bool CharacterControl::IsPasswordCorrect()
{
	//用户输入的密码和正确的密码
	string Password, PasswordRight;

	ifstream fin;
	const char FileName[20] = "password.dat";
	//打开密码文件
	fin.open(FileName);
	//正确密码
	fin >> PasswordRight;
	fin.close();

	while (true) 
	{
		system("cls");
		cout << "0.返回主菜单" << endl;
		cout << "请输入管理员密码：" << endl;

		//验证密码
		getline(cin,Password);

		//输入为零返回主界面
		if (Password == "0") return false;
		//密码不正确重新输入
		else if (PasswordRight != Password)
		{
			cout << "密码输入错误！请重新输入正确密码";
			Sleep(1000);
		}
		//密码正确进入管理员函数
		else 
		{
			cout << "密码正确！";
			Sleep(1000);
			return true;
		}
	}
}
void CharacterControl::PasswordSet() 
{
	//第一遍输入的密码和确认的密码
	string Password, PasswordSure;

	while (true) 
	{
		system("cls");
		cout << "0.返回主菜单" << endl;
		cout << "请设置管理员密码：" << endl;

		//第一次输入密码
		getline(cin,Password);
		//输入为零返回主界面

		if (Password == "0") return;
		else 
		{
			//第二次确认密码
			cout << "请确认密码：" << endl;
			getline(cin,PasswordSure);

			if (Password == PasswordSure)
			{
				//密码一致保存密码
				ofstream fout;
				const char FileName[20] = "password.dat";
				//打开密码文件
				fout.open(FileName,ios::out);
				fout << Password;
				fout.close();

				cout << "密码设置成功！";
				Sleep(1000);
				break;
			}
			else 
			{
				//密码不一致重新输入
				cout << "密码不一致！请重新输入！";
				Sleep(1000);
			}
		}
	}
}

void CharacterControl::ReadLog()
{
	system("cls");

	ifstream inf;
	inf.open("log.txt", ios::in);
	if (!inf.is_open()) {
		cout << "日志为空！" << endl;
	}

	//s代表一条日志
	string s;
	while (getline(inf, s))
	{
		cout << s << endl;
	}
	inf.close();

	system("pause");
}

inline bool CharacterControl::IsOperatorCorrect(char c)
{
	if (isdigit(c) || toupper(c) >= 'A' && toupper(c) <= 'F')return true;
	else return false;
}
void CharacterControl::Adminstrator(ExpressTable& Table) 
{
	//判断管理员密码文件是否存在,1为存在
	int Exist;

	const char FileName[20] = "password.dat";
	ifstream PasswordFile;
	PasswordFile.open(FileName,ios::in);
	if (PasswordFile.is_open()) Exist = 1;
	else Exist = 0;
	PasswordFile.close();


	if (Exist == 0)
	{
		PasswordSet();
	}
	else
	{
		if (!IsPasswordCorrect())
		{
			return;
		}
	}

	while (true)
	{
		system("cls");
		cout << "管理员菜单" << endl;
		cout << "1.列出柜内物品" << endl << "2.查询日志" << endl << "3.更改密码" << endl;
		cout << "0.返回主菜单" << endl;

		string op;
		cin >> op;

		if (op == "1") 
		{
			Table.Show();
		}
		else if (op == "2") 
		{
			ReadLog();
		}
		else if (op == "3") 
		{
			PasswordSet();
		}
		else if (op == "0") 
		{
			return;
		}
		else 
		{
			system("cls");
			cout << "请输入正确的操作数！" << endl;
			//暂停1秒便于用户看清报错信息
			Sleep(1000);
		}
	}
	
}
void CharacterControl::UISettingSave(string color) 
{
	//将用户的界面设置保存在文件中
	ofstream fout;
	const char FileName[20] = "cofig.ini";
	fout.open(FileName);

	if (!fout.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	fout << color << endl;
	fout.close();
}
void CharacterControl::UISettingLoad()
{
	ifstream fin;
	const char FileName[20] = "cofig.ini";
	//打开界面设置文件
	fin.open(FileName);
	//打开成功加载用户界面设置

	if (fin.is_open())
	{
		string op1;
		string op2;
		//读入设置信息
		fin >> op1 >> op2;

		//将信息接入一个字符串
		op1.append(" ");
		op1.append(op2);

		//进行设置,但是要转化为字符指针
		system(op1.c_str());
	}
	fin.close();
}
void CharacterControl::UISetting()
{
	while (true) {
		system("cls");
		//提示用户输入设置信息
		cout << "请按以下信息设置字体背景颜色（背景颜色在前，字体颜色在后，字母不区分大小写）：" << endl << "0 = 黑色     8 = 灰色" << endl
			<< "1 = 蓝色     9 = 淡蓝色" << endl<< "2 = 绿色     A = 淡绿色" << endl << "3 = 浅绿色   B = 淡浅绿色" << endl 
			<< "4 = 红色     C = 淡红色" << endl 
			<< "5 = 紫色     D = 淡紫色" << endl<< "6 = 黄色     E = 淡黄色" << endl << "7 = 白色     F = 亮白色" << endl 
			<< "如：设置黑色背景白色字体请输入 07" << endl 
			<< "0.返回主菜单" << endl;

		//操作数
		string cop;
		getline(cin,cop);

		//输入为零返回主界面
		if (cop == "0") return;
		//输入不为零验证输入是否合法
		else if(cop.length() == 2 && IsOperatorCorrect(cop[0]) && IsOperatorCorrect(cop[1]) && cop[0] != cop[1])
		{
			//输入合法加载界面设置
			string color = "color ";
			//将用户输入的设置信息接到color末尾
			color.append(cop);
			//保存设置
			UISettingSave(string(color));

			//进行设置
			system(color.c_str());
			system("cls");
			cout << "设置成功!";

			Sleep(1000);
			system("cls");
			break;
		}
		else {
			//不合法时提示用户
			system("cls");
			cout << "请输入正确的操作数！";
			Sleep(1000);
			system("cls");
		}
	}
}