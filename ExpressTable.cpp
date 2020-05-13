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
	/*FILE* FilePointer;
	if (fopen_s(&FilePointer,FileName,"rb") == 0 && FilePointer != NULL ) 
	{
		//���ļ��ɹ�
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
			MyCells[i] = (ExpressCell*)malloc(sizeof(ExpressCell));
			if (MyCells[i] != NULL)
			{
				MyCells[i]->Index = i;
				MyCells[i]->Timer = 0;
				MyCells[i]->ExpressPointer = NULL;
			}

		}
	}

	//�ر��ļ����ȼ��ָ���Ƿ�Ϊ��
	if(FilePointer)fclose(FilePointer);*/

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

	const char FileName[20] = "Cells.dat";
	ofstream fout(FileName, ios::out | ios::binary);
	if (fout.is_open()) 
	{
		for (int i = 0; i < MAXN; i++) {
			fout.write((char*)MyCells[i], sizeof(ExpressCell));
			fout << endl << MyCells[i]->StrTime;
			//fout.write((char*)&MyCells[i]->StrTime, sizeof(MyCells[i])->StrTime);
			if (MyCells[i]->ExpressPointer) 
			{
				fout << MyCells[i]->ExpressPointer->PhoneNumber << endl << MyCells[i]->ExpressPointer->OwnerName
					<< endl << MyCells[i]->ExpressPointer->CompanyName;
			}
		}
	}
	/*FILE* FilePointer;
	if (fopen_s(&FilePointer, FileName, "wb") == 0 && FilePointer != NULL)
	{
		for (int i = 0; i < MAXN; i++) 
		{
			if (MyCells[i] == NULL) 
			{
				//һ����˵��ֻҪ��ݹ�Ĺ��캯����ɣ�MyCells[i]��һ����ΪNULL
				//������Ȼ����NULL��Ϊ����ǿ�����ݴ���
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

	MyCells[Postion]->ExpressPointer = new Express;
	cin >> MyCells[Postion]->ExpressPointer->PhoneNumber >> MyCells[Postion]->ExpressPointer->OwnerName
		>> MyCells[Postion]->ExpressPointer->CompanyName;
	//time��������time_t���������ص��ǵ�ǰʱ��
	MyCells[Postion]->Timer = time(NULL);

	//��time_tת�����ַ���

	ctime_s(MyCells[Postion]->StrTime, 50, &MyCells[Postion]->Timer);
	
	return true;
}

