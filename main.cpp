#include <iostream>
#include <Windows.h>
#include "UIControl.h"
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
			//Expressman();
			//save();
		}
		else if (op == "2") 
		{
			cout << "取件人";
			//Receiver();
			//save();
		}
		else if (op == "3") 
		{
			cout << "管理员";
			//Administrator();
			//save();
		}
		else if (op == "4") 
		{
			string cop;//选择界面颜色
			while (1) {
				cout << "请选择字体背景颜色设置：" << endl << "1.白色背景红色字体" << endl << "2.黑色背景白色字体" << endl << "3.紫色背景黄色字体（猛男专用）" << endl;
				cout << "4.绿色背景黑色字体（护眼模式）" << endl;
				cin >> cop;
				if (cop == "1")
				{
					system("color 74");
					system("cls");
					cout << "设置成功！";
					Sleep(1000);
					system("cls");
					break;
				}
				else if (cop == "2")
				{
					system("color 07");
					system("cls");
					cout << "设置成功！";
					Sleep(1000);
					system("cls");
					break;
				}
				else if (cop == "3")
				{
					system("color 56");
					system("cls");
					cout << "设置成功！";
					Sleep(1000);
					system("cls");
					break;
				}
				else if (cop == "4")
				{
					system("color 20");
					system("cls");
					cout << "设置成功！";
					Sleep(1000);
					system("cls");
					break;
				}
				else {
					system("cls");
					cout << "请输入正确的操作数！";
					Sleep(1000);
					system("cls");
				}
			}
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