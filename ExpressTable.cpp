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
	//保存数据
	Save();
}
int  ExpressTable::IsFull() 
{
	for (int i = 0; i < MAXN; i++) 
	{
		//一般来说，只要快递柜的构造函数完成，MyCells[i]就一定不为NULL
		if (MyCells[i] && MyCells[i]->Timer == 0) 
		{
			return i;
		}
		else if (MyCells[i] == NULL) 
		{
			//以防万一，便于debug
			cout << "MyCells[i]指针出现NULL错误！" << endl;
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
		cout << "柜内没有快递！" << endl;
		//暂停以便于用户看清错误信息
		Sleep(1000);
		return;
	}
	typedef bool (*pCmp)(ExpressCell*, ExpressCell*);
	//map键值对用于存储比较函数的函数指针
	map<string, pCmp> mp;
	mp["1"] = Compare::CompanyNameAscendingCmp;		mp["6"] = Compare::CompanyNameDescendingCmp;
	mp["2"] = Compare::OwnerNameAscendingCmp;		mp["7"] = Compare::OwnerNameDescendingCmp;
	mp["3"] = Compare::PhoneNumberAscendingCmp;		mp["8"] = Compare::PhoneNumberDescendingCmp;
	mp["4"] = Compare::IndexAscendingCmp;			mp["9"] = Compare::IndexDescendingCmp;
	mp["5"] = Compare::TimeAscendingCmp;			mp["10"] = Compare::TimeDescendingCmp;


	while (true)
	{
		system("cls");
		cout << "1(6).按快递公司名称升序(降序)排序" << endl << "2(7).按收件人姓名升序(降序)排序" << endl
			<< "3(8).按收件人手机号码升序(降序)排序" << endl << "4(9).按快递柜编号升序(降序)排序" << endl
			<< "5(10).按入库时间从早到晚(从晚到早)排序" << endl << "0.返回" << endl;

		string op;
		cin >> op;
		if (op == "0") 
		{
			return;
		}
		else if (mp[op] == NULL)
		{
			system("cls");
			cout << "请输入正确的操作数！" << endl;
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
	//还原
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
	//time函数计算time_t整数，返回的是当前时间
	MyCells[Postion]->Timer = time(NULL);

	//将time_t转换成字符串

	ctime_s(MyCells[Postion]->StrTime, 50, &MyCells[Postion]->Timer);
	
	return true;
}
bool ExpressTable::TakeExpress(int Postion, char* phonenumber, char* ownername)
{
	if (MyCells[Postion]->Timer == 0)
	{
		//timer为0就是没有快递
		cout << "该位置没有快递！" << endl;
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

