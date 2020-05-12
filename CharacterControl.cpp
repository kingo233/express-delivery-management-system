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
				return;
			}
			else 
			{
				cout << "���������ռ��˺��롢�ռ��������Ϳ�ݹ�˾��,�ÿո����" << endl;
				string PhoneNumer,OwnerName, CompanyName;
				cin >> PhoneNumer >> OwnerName >> CompanyName;
				Express e(PhoneNumer, OwnerName, CompanyName);
				if (Table.PlaceExpress(e, Index)) 
				{
					cout << "����ɹ���" << endl;
				}
				else 
				{
					cout << "����ʧ�ܣ�" << endl;
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
			Sleep(1000);//��ͣ�Ա����û������������Ϣ
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
		cout << "��ѡ�����屳����ɫ���ã�" << endl << "1.��ɫ������ɫ����" << endl << "2.��ɫ������ɫ����" << endl
			<< "3.��ɫ������ɫ���壨����ר�ã�" << endl << "4.��ɫ������ɫ���壨����ģʽ��" << endl << "0.�������˵�" << endl;
		string cop;
		cin >> cop;
		if (cop == "1" || cop == "2" || cop == "3" || cop == "4")
		{
			system(mp[cop].c_str());
			system("cls");
			cout << "���óɹ���";
			UISettingSave(cop);
			break;
		}
		else if (cop == "0") return;
		else {
			system("cls");
			cout << "��������ȷ�Ĳ�������";
		}
		Sleep(1000);
		system("cls");
	}
}