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

	//快递格的编号
	int Index;

	//放入快递时的时间，用time_t整数表达，方便排序
	time_t Timer;

	//日期的字符串表达，方便显示
	char StrTime[50];

	//与一个快递关联
	Express Express;

};



