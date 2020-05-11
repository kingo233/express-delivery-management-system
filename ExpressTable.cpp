#include "ExpressTable.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;
ExpressTable::ExpressTable()
{
	memset(MyCells, 0, sizeof(MyCells));
	FILE* FilePointer;
	const char FileName[20] = "Cells.dat";
	if (fopen_s(&FilePointer,FileName,"rb") == 0 && FilePointer != NULL ) 
	{
		//打开文件成功
		for (int i = 0; i < MAXN; i++) 
		{
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

	fclose(FilePointer);
}
int  ExpressTable::IsFull() 
{
	for (int i = 0; i < MAXN; i++) {
		if (MyCells[i] == NULL)return i;
	}
	return -1;
}
void ExpressTable::Save() 
{

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
	struct tm* Tblock = localtime(&MyCells[Postion]->Timer);
	
	if (Tblock)
	{ 
		MyCells[Postion]->StrTime = string(asctime(Tblock));
	}
	else
	{
		return false;
	}
	return true;
}

