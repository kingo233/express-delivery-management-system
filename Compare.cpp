#include "Compare.h"
#include<iostream>
using namespace std;
bool Compare::CompanyNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.ExpressPointer == NULL) reutnr false;
	else if (b.ExpressPointer == NULL) return true;
	return a.ExpressPointer->CompanyName < b.ExpressPointer->CompanyName;
}
bool Compare::OwnerNameAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.ExpressPointer == NULL) reutnr false;
	else if (b.ExpressPointer == NULL) return true;
	return a.ExpressPointer->OwnerName < b.ExpressPointer->OwnerName;
}
bool Compare::PhoneNumerAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.ExpressPointer == NULL) reutnr false;
	else if (b.ExpressPointer == NULL) return true;
	return a.ExpressPointer->PhoneNumber < b.ExpressPointer->PhoneNumber;
}
bool Compare::IndexAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.ExpressPointer == NULL) reutnr false;
	else if (b.ExpressPointer == NULL) return true;
	return a.Index < b.Index;
}
bool Compare::TimeAscendingCmp(ExpressCell a, ExpressCell b) 
{
	if (a.ExpressPointer == NULL) reutnr false;
	else if (b.ExpressPointer == NULL) return true;
	return a.Timer < b.Timer;
}
bool Compare::CompanyNameDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.ExpressPointer == NULL) reutnr false;
	else if (a.ExpressPointer == NULL) return true;
	return a.ExpressPointer->CompanyName > b.ExpressPointer->CompanyName;
}
bool Compare::OwnerNameDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.ExpressPointer == NULL) reutnr false;
	else if (a.ExpressPointer == NULL) return true;
	return a.ExpressPointer->OwnerName > b.ExpressPointer->OwnerName;
}
bool Compare::PhoneNumerDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.ExpressPointer == NULL) reutnr false;
	else if (a.ExpressPointer == NULL) return true;
	return a.ExpressPointer->PhoneNumber > b.ExpressPointer->PhoneNumber;
}
bool Compare::IndexDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.ExpressPointer == NULL) reutnr false;
	else if (a.ExpressPointer == NULL) return true;
	return a.Index >  b.Index;
}
bool Compare::TimeDescendingCmp(ExpressCell a, ExpressCell b)
{
	if (b.ExpressPointer == NULL) reutnr false;
	else if (a.ExpressPointer == NULL) return true;
	return a.Timer > b.Timer;
}
