#include <iostream>
//#include"ExpressTable.h"
//#include"ExpressCell.h"
//#include"Compare.h"
//#include"Express.h"
using namespace std;
int main() {
	while (1) {
		int op;
		cout << "主菜单"<<endl;
		cout << "1.快递员" << endl << "2.取件人" << endl << "3.管理员" << endl<<"0.结束"<<endl;
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
			cout << "非法输入"<<endl;
			continue;
		}
	}
	return 0;
}