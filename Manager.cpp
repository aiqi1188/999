#include"Manager.h"
Manager::Manager()
{


}
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_mPwd = pwd;

	this->initVector();
	this->initComVector();

}
//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;

 }
//����˺� 
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	string fileName;
	string tip;
	string errorTip;
	
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ� ";
		errorTip = "ѧ���ظ�������������";

	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�������������";
	}
;
	ofstream ofs(fileName, ios::out || ios::app);
	ofs.imbue(locale(""));//ʹ��Ĭ�ϵı��뷽ʽANSI
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		
			if (ret)
			{
				cout << errorTip << endl;
			}
			else
			{
				break;
			}

	}
	

	cout << "������������ " << endl;
	cin >> name;
	
	cout << "���������룺  " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
	 
	ofs.close();
	this->initVector();

}
void Manager::initVector()
{
	ifstream ifs(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;

	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);

	}
	cout << "��ǰѧ��������Ϊ��" << vStu.size() << endl;
	ifs.close();

	 ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;

	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ������Ϊ��" << vTea.size() << endl;
	ifs.close();

}
void Manager::initComVector()
{
	ifstream ifs(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;

	}
	vCom.clear();
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ" << vCom.size() << endl;

	ifs.close();

}
//����ظ�
bool Manager::checkRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin();
			it != vStu.end(); it++)
		{
			if (id == it-> m_Id )
				return true;
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin();
			it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
				return true;
		}
	}
	return false;

}
//�鿴�˺�
void printStudent(Student & s)
	{
		cout<< "ѧ�ţ� " <<s.m_Id << " ������ " 
			<< s.m_Name << " ���룺" << s.m_Pwd << endl;
	}

void printTeacher(Teacher& t)
{
	cout << "ְ���ţ� " << t.m_EmpId << " ������ "
		<< t.m_Name << " ���룺" << t.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int select = 0;
	cin >> select;

	

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2)
	{
		cout << "������ʦ��Ϣ���£� " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");

}
//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ����" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin()
		; it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId <<"   "
			"�������������" << it->m_MaxNum << endl;

	}
	system("pause");
	system("cls");

}
//���ԤԼ��¼
void Manager::cleanFile()
{
	cout << "ȷ��Ҫ�����" << endl;
	cout << "ȷ������1" << endl;
	cout << "��������2" << endl;
	int put = 0;
	cin >> put;
	if (put == 1)
	{
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "��ճɹ���" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		system("pause");
		system("cls");

	}
}