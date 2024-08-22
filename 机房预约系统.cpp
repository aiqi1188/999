#include<iostream>
#include"Identity.h"
#include"globalFile.h"
#include"student.h"
#include"Manager.h"
#include"teacher.h"
#include<fstream>
#include<string>
#include"orderFile.h"
using namespace std;
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)//�鿴�˺�
		{
			//cout << "����˺�" << endl;
			man->addPerson();

		}
		else if (select == 2)//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();

		}
		else if (select == 3)//�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();


		}
		else if(select==4)
		{
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void studentMenu(Identity*& student)
{
	while (true)
	{
		//ѧ���˵�
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancalOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();

		}
		else if (select == 2)
		{
			tea->validorder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		}

	}

}
void LogginIn(string filename, int type)
{
	Identity* person = NULL;
	ifstream ifs(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;

	}
	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			/*cout << fId << endl;
			cout << fName << endl;
			cout << fPwd << endl;*/



			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
				
			}
		}
	}
	else if (type == 2)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher (id, name, pwd);
				return;
			}
		}
		//��ʦ��¼��֤
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string fName;
		string  fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;

			}
		}
	}
	cout<< "��֤��¼ʧ��!" << endl;
	system("pause");
	system("cls");
	return;

}

int main()
{


	while(true)
	{ 

		int select = 0;
	cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
		<< endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";
	cin >> select;
	switch (select)
	{

	case 1:
		LogginIn(STUDENT_FILE, 1);
		break;
	case 2:
		LogginIn(TEACHER_FILE, 2);
		break;
	case 3:
		LogginIn(ADMIN_FILE, 3);
		break;
	case 0:
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		return 0;
		break;
	default:
		cout<<"��������������ѡ��"<<endl;
		system("pause");
		system("cls");
		break;


	}

}
	system("pause");

	return 0;
	

}