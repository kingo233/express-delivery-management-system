#include <iostream>
#include <Windows.h>
#include "UIControl.h"
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
			//Expressman();
			//save();
		}
		else if (op == "2") 
		{
			cout << "ȡ����";
			//Receiver();
			//save();
		}
		else if (op == "3") 
		{
			cout << "����Ա";
			//Administrator();
			//save();
		}
		else if (op == "4") 
		{
			string cop;//ѡ�������ɫ
			while (1) {
				cout << "��ѡ�����屳����ɫ���ã�" << endl << "1.��ɫ������ɫ����" << endl << "2.��ɫ������ɫ����" << endl << "3.��ɫ������ɫ���壨����ר�ã�" << endl;
				cout << "4.��ɫ������ɫ���壨����ģʽ��" << endl;
				cin >> cop;
				if (cop == "1")
				{
					system("color 74");
					system("cls");
					cout << "���óɹ���";
					Sleep(1000);
					system("cls");
					break;
				}
				else if (cop == "2")
				{
					system("color 07");
					system("cls");
					cout << "���óɹ���";
					Sleep(1000);
					system("cls");
					break;
				}
				else if (cop == "3")
				{
					system("color 56");
					system("cls");
					cout << "���óɹ���";
					Sleep(1000);
					system("cls");
					break;
				}
				else if (cop == "4")
				{
					system("color 20");
					system("cls");
					cout << "���óɹ���";
					Sleep(1000);
					system("cls");
					break;
				}
				else {
					system("cls");
					cout << "��������ȷ�Ĳ�������";
					Sleep(1000);
					system("cls");
				}
			}
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