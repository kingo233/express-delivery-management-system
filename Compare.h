#pragma once
#include "ExpressCell.h"


//�����õľ�̬�࣬���������ֹؼ��ֱȽϵĺ���
static class Compare
{
public:
	bool Namecmp(ExpressCell a, ExpressCell b);
	bool OwnerNamecmp(ExpressCell a, ExpressCell b);
	bool PhoneNumercmp(ExpressCell a, ExpressCell b);
	bool Indexcmp(ExpressCell a, ExpressCell b);
	bool Timecmp(ExpressCell a, ExpressCell b);
};

