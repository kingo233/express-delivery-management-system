#include <iostream>
#include <Windows.h>
using namespace std;
int main() 
{

	//������ݹ���󣬲�ѯ��Ŀ¼�µ������ļ��ж���û�����еģ��оͶ�ȡ����
	//CraeteExpressTable();

	while (1) 
	{
		string op;
		cout << "���˵�" << endl;
		cout << "1.���Ա" << endl << "2.ȡ����" << endl << "3.����Ա" << endl << "0.����" << endl;
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

			cout << "��������ȷ�Ĳ�������" << endl;
			Sleep(1000);//��ͣ0.5��
			system("cls");
			continue;
		}
	}
	return 0;
}