#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"globalFile.h"
#include"orderFile.h"
#include<vector>
class Teacher :public Identity
{
public:
	Teacher();
	Teacher(int empId, string name, string pwd);
		//�˵�����
		virtual void operMenu();
		//�鿴����ԤԼ
	void showAllOrder();
		//���ԤԼ
	void validorder();
	//��ʦ���
	int m_EmpId;
	string m_Pwd;
};
