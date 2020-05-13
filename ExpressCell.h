#pragma once
#include <string>
#include <ctime>
#include "Express.h"
using namespace std;

//表示一个快递格
class ExpressCell
{
public:
	ExpressCell();
	~ExpressCell();
	
	int Index;//快递格的编号
	time_t Timer;//放入快递时的时间，用time_t整数表达，方便排序
	char StrTime[50];//日期的字符串表达，方便显示
	Express* ExpressPointer;//指向快递的指针

};



