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
	Time _t;//自定义类型
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
	A aa1(1);//构造
	A aa2 = 3;//构造 + 拷贝构造 + 优化
	system("pause");
	return 0;
}