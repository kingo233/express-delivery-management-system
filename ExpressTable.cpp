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
	//清零指针，以防乱指
	memset(MyCells, 0, sizeof(MyCells));

	const char FileName[20] = "Cells.dat";
	//按二进制读取文件方式打开文件
	ifstream fin(FileName, ios::in | ios::binary);

	//如果能打开说明之前保存了数据
	if (fin.is_open()) 
	{
		for (int i = 0; i < MAXN; i++) {
			//依次new新对象并读取数据
			MyCells[i] = new ExpressCell;
			//强制类型转换以完成数据块读取
			fin.read((char*)MyCells[i], sizeof(ExpressCell));

		}
	}
	//不能打开就说明之前没有保存数据
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
	//首先检查快递柜是否为空，为空就输出错误信息并返回
	if (IsEmpty()) {
		system("cls");
		cout << "柜内没有快递！" << endl;
		//暂停以便于用户看清错误信息
		Sleep(1000);
		return;
	}

	//给比较函数这个类型取个别名为pCmp
	typedef bool (*pCmp)(ExpressCell*, ExpressCell*);
	//map键值对用于存储比较函数的函数指针
	map<string, pCmp> mp;

	//对函数指针完成赋值
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
		cout << "1(6).按快递公司名称升序(降序)排序" << endl << "2(7).按收件人姓名升序(降序)排序" << endl
			<< "3(8).按收件人手机号码升序(降序)排序" << endl << "4(9).按快递柜编号升序(降序)排序" << endl
			<< "5(10).按入库时间从早到晚(从晚到早)排序" << endl << "0.返回" << endl;

		//操作数
		string op;
		cin >> op;

		//返回
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

			//依次打印信息
			for (int i = 0; MyCells[i]->Timer != 0; i++) {
				MyCells[i]->PrintInfo();
			}
			system("pause");
		}
	}

	//还原
	sort(MyCells, MyCells + MAXN, Compare::ResetCmp);
}
void ExpressTable::WriteLog(int mode, int Postion,char* time)
{
	//在文件中记录
	ofstream fout;
	fout.open("log.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "日志文件打开失败！" << endl;
	}
	string s[2] = { "取出快递: ","放入快递: " };

	//将相关信息写入文件
	fout << s[mode] << " 姓名：" << MyCells[Postion]->Express.OwnerName << "  电话号码：" << MyCells[Postion]->Express.PhoneNumber
		<< "  快递公司: " << MyCells[Postion]->Express.CompanyName << "  操作时间：" << time << endl;
	fout.close();
}
void ExpressTable::Save() 
{

	const char FileName[20] = "Cells.dat";

	//以二进制方式打开文件
	ofstream fout(FileName, ios::out | ios::binary);

	if (fout.is_open()) 
	{
		for (int i = 0; i < MAXN; i++) {
			//强制类型转换以完成数据块的写入
			fout.write((char*)MyCells[i], sizeof(ExpressCell));
		}
	}
	fout.close();

}
ExpressTable::~ExpressTable()
{
	//析构之前先保存数据
	Save();
	for (int i = 0; i < MAXN; i++) {
		//delete之前先检查指针是否指向NULL
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

	//在文件中记录
	WriteLog(1, Postion,MyCells[Postion]->StrTime);

	return true;
}
bool ExpressTable::TakeExpress(int Postion, char* phonenumber, char* ownername)
{
	if (MyCells[Postion]->Timer == 0)
	{
		//timer为0就是没有快递
		
		return false;
	}
	else
	{
		if (strcmp(MyCells[Postion]->Express.OwnerName, ownername) == 0 && strcmp(MyCells[Postion]->Express.PhoneNumber, phonenumber) == 0)
		{
			

			//time函数计算time_t整数，返回的是当前时间
			MyCells[Postion]->Timer = time(NULL);

			//将time_t转换成字符串

			ctime_s(MyCells[Postion]->StrTime, 50, &MyCells[Postion]->Timer);
			
			//写入日志
			WriteLog(0, Postion,MyCells[Postion]->StrTime);

			//把timer变成0代表快递被取出
			MyCells[Postion]->Timer = 0;
			return true;
		}
		else
		{
			return false;
		}
	}

}

