#include<iostream>
using namespace std;
//int n = 0;
//class A
//{
//public:
//	A()
//	{
//		++n;
//	}
//	A(const A& a)
//	{
//		++n;
//	}
//	static void Get()//静态成员函数，因为没有this指针，不访问非静态的成员
//	{
//		cout << n << endl;
//	}
//	void f2()//非静态成员函数可以调用静态成员函数
//	{
//		Get();//突破类域+访问限定符就可以访问，类里面是一个整体都在这类域中，类里面
//		//不受访问限定符限制
//	}
//private:
//	static int n;//这只是声明，不是属于某个对象，而是属于这个类，需要类外定义
//};
//int A::n = 0;
//A f1(A a)
//{
//	return a;
//}
//int main()
//{
//	//staic成员
//	//设计出一个类，可以计算出这个；类产生了多少个对象
//	A a1;
//	A a2;
//	f1(a1);//传参产生一个,返回值产生一个，如果都用引用就不产生临时对象了
//	f1(a2);
//
//	//突破类域访问的两种方式，编译可以知道到哪个域找+访问限定符是否可以访问
//	a2.Get();
//	A::Get();
//	return 0;
//}
class Date;//前置声明
class Time
{
public:
	friend Date;
private:
	int _hour = 0;
	int _minute = 1;
	int _second = 1;
};
class Date
{
public:
	//友元函数
	friend void f(const Date& d);
	
	friend ostream& operator<<(ostream& out, const Date& d);//防止this指针抢占第一个参数的位置
	//{
	//	out << _year << "/" << _month << "/" << _day << endl;
	//}
	friend istream& operator>>(istream& in, Date& d);//d对象不能再const因为输入的时候会对对象产生修改
	void Print()
	{
		cout << _year << _month << _day << _t._hour << endl;
	}
private:
	//C++11声明时给缺省值
	int _year = 0;
	int _month = 1;
	int _day = 1;
	Time _t;
	static int _n;
};
int Date::_n = 0;

ostream& operator<<(ostream& out,const Date& d)
{
	out << d._year << "/" << d._month << "/" <<d._day << endl;
	return out;//支持连续输出
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year>>d._month>>d._day;
	return in;
 }

void f(const Date& d)
{
	cout << d._year << endl;
}
int main()
{
	Date d;
	f(d);
	/*d.operator<<(cout);
	d << cout;*/
	int i = 99;

	cin >> d;
	cout << d;
	return 0;
}