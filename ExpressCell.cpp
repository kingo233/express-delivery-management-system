#include "ExpressCell.h"
#include <cstdio>
ExpressCell::ExpressCell() :Index(0), Timer(0), StrTime(""), Express()
{

}
ExpressCell::~ExpressCell() 
{

}

void ExpressCell::PrintInfo()
{
	//��ʽ����ӡ��Ϣ
	printf("%-4s  %-11s  %-10s%s\n", Express.OwnerName, Express.PhoneNumber, Express.CompanyName, StrTime);
}
