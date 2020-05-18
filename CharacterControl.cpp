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
	while (true)
	{
		system("cls");
		cout << "ѡ�����" << endl;
		cout << "0.����������" << endl << "1.ȡ�����" << endl;
		string op;
		cin >> op;
		if (op == "1")
		{
			system("cls");
			int i;
			int flag=0;//����ȡ����ݵ�����
			cout << "����������" << endl;
			char name[10];
			cin >> name;
			cout << "������绰����" << endl;
			char phonenumber[20];
			cin >> phonenumber;
			for ( i = 0; i < 500; i++)
			{
				if (Table.returnTimer(i) != 0)
				{
					if (strcmp(Table.returnOwnerName(i), name) == 0 && strcmp(Table.returnPhoneNumber(i), phonenumber) == 0)
					{
						if (Table.TakeExpress(i))
						{
							cout << "ȡ���ɹ�" << endl;
							flag++;
							Sleep(1000);
						}
						else
						{
							cout << "ȡ��ʧ��" << endl;
							Sleep(1000);
						}
					}	
				}
			}
			if (flag==0)
			{
			
			    cout << "δ�ҵ�������Ϣ��ƥ��Ŀ��" << endl << "��ȷ�����������Ϣ�Ƿ���ȷ" << endl;
				Sleep(1000);
				system("cls");
			
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

bool CharacterControl::IsPassword()
{
	string ispsd, psd;
	ifstream fin;
	const char FileName[20] = "passwd.dat";
	fin >> ispsd;
	fin.close();
	while (true) 
	{
		system("cls");
		cout << "0.�������˵�" << endl;
		cout << "���������Ա���룺" << endl;
		cin >> psd;
		if (psd == "0") break;
		else if (psd != ispsd) 
		{
			cout << "�����������������������ȷ����";
			Sleep(1000);
		}
		else 
		{
			cout << "������ȷ��";
			Sleep(1000);
			return true;
		}
	}
	return false;
}
void CharacterControl::PasswordSet() 
{
	string psd, psd1;
	while (true) 
	{
		system("cls");
		cout << "0.�������˵�" << endl;
		cout << "�����ù���Ա���룺" << endl;
		cin >> psd;
		if (psd == "0") return;
		else 
		{
			cout << "��ȷ�����룺" << endl;
			cin >> psd1;
			if (psd1 == "0") return;
			else if (psd1 == psd) 
			{
				ofstream fout;
				const char FileName[20] = "passwd.dat";
				fout.open(FileName);
				fout << psd1;
				fout.close();
				cout << "�������óɹ���";
				Sleep(1000);
				break;
			}
			else 
			{
				cout << "���벻һ�£����������룡";
				Sleep(1000);
			}
		}
	}
}
void CharacterControl::Adminstrator(ExpressTable& Table) 
{
	const char FileName[20] = "passwd.dat";
	fstream _file;
	_file.open(FileName, ios::in);
	if (!_file) 
	{
		PasswordSet();
	}
	else
	{
		if (IsPassword() == true)
		{

		}
		else if (IsPassword() == false) return;
	}
	_file.close();
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
		cout << "�밴������Ϣ�������屳����ɫ��������ɫ��ǰ��������ɫ�ں���ĸ�����ִ�Сд����" << endl << "0 = ��ɫ     8 = ��ɫ" << endl
			<< "1 = ��ɫ     9 = ����ɫ" << endl<< "2 = ��ɫ     A = ����ɫ" << endl << "3 = ǳ��ɫ   B = ��ǳ��ɫ" << endl << "4 = ��ɫ     C = ����ɫ" << endl 
			<< "5 = ��ɫ     D = ����ɫ" << endl<< "6 = ��ɫ     E = ����ɫ" << endl << "7 = ��ɫ     F = ����ɫ" << endl << "�磺���ú�ɫ������ɫ���������� 07" << endl 
			<< "0.�������˵�" << endl;
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