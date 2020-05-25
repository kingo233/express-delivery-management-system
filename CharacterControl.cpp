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
		cin >> op;

		if (op == "1")
		{
			//判断快递柜是否已满

			int Index = Table.IsFull();
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


		string op;
		cin >> op;
		if (op == "1")
		{
			system("cls");
			int i;

			//代表取出快递的数量
			int flag=0;
			cout << "请输入姓名" << endl;
			char name[10];
			cin >> name;
			cout << "请输入电话号码" << endl;
			char phonenumber[20];
			cin >> phonenumber;
			for ( i = 0; i < 500; i++)
			{
				if (Table.TakeExpress(i, phonenumber, name))
				{
					cout << "取出成功" << endl;
					Sleep(1000);
					flag++;
				}
			}

			//表示未找到快递
			if (flag==0)
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
	string Password, PasswordRight;
	ifstream fin;
	const char FileName[20] = "password.dat";
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
		cin >> Password;
		if (Password == "0") return false;
		else if (PasswordRight != Password)
		{
			cout << "密码输入错误！请重新输入正确密码";
			Sleep(1000);
		}
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
	string Password, PasswordSure;
	while (true) 
	{
		system("cls");
		cout << "0.返回主菜单" << endl;
		cout << "请设置管理员密码：" << endl;
		//第一次输入密码
		cin >> Password;
		if (Password == "0") return;
		else 
		{
			cout << "请确认密码：" << endl;
			//第二次确认密码
			cin >> PasswordSure;
			if (Password == PasswordSure)
			{
				ofstream fout;
				const char FileName[20] = "password.dat";
				fout.open(FileName,ios::out);
				//保存密码
				fout << Password;
				fout.close();
				cout << "密码设置成功！";
				Sleep(1000);
				break;
			}
			else 
			{
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
	//按行从文件中读取信息

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
	fin.open(FileName);
	if (fin.is_open())
	{
		string op1;
		string op2;
		fin >> op1>>op2;
		op1.append(" ");
		op1.append(op2);
		system(op1.c_str());
	}
	fin.close();
}
void CharacterControl::UISetting()
{
	while (true) {
		system("cls");
		cout << "请按以下信息设置字体背景颜色（背景颜色在前，字体颜色在后，字母不区分大小写）：" << endl << "0 = 黑色     8 = 灰色" << endl
			<< "1 = 蓝色     9 = 淡蓝色" << endl<< "2 = 绿色     A = 淡绿色" << endl << "3 = 浅绿色   B = 淡浅绿色" << endl 
			<< "4 = 红色     C = 淡红色" << endl 
			<< "5 = 紫色     D = 淡紫色" << endl<< "6 = 黄色     E = 淡黄色" << endl << "7 = 白色     F = 亮白色" << endl 
			<< "如：设置黑色背景白色字体请输入 07" << endl 
			<< "0.返回主菜单" << endl;
		string cop;
		cin >> cop;
		if (cop == "0") return;

		else if(cop.length() == 2 && IsOperatorCorrect(cop[0]) && IsOperatorCorrect(cop[1]) && cop[0] != cop[1])
		{
			string color = "color ";
			color.append(cop);
			UISettingSave(string(color));
			system(color.c_str());
			system("cls");
			cout << "设置成功!";
			Sleep(1000);
			system("cls");
			break;
		}
		else {
			system("cls");
			cout << "请输入正确的操作数！";
			Sleep(1000);
			system("cls");
		}
	}
}