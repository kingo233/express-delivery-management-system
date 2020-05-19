#include "ExpressTable.h"
#include "Compare.h"
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
	memset(MyCells, 0, sizeof(MyCells));
	const char FileName[20] = "Cells.dat";
	
	ifstream fin(FileName, ios::in | ios::binary);
	if (fin.is_open()) 
	{
		for (int i = 0; i < MAXN; i++) {
			MyCells[i] = new ExpressCell;
			fin.read((char*)MyCells[i], sizeof(ExpressCell));

		}
	}
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
	if (IsEmpty()) {
		system("cls");
		cout << "����û�п�ݣ�" << endl;
		//��ͣ�Ա����û����������Ϣ
		Sleep(1000);
		return;
	}
	typedef bool (*pCmp)(ExpressCell*, ExpressCell*);
	//map��ֵ�����ڴ洢�ȽϺ����ĺ���ָ��
	map<string, pCmp> mp;
	mp["1"] = Compare::CompanyNameAscendingCmp;		mp["6"] = Compare::CompanyNameDescendingCmp;
	mp["2"] = Compare::OwnerNameAscendingCmp;		mp["7"] = Compare::OwnerNameDescendingCmp;
	mp["3"] = Compare::PhoneNumberAscendingCmp;		mp["8"] = Compare::PhoneNumberDescendingCmp;
	mp["4"] = Compare::IndexAscendingCmp;			mp["9"] = Compare::IndexDescendingCmp;
	mp["5"] = Compare::TimeAscendingCmp;			mp["10"] = Compare::TimeDescendingCmp;


	while (true)
	{
		system("cls");
		cout << "1(6).����ݹ�˾��������(����)����" << endl << "2(7).���ռ�����������(����)����" << endl
			<< "3(8).���ռ����ֻ���������(����)����" << endl << "4(9).����ݹ�������(����)����" << endl
			<< "5(10).�����ʱ����絽��(������)����" << endl << "0.����" << endl;

		string op;
		cin >> op;
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

			for (int i = 0; MyCells[i]->Timer != 0; i++) {
				MyCells[i]->PrintInfo();
			}
			system("pause");
		}
	}
	//��ԭ
	sort(MyCells, MyCells + MAXN, Compare::ResetCmp);
}
void ExpressTable::Save() 
{

	const char FileName[20] = "Cells.dat";
	ofstream fout(FileName, ios::out | ios::binary);
	if (fout.is_open()) 
	{
		for (int i = 0; i < MAXN; i++) {
			fout.write((char*)MyCells[i], sizeof(ExpressCell));
		}
	}
	fout.close();

}
ExpressTable::~ExpressTable()
{
	Save();
	for (int i = 0; i < MAXN; i++) {
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
	
	return true;
}
bool ExpressTable::TakeExpress(int Postion, char* phonenumber, char* ownername)
{
	if (MyCells[Postion]->Timer == 0)
	{
		//timerΪ0����û�п��
		cout << "��λ��û�п�ݣ�" << endl;
		return false;
	}
	else
	{
		if (strcmp(MyCells[Postion]->Express.OwnerName, ownername) == 0 && strcmp(MyCells[Postion]->Express.PhoneNumber, phonenumber) == 0)
		{
			MyCells[Postion]->Timer = 0;
				
			return true;
		}
		else
		{
			return false;
		}
	}

}

