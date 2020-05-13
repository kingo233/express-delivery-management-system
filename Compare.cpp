#include "Compare.h"
#include<iostream>
using namespace std;
bool Compare::CompanyNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.Timer == 0) return false;
	else if (b.Timer == 0) return true;
	return a.Express.CompanyName < b.Express.CompanyName;
}
bool Compare::OwnerNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.Timer == 0) return false;
	else if (b.Timer == 0) return true;
	return a.Express.OwnerName < b.Express.OwnerName;
}
bool Compare::PhoneNumerAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.Timer == 0) return false;
	else if (b.Timer == 0) return true;
	return a.Express.PhoneNumber < b.Express.PhoneNumber;
}
bool Compare::IndexAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.Timer == 0) return false;
	else if (b.Timer == 0) return true;
	return a.Index < b.Index;
}
bool Compare::TimeAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.Timer == 0) return false;
	else if (b.Timer == 0) return true;
	return a.Timer < b.Timer;
}
bool Compare::CompanyNameDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.Timer == 0) return false;
	else if (a.Timer == 0) return true;
	return a.Express.CompanyName > b.Express.CompanyName;
}
bool Compare::OwnerNameDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.Timer == 0) return false;
	else if (a.Timer == 0) return true;
	return a.Express.OwnerName > b.Express.OwnerName;
}
bool Compare::PhoneNumerDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.Timer == 0) return false;
	else if (a.Timer == 0) return true;
	return a.Express.PhoneNumber > b.Express.PhoneNumber;
}
bool Compare::IndexDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.Timer == 0) return false;
	else if (a.Timer == 0) return true;
	return a.Index >  b.Index;
}
bool Compare::TimeDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.Timer == 0) return false;
	else if (a.Timer == 0) return true;
	return a.Timer > b.Timer;
}
