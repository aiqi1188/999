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
	//Ĭ�Ϲ���
	Student();
	//�вι���(ѧ�š�����������)
	Student(int id, string nmae, string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancalOrder();
	//ѧ��ѧ��
	int m_Id;
	string m_Pwd;
	//��������
	vector<ComputerRoom> vCom;

};