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
	bool TakeExpress(int Postion);

	//查询快递柜是否已满，满了返回-1，没满返回第一个空的快递格的位置
	int IsFull();

	//利用成员函数访问私有成员
	char* returnOwnerName(int index);
	char* returnPhoneNumber(int index);
	int returnTimer(int index);

private:
	const int MAXN = 500;
	ExpressCell* MyCells[500];
	friend Compare;
};

