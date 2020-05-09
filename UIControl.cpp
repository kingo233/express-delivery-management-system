#include "UIControl.h"
#include <iostream>
#include <Windows.h>
using namespace std;
void UIControl::ShowHome() 
{
	system("cls");
	cout << "欢迎使用快递柜管理系统！" << endl;
	cout << "主菜单" << endl;
	cout << "1.快递员" << endl << "2.取件人" << endl << "3.管理员" << endl << "4.UI界面设置" << endl << "0.结束" << endl;
}
void UIControl::ShowExpressMan()
{

}
void UIControl::ShowReceiver() 
{

}
void UIControl::ShowAdminstrator() 
{

}
void UIControl::ShowUISetting() 
{
	system("cls");
	cout << "请选择字体背景颜色设置：" << endl << "1.白色背景红色字体" << endl << "2.黑色背景白色字体" << endl
		<< "3.紫色背景黄色字体（猛男专用）" << endl << "4.绿色背景黑色字体（护眼模式）" << endl;
	
}
