#pragma once
#include<string>
#include "ExpressTable.h"
using namespace std;
class CharacterControl
{
public:
	static void ExpressMan(ExpressTable& Table);
	static void Receiver(ExpressTable& Table);
	static void Adminstrator(ExpressTable& Table);
	static void UISetting();
	static void UISettingSave(string color);
	static void UISettingLoad();
};

