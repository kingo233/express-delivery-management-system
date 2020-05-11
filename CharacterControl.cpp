#include "CharacterControl.h"
#include "UIControl.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
void CharacterControl::ExpressMan(ExpressTable& Table)
{
	while (true) 
	{
		UIControl::ShowExpressMan();
		Express e;
		string ex;
		cin >> ex;
		int i;
		if (ex == "1")
		{
			for (i = 0; i <= 500; i++)
			{
				if (Table.MyCells[i] == 0)
				{
					Table.MyCells[i] = new ExpressCell();
					if (Table.PlaceExpress(e))
					{
						struct tm* Time;
						Table.MyCells[i]->Index = i;
						Table.MyCells[i]->Timer = time(NULL);
						Time = localtime(&Table.MyCells[i]->Timer);
						Table.MyCells[i]->StrTime = asctime(Time);
						break;
					}
					else
					{
						cout << "快递放入失败" << endl;
						break;
					}
				}

			}
			if (i > 500)
			{
				cout << "快递格已满,无法放入" << endl;
			}
		}
		else if (ex == "0")
		{
			system("cls");
			return;
		}
		else
		{
			system("cls");
			cout << "请输入正确的操作数！";
			Sleep(1000);
			system("cls");
		}
	}
}
void CharacterControl::Receiver() 
{

}

void CharacterControl::Adminstrator() 
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
	}
	fout << color << endl;
	fout.close();
}
void CharacterControl::UISetting()
{
	map<string, string> mp;
	
	while (true) {
		system("cls");
		cout << "请选择字体背景颜色设置：" << endl << "1.白色背景红色字体" << endl << "2.黑色背景白色字体" << endl
			<< "3.紫色背景黄色字体（猛男专用）" << endl << "4.绿色背景黑色字体（护眼模式）" << endl;
		string cop;
		cin >> cop;
		if (cop == "1" || cop == "2" || cop == "3" || cop == "4")
		{
			system(cop.c_str());
			system("cls");
			cout << "设置成功！";
			break;
		}
		else {
			system("cls");
			cout << "请输入正确的操作数！";
		}
		Sleep(1000);
		system("cls");
	}
}