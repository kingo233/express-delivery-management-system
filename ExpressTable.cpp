#include "ExpressTable.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;
ExpressTable::ExpressTable()
{
	memset(MyCells, 0, sizeof(MyCells));
	const char FileName[20] = "Cells.dat";
	FILE* FilePointer;


	if (fopen_s(&FilePointer,FileName,"rb") == 0 && FilePointer != NULL ) 
	{
		//打开文件成功
		for (int i = 0; i < MAXN; i++) 
		{
			MyCells[i] = new ExpressCell;
			fread(MyCells[i], sizeof(ExpressCell), 1, FilePointer);
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
			MyCells[i] = new ExpressCell();
			MyCells[i]->Index = i;
		}
	}

	//关闭文件，先检查指针是否为空
	if(FilePointer)fclose(FilePointer);

	//保存数据
	Save();
}
int  ExpressTable::IsFull() 
{
	for (int i = 0; i < MAXN; i++) 
	{
		//一般来说，只要快递柜的构造函数完成，MyCells[i]就一定不为NULL
		if (MyCells[i] && MyCells[i]->ExpressPointer == NULL) 
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
	FILE* FilePointer;
	const char FileName[20] = "Cells.dat";
	
	if (fopen_s(&FilePointer, FileName, "wb") == 0 && FilePointer != NULL)
	{
		for (int i = 0; i < MAXN; i++) 
		{
			if (MyCells[i] == NULL) 
			{
				//一般来说，只要快递柜的构造函数完成，MyCells[i]就一定不为NULL
				//这里仍然讨论NULL是增强程序容错性
				MyCells[i] = new ExpressCell();
			}
			
			fwrite(MyCells[i], sizeof(ExpressCell), 1, FilePointer);
		}
	}
}
ExpressTable::~ExpressTable()
{
	Save();
	for (int i = 0; i < MAXN; i++) {
		if (MyCells[i])delete MyCells[i];
	}
}
bool ExpressTable::PlaceExpress(Express& e, int Postion) 
{
	//快递格的快递指针指向快递
	MyCells[Postion]->ExpressPointer = &e;

	//time函数计算time_t整数，返回的是当前时间
	MyCells[Postion]->Timer = time(NULL);

	//构造tm结构体，内部包含各种时间信息
	struct tm* Tblock=NULL;

	char buffer[50];
	ctime_s(buffer, 50, &MyCells[Postion]->Timer);
	MyCells[Postion]->StrTime = string(buffer);
	//localtime_s(Tblock, &MyCells[Postion]->Timer);
	
	return true;
}

