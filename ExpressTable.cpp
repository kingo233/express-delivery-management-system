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
		//���ļ��ɹ�
		for (int i = 0; i < MAXN; i++) 
		{
			fread(MyCells[i], sizeof(ExpressCell), 1, FilePointer);
		}
	}
	else
	{
		//�ļ�������
		//����wb��ʽ���������ļ�
		if (fopen_s(&FilePointer, FileName, "wb") == 0);
		else 
		{
			cout << "������ݹ������ļ�ʧ�ܣ�" << endl;
			return;
		}

		//ΪMyCells��ʼ��
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

