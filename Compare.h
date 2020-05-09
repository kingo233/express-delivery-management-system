#pragma once
#include "ExpressCell.h"


//�����õľ�̬�࣬���������ֹؼ��ֱȽϵĺ���
static class Compare
{
public:
	//����ݹ�˾������������
	bool CompanyNameAscendingCmp(ExpressCell a, ExpressCell b);
	//���ռ���������������
	bool OwnerNameAscendingCmp(ExpressCell a, ExpressCell b);
	//���ռ����ֻ�������������
	bool PhoneNumerAscendingCmp(ExpressCell a, ExpressCell b);
	//����ݹ�����������
	bool IndexAscendingCmp(ExpressCell a, ExpressCell b);
	//�����ʱ����絽������
	bool TimeAscendingCmp(ExpressCell a, ExpressCell b);


	//����ݹ�˾���ƽ�������
	bool CompanyNameDescendingCmp(ExpressCell a, ExpressCell b);
	//���ռ���������������
	bool OwnerNameDescendingCmp(ExpressCell a, ExpressCell b);
	//���ռ����ֻ����뽵������
	bool PhoneNumerDescendingCmp(ExpressCell a, ExpressCell b);
	//����ݹ��Ž�������
	bool IndexDescendingCmp(ExpressCell a, ExpressCell b);
	//�����ʱ�����������
	bool TimeDescendingCmp(ExpressCell a, ExpressCell b);
};

