#pragma once
#include "ExpressCell.h"
class ExpressTable
{
public:
	ExpressTable();
	~ExpressTable();
	void Save();
	bool PlaceExpress(Express e);//放入快递，成功返回true
	bool TakeExpress();//取出快递，成功返回true
	const int MAXN = 500;
	ExpressCell* MyCells[500];

};

