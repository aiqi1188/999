#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"globalFile.h"
#include<fstream>
#include<string>
#include<locale>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
class Manager :public Identity
{
public:

	Manager();
	Manager(string name, string pwd);
	//选择菜单
	virtual void operMenu();
	//添加账号 
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();
	//初始化容器
	void initVector();
	//初始化机房容器
	void initComVector();
	//学生容器
	vector<Student> vStu;
	//教师容器
	vector<Teacher> vTea;
	//机房容器
	vector<ComputerRoom>vCom;
	//检测重复
	bool checkRepeat(int id,int type);


};