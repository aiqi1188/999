#pragma once
#include<iostream>
#include"Identity.h"
#include<string>
#include"computerRoom.h"
#include<vector>
#include<fstream>
#include"globalFile.h"
#include<map>
#include"orderFile.h"
class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参构造(学号、姓名、密码)
	Student(int id, string nmae, string pwd);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看我的预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancalOrder();
	//学生学号
	int m_Id;
	string m_Pwd;
	//机房容器
	vector<ComputerRoom> vCom;

};