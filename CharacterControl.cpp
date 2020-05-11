#include "CharacterControl.h"
#include "UIControl.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
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
		system("cls");
		cout << "��ѡ�����屳����ɫ���ã�" << endl << "1.��ɫ������ɫ����" << endl << "2.��ɫ������ɫ����" << endl
			<< "3.��ɫ������ɫ���壨����ר�ã�" << endl << "4.��ɫ������ɫ���壨����ģʽ��" << endl;
		string cop;
		cin >> cop;
		if (cop == "1" || cop == "2" || cop == "3" || cop == "4")
		{
			switch (cop)
			{
			case "1": system("color 74");
				break;
			case "2": system("color 07");
				break;
			case "3": system("color 56");
				break;
			case "4": system("color 30");
				break;
			} cop;
			system("cls");
			cout << "���óɹ���";
			break;
		}
		else {
			system("cls");
			cout << "��������ȷ�Ĳ�������";
		}
		Sleep(1000);
		system("cls");
	}
}