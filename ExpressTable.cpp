#include "ExpressTable.h"
#include "Compare.h"
#include "CharacterControl.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
ExpressTable::ExpressTable()
{
	//����ָ�룬�Է���ָ
	memset(MyCells, 0, sizeof(MyCells));

	const char FileName[20] = "Cells.dat";
	//�������ƶ�ȡ�ļ���ʽ���ļ�
	ifstream fin(FileName, ios::in | ios::binary);

	//����ܴ�˵��֮ǰ����������
	if (fin.is_open()) 
	{
		for (int i = 0; i < MAXN; i++) {
			//����new�¶��󲢶�ȡ����
			MyCells[i] = new ExpressCell;
			//ǿ������ת����������ݿ��ȡ
			fin.read((char*)MyCells[i], sizeof(ExpressCell));

		}
	}
	//���ܴ򿪾�˵��֮ǰû�б�������
	else 
	{
		for (int i = 0; i < MAXN; i++)
		{
			MyCells[i] = new ExpressCell;
			MyCells[i]->Index = i;
		}
	}

	fin.close();
	//��������
	Save();
}
int  ExpressTable::IsFull() 
{
	for (int i = 0; i < MAXN; i++) 
	{
		//һ����˵��ֻҪ��ݹ�Ĺ��캯����ɣ�MyCells[i]��һ����ΪNULL
		if (MyCells[i] && MyCells[i]->Timer == 0) 
		{
			return i;
		}
		else if (MyCells[i] == NULL) 
		{
			//�Է���һ������debug
			cout << "MyCells[i]ָ�����NULL����" << endl;
		}
	}
	return -1;
}
bool ExpressTable::IsEmpty()
{
	for (int i = 0; i < MAXN; i++) {
		if (MyCells[i]->Timer != 0)return false;
	}
	return true;
}
void ExpressTable::Show()
{
	//���ȼ���ݹ��Ƿ�Ϊ�գ�Ϊ�վ����������Ϣ������
	if (IsEmpty()) {
		system("cls");
		cout << "����û�п�ݣ�" << endl;
		//��ͣ�Ա����û����������Ϣ
		Sleep(1000);
		return;
	}

	//���ȽϺ����������ȡ������ΪpCmp
	typedef bool (*pCmp)(ExpressCell*, ExpressCell*);
	//map��ֵ�����ڴ洢�ȽϺ����ĺ���ָ��
	map<string, pCmp> mp;

	//�Ժ���ָ����ɸ�ֵ
	mp["1"] = Compare::CompanyNameAscendingCmp;		
	mp["6"] = Compare::CompanyNameDescendingCmp;
	mp["2"] = Compare::OwnerNameAscendingCmp;		
	mp["7"] = Compare::OwnerNameDescendingCmp;
	mp["3"] = Compare::PhoneNumberAscendingCmp;		
	mp["8"] = Compare::PhoneNumberDescendingCmp;
	mp["4"] = Compare::IndexAscendingCmp;			
	mp["9"] = Compare::IndexDescendingCmp;
	mp["5"] = Compare::TimeAscendingCmp;			
	mp["10"] = Compare::TimeDescendingCmp;


	while (true)
	{
		system("cls");
		cout << "1(6).����ݹ�˾��������(����)����" << endl << "2(7).���ռ�����������(����)����" << endl
			<< "3(8).���ռ����ֻ���������(����)����" << endl << "4(9).����ݹ�������(����)����" << endl
			<< "5(10).�����ʱ����絽��(������)����" << endl << "0.����" << endl;

		//������
		string op;
		cin >> op;

		//����
		if (op == "0") 
		{
			return;
		}
		else if (mp[op] == NULL)
		{
			system("cls");
			cout << "��������ȷ�Ĳ�������" << endl;
			Sleep(1000);
		}
		else 
		{
			sort(MyCells, MyCells + MAXN, mp[op]);
			system("cls");

			//���δ�ӡ��Ϣ
			for (int i = 0; MyCells[i]->Timer != 0; i++) {
				MyCells[i]->PrintInfo();
			}
			system("pause");
		}
	}

	//��ԭ
	sort(MyCells, MyCells + MAXN, Compare::ResetCmp);
}
void ExpressTable::WriteLog(int mode, int Postion,char* time)
{
	//���ļ��м�¼
	ofstream fout;
	fout.open("log.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "��־�ļ���ʧ�ܣ�" << endl;
	}
	string s[2] = { "ȡ�����: ","������: " };

	//�������Ϣд���ļ�
	fout << s[mode] << " ������" << MyCells[Postion]->Express.OwnerName << "  �绰���룺" << MyCells[Postion]->Express.PhoneNumber
		<< "  ��ݹ�˾: " << MyCells[Postion]->Express.CompanyName << "  ����ʱ�䣺" << time << endl;
	fout.close();
}
void ExpressTable::Save() 
{

	const char FileName[20] = "Cells.dat";

	//�Զ����Ʒ�ʽ���ļ�
	ofstream fout(FileName, ios::out | ios::binary);

	if (fout.is_open()) 
	{
		for (int i = 0; i < MAXN; i++) {
			//ǿ������ת����������ݿ��д��
			fout.write((char*)MyCells[i], sizeof(ExpressCell));
		}
	}
	fout.close();

}
ExpressTable::~ExpressTable()
{
	//����֮ǰ�ȱ�������
	Save();
	for (int i = 0; i < MAXN; i++) {
		//delete֮ǰ�ȼ��ָ���Ƿ�ָ��NULL
		if (MyCells[i])delete (MyCells[i]);
	}
}
bool ExpressTable::PlaceExpress(int Postion) 
{

	cin >> MyCells[Postion]->Express.PhoneNumber >> MyCells[Postion]->Express.OwnerName
		>> MyCells[Postion]->Express.CompanyName;
	//time��������time_t���������ص��ǵ�ǰʱ��
	MyCells[Postion]->Timer = time(NULL);

	//��time_tת�����ַ���

	ctime_s(MyCells[Postion]->StrTime, 50, &MyCells[Postion]->Timer);

	//���ļ��м�¼
	WriteLog(1, Postion,MyCells[Postion]->StrTime);

	return true;
}
bool ExpressTable::TakeExpress(int Postion, char* phonenumber, char* ownername)
{
	if (MyCells[Postion]->Timer == 0)
	{
		//timerΪ0����û�п��
		
		return false;
	}
	else
	{
		if (strcmp(MyCells[Postion]->Express.OwnerName, ownername) == 0 && strcmp(MyCells[Postion]->Express.PhoneNumber, phonenumber) == 0)
		{
			

			//time��������time_t���������ص��ǵ�ǰʱ��
			MyCells[Postion]->Timer = time(NULL);

			//��time_tת�����ַ���

			ctime_s(MyCells[Postion]->StrTime, 50, &MyCells[Postion]->Timer);
			
			//д����־
			WriteLog(0, Postion,MyCells[Postion]->StrTime);

			//��timer���0�����ݱ�ȡ��
			MyCells[Postion]->Timer = 0;
			return true;
		}
		else
		{
			return false;
		}
	}

}

