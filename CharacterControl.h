#pragma once
#include<string>
#include "ExpressTable.h"
using namespace std;
class CharacterControl
{
public:
	static void ExpressMan(ExpressTable& Table);
	static void Receiver();
	static void Adminstrator();
	static void UISetting();
	static void UISettingSave(string color);
};

