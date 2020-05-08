#include "Compare.h"
#include<iostream>
using namespace std;
bool Compare::CompanyNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.ExpressPointer->CompanyName < b.ExpressPointer->CompanyName;
}
bool Compare::OwnerNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.ExpressPointer->OwnerName < b.ExpressPointer->OwnerName;
}
bool Compare::PhoneNumerAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.ExpressPointer->PhoneNumber < b.ExpressPointer->PhoneNumber;
}
bool Compare::IndexAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.Index < b.Index;
}
bool Compare::TimeAscendingCmp(ExpressCell a, ExpressCell b) 
{
	return a.Timer < b.Timer;
}
bool Compare::CompanyNameAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.ExpressPointer->CompanyName > b.ExpressPointer->CompanyName;
}
bool Compare::OwnerNameAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.ExpressPointer->OwnerName > b.ExpressPointer->OwnerName;
}
bool Compare::PhoneNumerAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.ExpressPointer->PhoneNumber > b.ExpressPointer->PhoneNumber;
}
bool Compare::IndexAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.Index >  b.Index;
}
bool Compare::TimeAscendingCmp(ExpressCell a, ExpressCell b)
{
	return a.Timer > b.Timer;
}
