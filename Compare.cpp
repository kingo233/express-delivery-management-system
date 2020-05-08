#include "Compare.h"
#include"Express.h"
#include<iostream>
using namespace std;
bool Compare::CompanyNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.CompanyName < b.CompanyName;
}
bool Compare::OwnerNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.OwnerName < b.OwnerName;
}
bool Compare::PhoneNumerAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.PhoneNumber < b.PhoneNumber;
}
bool Compare::IndexAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.Index < b.Index;
}
bool Compare::TimeAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.Time < b.Timer;
}
bool Compare::CompanyNameAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.CompanyName > b.CompanyName;
}
bool Compare::OwnerNameAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.OwnerName > b.OwnerName;
}
bool Compare::PhoneNumerAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.PhoneNumber > b.PhoneNumber;
}
bool Compare::IndexAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.Index > b.Index;
}
bool Compare::TimeAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.Time > b.Timer;
}
