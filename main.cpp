#include <iostream>
#include <Windows.h>
#include "UIControl.h"
#include "CharacterControl.h"
using namespace std;
int main() 
{

	//������ݹ���󣬲�ѯ��Ŀ¼�µ������ļ��ж���û�����еģ��оͶ�ȡ����
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
			cout << "���Ա";
			CharacterControl::ExpressMan();
			//save();
		}
		else if (op == "2")
		{
			cout << "ȡ����";
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
			cout << "��������ȷ�Ĳ�������" << endl;
			Sleep(1000);//��ͣ1��
			system("cls");
			continue;
		}
	}
	return 0;
}