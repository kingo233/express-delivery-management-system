#include <iostream>
#include <Windows.h>
#include "CharacterControl.h"
#include "ExpressTable.h"
using namespace std;
int main() 
{

	//创建快递柜对象，查询子目录下的数据文件判断有没有已有的，有就读取数据
	ExpressTable Table;
	cout << "欢迎使用快递柜管理系统！" << endl;
	UISettingLoad();
	while (1) 
	{
		system("cls");
		cout << "主菜单" << endl;
		cout << "1.快递员" << endl << "2.取件人" << endl << "3.管理员" << endl << "4.UI界面设置" << endl << "0.结束" << endl;
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
			CharacterControl::ExpressMan(Table);
			//save();
		}
		else if (op == "2")
		{
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