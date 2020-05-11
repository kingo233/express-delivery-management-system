#pragma once
#include "ExpressCell.h"
#include "Compare.h"
class ExpressTable
{
public:
	ExpressTable();
	~ExpressTable();

	//保存数据
	void Save();
	//放入快递，成功返回true
	bool PlaceExpress(Express& e,int Postion);

	//取出快递，成功返回true
	bool TakeExpress();

	//查询快递柜是否已满，满了返回-1，没满返回第一个空的快递格的位置
	int IsFull();
private:
	const int MAXN = 500;
	ExpressCell* MyCells[500];
	friend Compare;
};

