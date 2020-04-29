#pragma once
#include "ExpressCell.h"


//排序用的静态类，包含按各种关键字比较的函数
static class Compare
{
public:
	bool Namecmp(ExpressCell a, ExpressCell b);
	bool OwnerNamecmp(ExpressCell a, ExpressCell b);
	bool PhoneNumercmp(ExpressCell a, ExpressCell b);
	bool Indexcmp(ExpressCell a, ExpressCell b);
	bool Timecmp(ExpressCell a, ExpressCell b);
};

