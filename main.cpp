#include <iostream>
#include <Windows.h>
#include "UIControl.h"
#include "CharacterControl.h"
using namespace std;
int main() 
{

	//创建快递柜对象，查询子目录下的数据文件判断有没有已有的，有就读取数据
	//CraeteExpressTable();
	
	while (1) 
	{
		UIControl::ShowHome();
		string op;
		cin >> op;
		system("cls");
		if (op == "0")
		{
			//save();
			return 0;
		}
		else if (op == "1")
		{
			cout << "快递员";
			CharacterControl::ExpressMan();
			//save();
		}
		else if (op == "2")
		{
			cout << "取件人";
			CharacterControl::Receiver();
			//save();
		}
		else if (op == "3")
		{
			CharacterControl::Adminstrator();
			//save();
		}
		else if (op == "4")
		{
			CharacterControl::UISetting();
		}
		else 
		{
			cout << "请输入正确的操作数！" << endl;
			Sleep(1000);//暂停1秒
			system("cls");
			continue;
		}
	}
	return 0;
}