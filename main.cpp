#include <iostream>
#include <Windows.h>
using namespace std;
int main() 
{

	//������ݹ���󣬲�ѯ��Ŀ¼�µ������ļ��ж���û�����еģ��оͶ�ȡ����
	//CraeteExpressTable();
	cout << "��ӭʹ�ÿ�ݹ����ϵͳ��";
	Sleep(1000);//��ͣ1s
	system("cls");
	while (1) 
	{
		string op;
		cout << "���˵�" << endl;
		cout << "1.���Ա" << endl << "2.ȡ����" << endl << "3.����Ա" << endl << "4.UI��������" << endl << "0.����" << endl;
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