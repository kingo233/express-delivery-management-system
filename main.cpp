#include <iostream>
//#include"ExpressTable.h"
//#include"ExpressCell.h"
//#include"Compare.h"
//#include"Express.h"
using namespace std;
int main() {
	while (1) {
		int op;
		cout << "���˵�"<<endl;
		cout << "1.���Ա" << endl << "2.ȡ����" << endl << "3.����Ա" << endl<<"0.����"<<endl;
		cin >> op;
		if (op == 0) {
			system("cls");
			//save();
			return 0;
		}
		else if (op == 1) {
			system("cls");
			//Expressman();
			//save();
		}
		else if (op == 2) {
			system("cls");
			//Receiver();
			//save();
		}
		else if (op == 3) {
			system("cls");
			//Administrator();
			//save();
		}
		else {
			system("cls");
			cout << "�Ƿ�����"<<endl;
			continue;
		}
	}
	return 0;
}