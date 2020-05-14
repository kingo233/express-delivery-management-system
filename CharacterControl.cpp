#include "CharacterControl.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
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

}

void CharacterControl::Adminstrator(ExpressTable& Table) 
{

}
void CharacterControl::UISettingSave(string color) 
{
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
		cout << "请按以下信息设置字体背景颜色（背景颜色在前，字体颜色在后）：" << endl << "0 = 黑色 8 = 灰色" << endl << "1 = 蓝色 9 = 淡蓝色" << endl
			<< "2 = 绿色 A = 淡绿色" << endl << "3 = 浅绿色 B = 淡浅绿色" << endl << "4 = 红色 C = 淡红色" << endl << "5 = 紫色 D = 淡紫色" << endl
			<< "6 = 黄色 E = 淡黄色" << endl << "7 = 白色 F = 亮白色" << endl << "如：设置黑色背景白色字体请输入 08" << endl << "0.返回主菜单" << endl;
		string cop;
		cin >> cop;
		if (cop == "0") return;
		else if(cop.length()==2&&((cop[0]>='0'&&cop[0]<='9')||(cop[0]>='A'||cop[0]<='F'))&& ((cop[1] >= '0' && cop[1] <= '9') || (cop[1] >= 'A' || cop[1] <= 'F'))&&cop[0]!=cop[1])
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