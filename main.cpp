#include <iostream>
#include <Windows.h>
#include "CharacterControl.h"
#include "ExpressTable.h"
using namespace std;
int main() 
{
	//创建快递柜对象，查询子目录下的数据文件判断有没有已有的，有就读取数据
	ExpressTable Table;

	//加载UI界面设置
	CharacterControl::UISettingLoad();


	while (1) 
	{
		system("cls");
		cout << "欢迎使用快递柜管理系统！" << endl;
		cout << "主菜单" << endl;
		cout << "1.快递员" << endl << "2.取件人" << endl << "3.管理员" << endl << "4.UI界面设置" << endl << "0.结束" << endl;

		string op;
		getline(cin,op);

		if (op == "0")
		{
			Table.Save();
			return 0;
		}
		else if (op == "1")
		{
			CharacterControl::ExpressMan(Table);
			Table.Save();
		}
		else if (op == "2")
		{
			CharacterControl::Receiver(Table);
			Table.Save();
		}
		else if (op == "3")
		{
			CharacterControl::Adminstrator(Table);
			Table.Save();
		}
		else if (op == "4")
		{
			CharacterControl::UISetting();
		}
		else 
		{
			cout << "请输入正确的操作数！" << endl;
			//暂停1秒便于用户看清错误信息
			Sleep(1000);
			system("cls");
			continue;
		}
	}
	return 0;
}