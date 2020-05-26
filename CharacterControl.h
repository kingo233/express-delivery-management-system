#pragma once
#include<string>
#include "ExpressTable.h"
using namespace std;
class CharacterControl
{
public:
	//快递员的角色函数，是快递柜放入快递功能与外界交互的接口
	static void ExpressMan(ExpressTable& Table);

	//收件人的角色函数，是快递柜取出快递功能与外界交互的接口
	static void Receiver(ExpressTable& Table);

	//管理员的角色函数，是快递柜展示功能与外界交互的接口，同时也包含密码管理和日志查询功能
	static void Adminstrator(ExpressTable& Table);

	//用户界面手动设置函数
	static void UISetting();
	//用户界面设置保存函数，用于保存用户自定义界面设置，参数为用户输入的代码字符串
	static void UISettingSave(string color);
	//用户界面设置加载函数，该函数时系统自动调用的
	static void UISettingLoad();

	//验证密码是否正确的函数，通过读文件比较字符串完成
	static bool IsPasswordCorrect();
	//设置密码的函数，写文件
	static void PasswordSet();
	//读取日志，读文件
	static void ReadLog();

	//判断用户输入的颜色设置代码是否合法
	static inline bool IsOperatorCorrect(char c);
};

