#include "UIControl.h"
#include <iostream>
#include <Windows.h>
using namespace std;
void UIControl::ShowHome() 
{
	system("cls");
	cout << "��ӭʹ�ÿ�ݹ����ϵͳ��" << endl;
	cout << "���˵�" << endl;
	cout << "1.���Ա" << endl << "2.ȡ����" << endl << "3.����Ա" << endl << "4.UI��������" << endl << "0.����" << endl;
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
	while (1) {
		string cop;
		cout << "��ѡ�����屳����ɫ���ã�" << endl << "1.��ɫ������ɫ����" << endl << "2.��ɫ������ɫ����" << endl
			<< "3.��ɫ������ɫ���壨����ר�ã�" << endl << "4.��ɫ������ɫ���壨����ģʽ��" << endl;
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