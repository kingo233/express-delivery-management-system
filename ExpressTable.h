#pragma once
#include "ExpressCell.h"
class ExpressTable
{
public:
	ExpressTable();
	~ExpressTable();
	void Save();


	const int MAXN = 500;
	ExpressCell* MyCells[500];

};

