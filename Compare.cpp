#include "Compare.h"
#include<iostream>
using namespace std;

//下面的排序是把timer不为0也就是快递格不为空的排到前面来

bool Compare::CompanyNameAscendingCmp(ExpressCell* a, ExpressCell* b) 
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	else if (strcmp(a->Express.CompanyName, b->Express.CompanyName) < 0) return true;
	else return false;
}
bool Compare::OwnerNameAscendingCmp(ExpressCell* a, ExpressCell* b) 
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	else if (strcmp(a->Express.OwnerName, b->Express.OwnerName) < 0) return true;
	else return false;
}
bool Compare::PhoneNumberAscendingCmp(ExpressCell* a, ExpressCell* b) 
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	else if (strcmp(a->Express.PhoneNumber, b->Express.PhoneNumber) < 0) return true;
	else return false;
}
bool Compare::IndexAscendingCmp(ExpressCell* a, ExpressCell* b) 
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	return a->Index < b->Index;
}
bool Compare::TimeAscendingCmp(ExpressCell* a, ExpressCell* b) 
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	return a->Timer < b->Timer;
}
bool Compare::CompanyNameDescendingCmp(ExpressCell* a, ExpressCell* b)
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	else if (strcmp(a->Express.CompanyName, b->Express.CompanyName) > 0) return true;
	else return false;
}
bool Compare::OwnerNameDescendingCmp(ExpressCell* a, ExpressCell* b)
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	else if (strcmp(a->Express.OwnerName, b->Express.OwnerName) > 0) return true;
	else return false;
}
bool Compare::PhoneNumberDescendingCmp(ExpressCell* a, ExpressCell* b)
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	else if (strcmp(a->Express.PhoneNumber, b->Express.PhoneNumber) > 0) return true;
	else return false;
}
bool Compare::IndexDescendingCmp(ExpressCell* a, ExpressCell* b)
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	return a->Index >  b->Index;
}
bool Compare::TimeDescendingCmp(ExpressCell* a, ExpressCell* b)
{
	if (a->Timer == 0) return false;
	else if (b->Timer == 0) return true;
	return a->Timer > b->Timer;
}

//下面的函数是让各个快递格回到原来的位置
bool Compare::ResetCmp(ExpressCell* a, ExpressCell* b) 
{
	return a->Index < b->Index;
}