#include <iostream>
#include <Windows.h>
using namespace std;
int main() 
{

	//创建快递柜对象，查询子目录下的数据文件判断有没有已有的，有就读取数据
	//CraeteExpressTable();

	while (1) 
	{
		string op;
		cout << "主菜单" << endl;
		cout << "1.快递员" << endl << "2.取件人" << endl << "3.管理员" << endl << "0.结束" << endl;
		cin >> op;

		system("cls");
		if (op == "0") 
		{
			//save();
			return 0;
		}
		else if (op == "1") 
		{

			//Expressman();
			//save();
		}
		else if (op == "2") 
		{

			//Receiver();
			//save();
		}
		else if (op == "3") {

			//Administrator();
			//save();
		}
		else 
		{

			cout << "请输入正确的操作数！" << endl;
			Sleep(1000);//暂停0.5秒
			system("cls");
			continue;
		}
	}
	return 0;
}