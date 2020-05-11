#include "CharacterControl.h"
#include "ExpressTable.h"
#include "UIControl.h"
#include <Windows.h>
#include <iostream>
#include<fstream>
using namespace std;
void CharacterControl::ExpressMan()
{
	while (true) {
		UIControl::ShowExpressMan();
		ExpressTable Table;
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
						cout << "��ݷ���ʧ��" << endl;
						break;
					}
				}

			}
			if (i > 500)
			{
				cout << "��ݸ�����,�޷�����" << endl;
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
			cout << "��������ȷ�Ĳ�������";
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
		cout << "�ļ���ʧ��" << endl;
	}
	fout << color << endl;
	fout.close();
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