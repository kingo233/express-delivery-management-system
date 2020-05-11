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
	//��ݸ�Ŀ��ָ��ָ����
	MyCells[Postion]->ExpressPointer = &e;
	//time��������time_t���������ص��ǵ�ǰʱ��
	MyCells[Postion]->Timer = time(NULL);
	//����tm�ṹ�壬�ڲ���������ʱ����Ϣ
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

