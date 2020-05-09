#pragma once
#include "ExpressCell.h"


//排序用的静态类，包含按各种关键字比较的函数
static class Compare
{
public:
	//按快递公司名称升序排序
	bool CompanyNameAscendingCmp(ExpressCell a, ExpressCell b);
	//按收件人姓名升序排序
	bool OwnerNameAscendingCmp(ExpressCell a, ExpressCell b);
	//按收件人手机号码升序排序
	bool PhoneNumerAscendingCmp(ExpressCell a, ExpressCell b);
	//按快递柜编号升序排序
	bool IndexAscendingCmp(ExpressCell a, ExpressCell b);
	//按入库时间从早到晚排序
	bool TimeAscendingCmp(ExpressCell a, ExpressCell b);


	//按快递公司名称降序排序
	bool CompanyNameDescendingCmp(ExpressCell a, ExpressCell b);
	//按收件人姓名降序排序
	bool OwnerNameDescendingCmp(ExpressCell a, ExpressCell b);
	//按收件人手机号码降序排序
	bool PhoneNumerDescendingCmp(ExpressCell a, ExpressCell b);
	//按快递柜编号降序排序
	bool IndexDescendingCmp(ExpressCell a, ExpressCell b);
	//按入库时间从晚到早排序
	bool TimeDescendingCmp(ExpressCell a, ExpressCell b);
};

