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
		//���ļ��ɹ�
		for (int i = 0; i < MAXN; i++) 
		{
			MyCells[i] = new ExpressCell;
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

	//�ر��ļ����ȼ��ָ���Ƿ�Ϊ��
	if(FilePointer)fclose(FilePointer);

	//��������
	Save();
}
int  ExpressTable::IsFull() 
{
	for (int i = 0; i < MAXN; i++) 
	{
		//һ����˵��ֻҪ��ݹ�Ĺ��캯����ɣ�MyCells[i]��һ����ΪNULL
		if (MyCells[i] && MyCells[i]->ExpressPointer == NULL) 
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
	FILE* FilePointer;
	const char FileName[20] = "Cells.dat";
	
	if (fopen_s(&FilePointer, FileName, "wb") == 0 && FilePointer != NULL)
	{
		for (int i = 0; i < MAXN; i++) 
		{
			if (MyCells[i] == NULL) 
			{
				//һ����˵��ֻҪ��ݹ�Ĺ��캯����ɣ�MyCells[i]��һ����ΪNULL
				//������Ȼ����NULL����ǿ�����ݴ���
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
	//��ݸ�Ŀ��ָ��ָ����
	MyCells[Postion]->ExpressPointer = &e;

	//time��������time_t���������ص��ǵ�ǰʱ��
	MyCells[Postion]->Timer = time(NULL);

	//����tm�ṹ�壬�ڲ���������ʱ����Ϣ
	struct tm* Tblock=NULL;

	char buffer[50];
	ctime_s(buffer, 50, &MyCells[Postion]->Timer);
	MyCells[Postion]->StrTime = string(buffer);
	//localtime_s(Tblock, &MyCells[Postion]->Timer);
	
	return true;
}

