#pragma once
#include "ExpressCell.h"
#include "Compare.h"
class ExpressTable
{
public:
	ExpressTable();
	~ExpressTable();

	//��������
	void Save();
	//�����ݣ��ɹ�����true
	bool PlaceExpress(int Postion);

	//ȡ����ݣ��ɹ�����true
	bool TakeExpress(int Postion);

	//��ѯ��ݹ��Ƿ����������˷���-1��û�����ص�һ���յĿ�ݸ��λ��
	int IsFull();

	//���ó�Ա��������˽�г�Ա
	char* returnOwnerName(int index);
	char* returnPhoneNumber(int index);
	int returnTimer(int index);

private:
	const int MAXN = 500;
	ExpressCell* MyCells[500];
	friend Compare;
};

