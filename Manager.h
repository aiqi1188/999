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
	//ѡ��˵�
	virtual void operMenu();
	//����˺� 
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();
	//��ʼ������
	void initVector();
	//��ʼ����������
	void initComVector();
	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;
	//��������
	vector<ComputerRoom>vCom;
	//����ظ�
	bool checkRepeat(int id,int type);


};