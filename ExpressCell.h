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
	
	int Index;//��ݸ�ı��
	time_t Timer;//������ʱ��ʱ�䣬��time_t��������������
	char StrTime[50];//���ڵ��ַ�����������ʾ
	Express* ExpressPointer;//ָ���ݵ�ָ��

};



