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
		//菜单界面
		virtual void operMenu();
		//查看所有预约
	void showAllOrder();
		//审核预约
	void validorder();
	//教师编号
	int m_EmpId;
	string m_Pwd;
};
