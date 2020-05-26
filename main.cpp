#include <iostream>
#include <Windows.h>
#include "CharacterControl.h"
#include "ExpressTable.h"
using namespace std;
int main() 
{
	//������ݹ���󣬲�ѯ��Ŀ¼�µ������ļ��ж���û�����еģ��оͶ�ȡ����
	ExpressTable Table;

	//����UI��������
	CharacterControl::UISettingLoad();


	while (1) 
	{
		system("cls");
		cout << "��ӭʹ�ÿ�ݹ����ϵͳ��" << endl;
		cout << "���˵�" << endl;
		cout << "1.���Ա" << endl << "2.ȡ����" << endl << "3.����Ա" << endl << "4.UI��������" << endl << "0.����" << endl;

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
			cout << "��������ȷ�Ĳ�������" << endl;
			//��ͣ1������û����������Ϣ
			Sleep(1000);
			system("cls");
			continue;
		}
	}
	return 0;
}