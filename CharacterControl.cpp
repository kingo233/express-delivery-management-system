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
				return;
			}
			else 
			{
				cout << "请输入快递收件人号码、收件人姓名和快递公司名,用空格隔开" << endl;
				string PhoneNumer,OwnerName, CompanyName;
				cin >> PhoneNumer >> OwnerName >> CompanyName;
				Express e(PhoneNumer, OwnerName, CompanyName);
				if (Table.PlaceExpress(e, Index)) 
				{
					cout << "放入成功！" << endl;
				}
				else 
				{
					cout << "放入失败！" << endl;
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
			Sleep(1000);//暂停以便于用户看清楚错误信息
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
	map<string, string> mp;
	mp["1"] = "color 74";
	mp["2"] = "color 07";
	mp["3"] = "color 56";
	mp["4"] = "color 30";
	ifstream fin;
	const char FileName[20] = "cofig.ini";
	fin.open(FileName);
	if (fin.is_open())
	{
		string cop;
		fin>> cop;
		system(mp[cop].c_str());
	}
	fin.close();
}
void CharacterControl::UISetting()
{
	map<string, string> mp;
	mp["1"] = "color 74";
	mp["2"] = "color 07";
	mp["3"] = "color 56";
	mp["4"] = "color 30";
	while (true) {
		system("cls");
		cout << "请选择字体背景颜色设置：" << endl << "1.白色背景红色字体" << endl << "2.黑色背景白色字体" << endl
			<< "3.紫色背景黄色字体（猛男专用）" << endl << "4.绿色背景黑色字体（护眼模式）" << endl << "0.返回主菜单" << endl;
		string cop;
		cin >> cop;
		if (cop == "1" || cop == "2" || cop == "3" || cop == "4")
		{
			system(mp[cop].c_str());
			system("cls");
			cout << "设置成功！";
			UISettingSave(cop);
			break;
		}
		else if (cop == "0") return;
		else {
			system("cls");
			cout << "请输入正确的操作数！";
		}
		Sleep(1000);
		system("cls");
	}
}