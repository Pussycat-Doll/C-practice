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
		//*it1 = 99;//set不允许修改
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	//输出结果为：1 2 3 4 5 6

	set<int>::reverse_iterator it2 = s.rbegin();
	while (it2 != s.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
	//输出结果为：6 5 4 3 2 1

	auto pos = s.find(5);
	if (pos != s.end())
	{
		s.erase(5);
		//s.erase(pos);

	}
	else
		cout << "没有该值，无法删除\n";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	//输出结果为：1 2 3 4 6
}
void test_map_set2()
{
	//map<string, string> dict;
	//dict.insert(pair<string, string>("insert", "插入"));
	//dict.insert(pair<string, string>("left", "左边"));
	//dict.insert(pair<string, string>("right", "右边"));
	//dict.insert(pair<string, string>("node", "结点"));
	//dict.insert(pair<string, string>("apple", "苹果"));
	//dict["sort"] = "排序";

	//string str;
	//while (cin >> str)
	//{
	//	auto e = dict.find(str);
	//	if (e != dict.end())
	//		cout << str << "---" << (*e).second << endl;
	//	else
	//		cout << "非法词汇\n";
	//}
	
	//string strs[] = { "香蕉", "橘子", "香蕉", "橙子", "菠萝", "哈密瓜", "橙子" };
	//map<string, int> count_fruit;
	//for (auto e : strs)
	//{
	//	auto pos = count_fruit.find(e);
	//	if (pos != count_fruit.end())
	//		//(*pos).second++;
	//		pos->second++;
	//	else
	//		//count_fruit.insert(pair<string, int>(e, 1));调用构造函数，创造匿名对象
	//		count_fruit.insert(make_pair(e, 1));
	//	//实际上相当于
	//	//template<class K,class T>
	//	//inline make_pair(const K&k,const T&t)
	//	//{
	//	//	return pair<K,T>(k,t);
	//	//}
	//}

	string strs[] = { "香蕉", "橘子", "香蕉", "橙子", "菠萝", "哈密瓜", "橙子" };
	map<string, int> count_fruit;
	for (auto e : strs)
	{
		pair<map<string, int>::iterator, bool> ret = count_fruit.insert(make_pair(e, 1));
		if (ret.second == false)//插入失败，表示该值已存在
			ret.first->second++;
	}

	string strs[] = { "香蕉", "橘子", "香蕉", "橙子", "菠萝", "哈密瓜", "橙子" };
	map<string, int> count_fruit;
	for (auto e : strs)
	{
		count_fruit[e]++;
		
	}
	/*[]的底层实现
	V& operator[](const K&k)//插入加修改(存在进行修改，不存在进行插入)
	{
		pair<iterator, bool> ret = insert(make_pair(k, V()));//如果不存在，插入K;如果存在，插入失败，没有影响
		return ret.first->second;
	}*/
}