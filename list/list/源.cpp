#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<list>
#include<algorithm>//find��ͷ�ļ�
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
	l.unique();//����ʱȥ��ΪO(N)
	//���������ַ�ʽ��������+��Χfor(�������±�)
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
		l.insert(pos, 99);//��λ��֮ǰ����
		l.erase(pos);
	}

	print_list(l);
}
/*
* ����vector��˵��insert��erase�����ܻᵼ�µ�����ʧЧ����
* ������list��˵��insert���ᵼ�µ�����ʧЧ������earse�ᵼ�µ�����ʧЧ
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

	list<int>::reverse_iterator rit1 = l1.rbegin();//�Ӻ���ǰ����
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
		//	l1.erase(it);//��ǰλ�ñ�ɾ�������ܶ������++����
		//	++it;//��Ϊ�������Ѿ�ʧЧ��
		if (*it % 2 == 0)
		{
			it = l1.erase(it);//ɾ��֮��ָ��������һ��λ��

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