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
			fin.read((char*)MyCells[i], sizeof(ExpressCell)+sizeof(Express));

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
	/*FILE* FilePointer;
	if (fopen_s(&FilePointer,FileName,"rb") == 0 && FilePointer != NULL ) 
	{
		//打开文件成功
		for (int i = 0; i < MAXN; i++) 
		{
			MyCells[i] = (ExpressCell*)malloc(sizeof(ExpressCell));
			if (MyCells[i] != NULL) 
			{
				fread(MyCells[i], sizeof(ExpressCell), 1, FilePointer);
			}
		}
	}
	else
	{
		//文件不存在
		//换用wb方式创建数据文件
		if (fopen_s(&FilePointer, FileName, "wb") == 0);
		else 
		{
			cout << "创建快递柜数据文件失败！" << endl;
			return;
		}

		//为MyCells初始化
		for (int i = 0; i < MAXN; i++)
		{
			MyCells[i] = (ExpressCell*)malloc(sizeof(ExpressCell));
			if (MyCells[i] != NULL)
			{
				MyCells[i]->Index = i;
				MyCells[i]->Timer = 0;
				MyCells[i]->ExpressPointer = NULL;
			}

		}
	}

	//关闭文件，先检查指针是否为空
	if(FilePointer)fclose(FilePointer);*/
	fin.close();
	//保存数据
	Save();
}
int  ExpressTable::IsFull() 
{
	for (int i = 0; i < MAXN; i++) 
	{
		//一般来说，只要快递柜的构造函数完成，MyCells[i]就一定不为NULL
		if (MyCells[i] && MyCells[i]->Index == 0) 
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
	/*FILE* FilePointer;
	if (fopen_s(&FilePointer, FileName, "wb") == 0 && FilePointer != NULL)
	{
		for (int i = 0; i < MAXN; i++) 
		{
			if (MyCells[i] == NULL) 
			{
				//一般来说，只要快递柜的构造函数完成，MyCells[i]就一定不为NULL
				//这里仍然讨论NULL是为了增强程序容错性
				MyCells[i] = (ExpressCell*)malloc(sizeof(ExpressCell));
				if (MyCells[i] != NULL)
				{
					MyCells[i]->Index = i;
					MyCells[i]->Timer = 0;
					MyCells[i]->StrTime = "";
					MyCells[i]->ExpressPointer = NULL;
				}
			}
			
			if (MyCells[i] != NULL) 
			{ 
				fwrite(MyCells[i], sizeof(ExpressCell), 1, FilePointer); 
			}
		}
	}*/
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

	cin >> MyCells[Postion]->ExpressPointer.PhoneNumber >> MyCells[Postion]->ExpressPointer.OwnerName
		>> MyCells[Postion]->ExpressPointer.CompanyName;
	//time函数计算time_t整数，返回的是当前时间
	MyCells[Postion]->Timer = time(NULL);

	//将time_t转换成字符串

	ctime_s(MyCells[Postion]->StrTime, 50, &MyCells[Postion]->Timer);
	
	return true;
}

