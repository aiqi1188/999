#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<map>
#include<fstream>

class OrderFile
{
public:
	//���캯��
	OrderFile();
	//����ԤԼ��¼
	void updateOrder();
	//��¼������
	//   key --- ��¼������ 
	//  value --- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>>m_orderData;
//	void MapDiv(string& s, map<string, string> m);

	//ԤԼ��¼����
	int m_Size ;

};