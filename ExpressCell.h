#pragma once
#include <string>
#include <ctime>
#include "Express.h"
using namespace std;

//��ʾһ����ݸ�
class ExpressCell
{
public:
	ExpressCell();
	~ExpressCell();

	//��ݸ�ı��
	int Index;

	//������ʱ��ʱ�䣬��time_t��������������
	time_t Timer;

	//���ڵ��ַ�����������ʾ
	char StrTime[50];

	//��һ����ݹ���
	Express Express;

};



