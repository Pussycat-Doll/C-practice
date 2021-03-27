#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<list>
#include<algorithm>//find的头文件
#include"list.h"
using namespace std;

void print_list(list<int>& l)
{
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}
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
	//遍历的两种方式：迭代器+范围for(不能用下标)
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
	list<int> ::iterator pos = find(l.begin(), l.end(), 90);
	if (pos != l.end())
	{
		l.insert(pos, 99);//在位置之前插入
		l.erase(pos);
	}

	print_list(l);
}
/*
* 对于vector来说，insert和erase都可能会导致迭代器失效问题
* 而对于list来说，insert不会导致迭代器失效，但是earse会导致迭代器失效
*/
void test3()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_front(-1);
	l1.push_front(-2);

	list<int>::reverse_iterator rit1 = l1.rbegin();//从后向前遍历
	while (rit1 != l1.rend())
	{
		cout << *rit1 << " ";
		++rit1;
	}
	cout << endl;
}
void test4()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_front(-1);
	l1.push_front(-2);
	l1.sort();
	print_list(l1);
}
void test5()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_front(-1);
	l1.push_front(-2);

	list<int> ::iterator it = l1.begin();
	while (it != l1.end())
	{
		//if (*it % 2 == 0)
		//	l1.erase(it);//当前位置被删除，不能对其进行++操作
		//	++it;//因为迭代器已经失效了
		if (*it % 2 == 0)
		{
			it = l1.erase(it);//删除之后指向它的下一个位置

		}
		else
			++it;
	}
	print_list(l1);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	mystl::test4();
	system("pause");
	return 0;
}