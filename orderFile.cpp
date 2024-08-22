#include"orderFile.h"
OrderFile::OrderFile()
{
	ifstream ifs(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;

	while (ifs >> date && ifs >> interval &&
		ifs >> stuId && ifs >> stuName && ifs
		>> roomId && ifs >> status
		)
	{
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;*/
		map<string, string> m;
		string key;
		string value;
		int pos = date.find(":");
		for (int i = 0; i <= this->m_Size; i++) {
			if (pos != -1)
			{
				key = date.substr(0, pos);
				value = date.substr(pos + 1, date.size()
					- 1 - pos);
				m.insert(make_pair(key, value));
			}

			pos = interval.find(":");
			if (pos != -1)
			{
				key = interval.substr(0, pos);
				value = interval.substr(pos + 1, date.size()
					- 1 - pos);
				m.insert(make_pair(key, value));
			}

			pos = stuId.find(":");
			if (pos != -1)
			{
				key = stuId.substr(0, pos);
				value = stuId.substr(pos + 1, date.size()
					- 1 - pos);
				m.insert(make_pair(key, value));
			}

			pos = stuName.find(":");
			if (pos != -1)
			{
				key = stuName.substr(0, pos);
				value = stuName.substr(pos + 1, date.size()
					- 1 - pos);
				m.insert(make_pair(key, value));
			}
			pos = roomId.find(":");
			if (pos != -1)
			{
				key = roomId.substr(0, pos);
				value = roomId.substr(pos + 1, date.size()
					- 1 - pos);
				m.insert(make_pair(key, value));
			}

			pos = status.find(":");
			if (pos != -1)
			{
				key = status.substr(0, pos);
				value = status.substr(pos + 1, date.size()
					- 1 - pos);
				m.insert(make_pair(key, value));
			}

			this->m_orderData.insert(make_pair(this->m_Size, m));
			this->m_Size++;
		}
		/*or (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
				{
					cout << "key = " << it->first << " value = " << endl;
					for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
					{
						cout << mit->first << " " << mit->second << " ";
					}
					cout << endl;

				}*/
		//MapDiv(date, m);
		//MapDiv(interval, m);
		//MapDiv(stuId, m);
		//MapDiv(stuName, m);
		//MapDiv(roomId, m);
		//MapDiv(status, m);


		//this->m_orderData.insert(make_pair(this->m_Size, m));
		//this->m_Size++;

		
		ifs.close();
	}
}
//将找key和value的行为封装
//void OrderFile::MapDiv(string &s, map<string, string> m)
//{	
//		string key;
//		string value;
//		
//	int pos = s.find(":");
//	if (pos != -1)
//	{
//		key = s.substr(0, pos);
//		value = s.substr(pos + 1, s.size() - 1 - pos);
//		m.insert(make_pair(key, value));
//	}
//}


void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		cout << "没有预约" << endl;
		return;

	}
	ofstream ofs("ORDER_FILE0",
		ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << " ";
	}
	ofs.close();
}