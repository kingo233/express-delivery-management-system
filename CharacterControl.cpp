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
		cout << "ѡ�������" << endl;
		cout << "0.����������" << endl << "1.������" << endl;
		//�������


		string op;
		cin >> op;

		if (op == "1")
		{
			int Index = Table.IsFull();
			if (Index == -1)
			{
				cout << "�Բ��𣬿�ݹ�������" << endl;
				Sleep(1000);
				return;
			}
			else 
			{
				cout << "���������ռ��˺��롢�ռ��������Ϳ�ݹ�˾��,�ÿո����" << endl;

				if (Table.PlaceExpress(Index)) 
				{
					cout << "����ɹ���" << endl;
					Sleep(1000);
				}
				else 
				{
					cout << "����ʧ�ܣ�" << endl;
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
			cout << "��������ȷ�Ĳ�������";
			//��ͣ�Ա����û������������Ϣ
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
		cout << "�ļ���ʧ��" << endl;
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
		cout << "�밴������Ϣ�������屳����ɫ��������ɫ��ǰ��������ɫ�ں󣩣�" << endl << "0 = ��ɫ 8 = ��ɫ" << endl << "1 = ��ɫ 9 = ����ɫ" << endl
			<< "2 = ��ɫ A = ����ɫ" << endl << "3 = ǳ��ɫ B = ��ǳ��ɫ" << endl << "4 = ��ɫ C = ����ɫ" << endl << "5 = ��ɫ D = ����ɫ" << endl
			<< "6 = ��ɫ E = ����ɫ" << endl << "7 = ��ɫ F = ����ɫ" << endl << "�磺���ú�ɫ������ɫ���������� 08" << endl << "0.�������˵�" << endl;
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
			cout << "���óɹ�!";
			Sleep(1000);
			system("cls");
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