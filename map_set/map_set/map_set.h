#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

void test_map_set1()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);
	set<int>::iterator it1 = s.begin();
	while (it1 != s.end())
	{
		//*it1 = 99;//set�������޸�
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	//������Ϊ��1 2 3 4 5 6

	set<int>::reverse_iterator it2 = s.rbegin();
	while (it2 != s.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
	//������Ϊ��6 5 4 3 2 1

	auto pos = s.find(5);
	if (pos != s.end())
	{
		s.erase(5);
		//s.erase(pos);

	}
	else
		cout << "û�и�ֵ���޷�ɾ��\n";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	//������Ϊ��1 2 3 4 6
}
void test_map_set2()
{
	//map<string, string> dict;
	//dict.insert(pair<string, string>("insert", "����"));
	//dict.insert(pair<string, string>("left", "���"));
	//dict.insert(pair<string, string>("right", "�ұ�"));
	//dict.insert(pair<string, string>("node", "���"));
	//dict.insert(pair<string, string>("apple", "ƻ��"));
	//dict["sort"] = "����";

	//string str;
	//while (cin >> str)
	//{
	//	auto e = dict.find(str);
	//	if (e != dict.end())
	//		cout << str << "---" << (*e).second << endl;
	//	else
	//		cout << "�Ƿ��ʻ�\n";
	//}
	
	//string strs[] = { "�㽶", "����", "�㽶", "����", "����", "���ܹ�", "����" };
	//map<string, int> count_fruit;
	//for (auto e : strs)
	//{
	//	auto pos = count_fruit.find(e);
	//	if (pos != count_fruit.end())
	//		//(*pos).second++;
	//		pos->second++;
	//	else
	//		//count_fruit.insert(pair<string, int>(e, 1));���ù��캯����������������
	//		count_fruit.insert(make_pair(e, 1));
	//	//ʵ�����൱��
	//	//template<class K,class T>
	//	//inline make_pair(const K&k,const T&t)
	//	//{
	//	//	return pair<K,T>(k,t);
	//	//}
	//}

	string strs[] = { "�㽶", "����", "�㽶", "����", "����", "���ܹ�", "����" };
	map<string, int> count_fruit;
	for (auto e : strs)
	{
		pair<map<string, int>::iterator, bool> ret = count_fruit.insert(make_pair(e, 1));
		if (ret.second == false)//����ʧ�ܣ���ʾ��ֵ�Ѵ���
			ret.first->second++;
	}

	string strs[] = { "�㽶", "����", "�㽶", "����", "����", "���ܹ�", "����" };
	map<string, int> count_fruit;
	for (auto e : strs)
	{
		count_fruit[e]++;
		
	}
	/*[]�ĵײ�ʵ��
	V& operator[](const K&k)//������޸�(���ڽ����޸ģ������ڽ��в���)
	{
		pair<iterator, bool> ret = insert(make_pair(k, V()));//��������ڣ�����K;������ڣ�����ʧ�ܣ�û��Ӱ��
		return ret.first->second;
	}*/
}