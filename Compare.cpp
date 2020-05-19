#include "Compare.h"
#include<iostream>
using namespace std;
bool Compare::CompanyNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.Timer == 0) return false;
	else if (b.Timer == 0) return true;
	else if (strcmp(a.Express.CompanyName, b.Express.CompanyName) < 0) return true;
	else return false;
}
bool Compare::OwnerNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.Timer == 0) return false;
	else if (b.Timer == 0) return true;
	else if (strcmp(a.Express.OwnerName, b.Express.OwnerName) < 0) return true;
	else return false;
}
bool Compare::PhoneNumberAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.Timer == 0) return false;
	else if (b.Timer == 0) return true;
	else if (strcmp(a.Express.PhoneNumber, b.Express.PhoneNumber) < 0) return true;
	else return false;
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
	else if (strcmp(a.Express.CompanyName, b.Express.CompanyName) > 0) return true;
	else return false;
}
bool Compare::OwnerNameDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.Timer == 0) return false;
	else if (a.Timer == 0) return true;
	else if (strcmp(a.Express.OwnerName, b.Express.OwnerName) > 0) return true;
	else return false;
}
bool Compare::PhoneNumberDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.Timer == 0) return false;
	else if (a.Timer == 0) return true;
	else if (strcmp(a.Express.PhoneNumber, b.Express.PhoneNumber) > 0) return true;
	else return false;
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
bool Compare::ResetCmp(ExpressCell a, ExpressCell b) 
{
	return a.Index < b.Index;
}