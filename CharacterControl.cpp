#include "CharacterControl.h"
#include "UIControl.h"
#include <Windows.h>
#include <iostream>
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
			cout << "���óɹ���";
			Sleep(1000);
			system("cls");
			break;
		}
		else if (cop == "2")
		{
			system("color 07");
			system("cls");
			cout << "���óɹ���";
			Sleep(1000);
			system("cls");
			break;
	}
		else if (cop == "3")
		{
			system("color 56");
			system("cls");
			cout << "���óɹ���";
			Sleep(1000);
			system("cls");
			break;
		}
		else if (cop == "4")
		{
			system("color 20");
			system("cls");
			cout << "���óɹ���";
			Sleep(1000);
			("cls");
			break;
		}
		else {
			system("cls");
			cout << "��������ȷ�Ĳ�������";
			Sleep(1000);
			system("cls");
		}
	}
}