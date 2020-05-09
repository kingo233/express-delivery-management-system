#include "ExpressTable.h"
#include <stdio.h>
#include <iostream>
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

ExpressTable::~ExpressTable()
{
	Save();
	for (int i = 0; i < MAXN; i++) {
		if (MyCells[i])delete MyCells[i];
	}
}

