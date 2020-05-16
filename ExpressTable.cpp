#include "ExpressTable.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <string>
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
		if (MyCells[i] && MyCells[i]->Index == 0) 
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
bool ExpressTable::TakeExpress(int Postion)
{

	MyCells[Postion]->Timer = 0;
	return true;
}

char* ExpressTable::returnOwnerName(int index)
{
	return MyCells[index]->Express.OwnerName;
}

char* ExpressTable::returnPhoneNumber(int index)
{
	return MyCells[index]->Express.PhoneNumber;
}

int ExpressTable::returnTimer(int index)
{
	return MyCells[index]->Timer;
}

