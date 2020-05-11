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
	bool PlaceExpress(Express& e,int Postion);

	//ȡ����ݣ��ɹ�����true
	bool TakeExpress();

	//��ѯ��ݹ��Ƿ����������˷���-1��û�����ص�һ���յĿ�ݸ��λ��
	int IsFull();
private:
	const int MAXN = 500;
	ExpressCell* MyCells[500];
	friend Compare;
};

