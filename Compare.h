#pragma once
#include "ExpressCell.h"


//�����õ��࣬���������ֹؼ��ֱȽϵĺ���
class Compare
{
public:
	//����ݹ�˾������������
	static bool CompanyNameAscendingCmp(ExpressCell a, ExpressCell b);
	//���ռ���������������
	static bool OwnerNameAscendingCmp(ExpressCell a, ExpressCell b);
	//���ռ����ֻ�������������
	static bool PhoneNumerAscendingCmp(ExpressCell a, ExpressCell b);
	//����ݹ�����������
	static bool IndexAscendingCmp(ExpressCell a, ExpressCell b);
	//�����ʱ����絽������
	static bool TimeAscendingCmp(ExpressCell a, ExpressCell b);


	//����ݹ�˾���ƽ�������
	static bool CompanyNameDescendingCmp(ExpressCell a, ExpressCell b);
	//���ռ���������������
	static bool OwnerNameDescendingCmp(ExpressCell a, ExpressCell b);
	//���ռ����ֻ����뽵������
	static bool PhoneNumerDescendingCmp(ExpressCell a, ExpressCell b);
	//����ݹ��Ž�������
	static bool IndexDescendingCmp(ExpressCell a, ExpressCell b);
	//�����ʱ�����������
	static bool TimeDescendingCmp(ExpressCell a, ExpressCell b);
};

