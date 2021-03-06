#pragma once
#include "ExpressCell.h"


//排序用的类，包含按各种关键字比较的函数
class Compare
{
public:
	//按快递公司名称升序排序
	static bool CompanyNameAscendingCmp(ExpressCell* a, ExpressCell* b);
	//按收件人姓名升序排序
	static bool OwnerNameAscendingCmp(ExpressCell* a, ExpressCell* b);
	//按收件人手机号码升序排序
	static bool PhoneNumberAscendingCmp(ExpressCell* a, ExpressCell* b);
	//按快递柜编号升序排序
	static bool IndexAscendingCmp(ExpressCell* a, ExpressCell* b);
	//按入库时间从早到晚排序
	static bool TimeAscendingCmp(ExpressCell* a, ExpressCell* b);


	//按快递公司名称降序排序
	static bool CompanyNameDescendingCmp(ExpressCell* a, ExpressCell* b);
	//按收件人姓名降序排序
	static bool OwnerNameDescendingCmp(ExpressCell* a, ExpressCell* b);
	//按收件人手机号码降序排序
	static bool PhoneNumberDescendingCmp(ExpressCell* a, ExpressCell* b);
	//按快递柜编号降序排序
	static bool IndexDescendingCmp(ExpressCell* a, ExpressCell* b);
	//按入库时间从晚到早排序
	static bool TimeDescendingCmp(ExpressCell* a, ExpressCell* b);

	//位置复原排序,上面的排序都是只对含快递的格子排序。
	static bool ResetCmp(ExpressCell* a, ExpressCell* b);
};

