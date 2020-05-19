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
	bool PlaceExpress(int Postion);

	//取出快递，成功返回true
	bool TakeExpress(int Postion, char* phonenumber, char* ownername);

	//查询快递柜是否已满，满了返回-1，没满返回第一个空的快递格的位置
	int IsFull();

	//查询快递柜是否是空的，是返回true
	bool IsEmpty();

	//展示柜内物品
	void Show();

private:
	const int MAXN = 500;
	ExpressCell* MyCells[500];
	friend Compare;
};

