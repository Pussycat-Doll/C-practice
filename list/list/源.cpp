#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<list>
#include<algorithm>//find��ͷ�ļ�
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
	l.unique();//����ʱȥ��ΪO(N)
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
	l.insert(pos, 99);//��λ��֮ǰ����
	*pos = 100;
	//l.erase(pos);������ʧЧ
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