#include "CharacterControl.h"
#include "UIControl.h"
#include <Windows.h>
#include <iostream>
#include<string>
using namespace std;
void CharacterControl::ExpressMan() 
{

}
void CharacterControl::Receiver() 
{

}

void CharacterControl::Adminstrator() 
{

}
void CharacterControl::UISettingSave(string color) 
{
	FILE* Filepointer;
	const char Filename[20] = "cofig.ini";
	if (fopen_s(&Filepointer, Filename, "w") == 0 && Filepointer != NULL)
	{
		fwrite(&color, color.length(), 1, Filepointer);
	}
	else
	{
		cout << "文件打开失败" << endl;
	}
}
void CharacterControl::UISetting()
{
	while (true) {
		UIControl::ShowUISetting();
		string cop;
		cin >> cop;
		if (cop == "1")
		{
			system("color 74");
			system("cls");
			cout << "设置成功！";
			Sleep(1000);
			system("cls");
			break;
		}
		else if (cop == "2")
		{
			system("color 07");
			system("cls");
			cout << "设置成功！";
			Sleep(1000);
			system("cls");
			break;
	}
		else if (cop == "3")
		{
			system("color 56");
			system("cls");
			cout << "设置成功！";
			Sleep(1000);
			system("cls");
			break;
		}
		else if (cop == "4")
		{
			system("color 20");
			system("cls");
			cout << "设置成功！";
			Sleep(1000);
			("cls");
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