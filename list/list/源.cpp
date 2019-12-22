#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<list>
#include<algorithm>//find的头文件
using namespace std;
void test1()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(2);
	l.push_back(4);
	l.push_back(4);
	l.push_back(3);
	l.sort();
	l.unique();//有序时去重为O(N)
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test2()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(4);
	l.push_back(3);
	list<int> ::iterator pos = find(l.begin(), l.end(), 4);
	l.insert(pos, 99);//在位置之前插入
	*pos = 100;
	//l.erase(pos);迭代器失效
	cout << *pos << endl;
	for (auto e :l)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test3()
{

}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}