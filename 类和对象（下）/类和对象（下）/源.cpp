#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdlib>
using namespace std;
class Time
{
public:
	//Time(int hour = 0)
	//	:_hour(hour)
	//{
	//	cout << "Time()" << endl;
	//}
	Time(int hour = 0)
	{
		_hour = hour;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int day)
	{}
private:
	int _day;
	Time _t;//�Զ�������
};

class A
{
public:
	A(int a)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
	{
		cout << "A(const A& aa)" << endl;
	}
private:
	int _a;
};

int main()
{
	//Date d(1);
	A aa1(1);//����
	A aa2 = 3;//���� + �������� + �Ż�
	system("pause");
	return 0;
}