#pragma once
#include<string>
#include "ExpressTable.h"
using namespace std;
class CharacterControl
{
public:
	//���Ա�Ľ�ɫ�������ǿ�ݹ�����ݹ�������罻���Ľӿ�
	static void ExpressMan(ExpressTable& Table);

	//�ռ��˵Ľ�ɫ�������ǿ�ݹ�ȡ����ݹ�������罻���Ľӿ�
	static void Receiver(ExpressTable& Table);

	//����Ա�Ľ�ɫ�������ǿ�ݹ�չʾ��������罻���Ľӿڣ�ͬʱҲ��������������־��ѯ����
	static void Adminstrator(ExpressTable& Table);

	//�û������ֶ����ú���
	static void UISetting();
	//�û��������ñ��溯�������ڱ����û��Զ���������ã�����Ϊ�û�����Ĵ����ַ���
	static void UISettingSave(string color);
	//�û��������ü��غ������ú���ʱϵͳ�Զ����õ�
	static void UISettingLoad();

	//��֤�����Ƿ���ȷ�ĺ�����ͨ�����ļ��Ƚ��ַ������
	static bool IsPasswordCorrect();
	//��������ĺ�����д�ļ�
	static void PasswordSet();
	//��ȡ��־�����ļ�
	static void ReadLog();

	//�ж��û��������ɫ���ô����Ƿ�Ϸ�
	static inline bool IsOperatorCorrect(char c);
};

