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
	bool TakeExpress(int Postion, char* phonenumber, char* ownername);

	//��ѯ��ݹ��Ƿ����������˷���-1��û�����ص�һ���յĿ�ݸ��λ��
	int IsFull();

	//��ѯ��ݹ��Ƿ��ǿյģ��Ƿ���true
	bool IsEmpty();

	//չʾ������Ʒ
	void Show();

private:
	const int MAXN = 500;
	ExpressCell* MyCells[500];
	friend Compare;
};

