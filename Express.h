#pragma once
#include <string>
using namespace std;
class Express
{
public:
	Express();
	~Express();
	Express(string, string, string);


	//快递收件人手机号码
	string PhoneNumber;

	//收件人姓名
	string OwnerName;

	//快递公司名称
	string CompanyName;
};


