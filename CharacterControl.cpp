#include "CharacterControl.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
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
			//�жϿ�ݹ��Ƿ�����

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
		//����������
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
		//�������


		string op;
		cin >> op;
		if (op == "1")
		{
			system("cls");
			int i;

			//����ȡ����ݵ�����
			int flag=0;
			cout << "����������" << endl;
			char name[10];
			cin >> name;
			cout << "������绰����" << endl;
			char phonenumber[20];
			cin >> phonenumber;
			for ( i = 0; i < 500; i++)
			{
				if (Table.TakeExpress(i, phonenumber, name))
				{
					cout << "ȡ���ɹ�" << endl;
					Sleep(1000);
					flag++;
				}
			}

			//��ʾδ�ҵ����
			if (flag==0)
			{
			    cout << "δ�ҵ�������Ϣ��ƥ��Ŀ��" << endl << "��ȷ�����������Ϣ�Ƿ���ȷ" << endl;
				Sleep(1000);
				system("cls");
			
			}
		}
		//����������
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

bool CharacterControl::IsPasswordCorrect()
{
	string Password, PasswordRight;
	ifstream fin;
	const char FileName[20] = "password.dat";
	fin.open(FileName);
	//��ȷ����
	fin >> PasswordRight;
	fin.close();
	while (true) 
	{
		system("cls");
		cout << "0.�������˵�" << endl;
		cout << "���������Ա���룺" << endl;
		//��֤����
		cin >> Password;
		if (Password == "0") return false;
		else if (PasswordRight != Password)
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
}
void CharacterControl::PasswordSet() 
{
	string Password, PasswordSure;
	while (true) 
	{
		system("cls");
		cout << "0.�������˵�" << endl;
		cout << "�����ù���Ա���룺" << endl;
		//��һ����������
		cin >> Password;
		if (Password == "0") return;
		else 
		{
			cout << "��ȷ�����룺" << endl;
			//�ڶ���ȷ������
			cin >> PasswordSure;
			if (Password == PasswordSure)
			{
				ofstream fout;
				const char FileName[20] = "password.dat";
				fout.open(FileName,ios::out);
				//��������
				fout << Password;
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

void CharacterControl::ReadLog()
{
	system("cls");
	ifstream inf;
	inf.open("log.txt", ios::in);
	if (!inf.is_open()) {
		cout << "��־Ϊ�գ�" << endl;
	}
	//���д��ļ��ж�ȡ��Ϣ

	string s;
	while (getline(inf, s))
	{
		cout << s << endl;
	}
	inf.close();
	system("pause");
}

inline bool CharacterControl::IsOperatorCorrect(char c)
{
	if (isdigit(c) || toupper(c) >= 'A' && toupper(c) <= 'F')return true;
	else return false;
}
void CharacterControl::Adminstrator(ExpressTable& Table) 
{
	//�жϹ���Ա�����ļ��Ƿ����,1Ϊ����
	int Exist;

	const char FileName[20] = "password.dat";
	ifstream PasswordFile;
	PasswordFile.open(FileName,ios::in);
	if (PasswordFile.is_open()) Exist = 1;
	else Exist = 0;
	PasswordFile.close();


	if (Exist == 0)
	{
		PasswordSet();
	}
	else
	{
		if (!IsPasswordCorrect())
		{
			return;
		}
	}

	while (true)
	{
		system("cls");
		cout << "����Ա�˵�" << endl;
		cout << "1.�г�������Ʒ" << endl << "2.��ѯ��־" << endl << "3.��������" << endl;
		cout << "0.�������˵�" << endl;

		string op;
		cin >> op;

		if (op == "1") 
		{
			Table.Show();
		}
		else if (op == "2") 
		{
			ReadLog();
		}
		else if (op == "3") 
		{
			PasswordSet();
		}
		else if (op == "0") 
		{
			return;
		}
		else 
		{
			system("cls");
			cout << "��������ȷ�Ĳ�������" << endl;
			//��ͣ1������û����屨����Ϣ
			Sleep(1000);
		}
	}
	
}
void CharacterControl::UISettingSave(string color) 
{
	//���û��Ľ������ñ������ļ���

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
			<< "1 = ��ɫ     9 = ����ɫ" << endl<< "2 = ��ɫ     A = ����ɫ" << endl << "3 = ǳ��ɫ   B = ��ǳ��ɫ" << endl 
			<< "4 = ��ɫ     C = ����ɫ" << endl 
			<< "5 = ��ɫ     D = ����ɫ" << endl<< "6 = ��ɫ     E = ����ɫ" << endl << "7 = ��ɫ     F = ����ɫ" << endl 
			<< "�磺���ú�ɫ������ɫ���������� 07" << endl 
			<< "0.�������˵�" << endl;
		string cop;
		cin >> cop;
		if (cop == "0") return;

		else if(cop.length() == 2 && IsOperatorCorrect(cop[0]) && IsOperatorCorrect(cop[1]) && cop[0] != cop[1])
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