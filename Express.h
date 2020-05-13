#pragma once
#include <string>
using namespace std;
class Express
{
public:
	Express();
	~Express();


	//快递收件人手机号码
	char PhoneNumber[20];

	//收件人姓名
	char OwnerName[10];

	//快递公司名称
	char CompanyName[20];
};


