#pragma once
#include "ExpressCell.h"
class ExpressTable
{
public:
	ExpressTable();
	~ExpressTable();
	void Save();
	bool PlaceExpress(Express e);//�����ݣ��ɹ�����true
	bool TakeExpress();//ȡ����ݣ��ɹ�����true
	const int MAXN = 500;
	ExpressCell* MyCells[500];

};

