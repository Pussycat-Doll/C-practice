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
//	static void Get()//��̬��Ա��������Ϊû��thisָ�룬�����ʷǾ�̬�ĳ�Ա
//	{
//		cout << n << endl;
//	}
//	void f2()//�Ǿ�̬��Ա�������Ե��þ�̬��Ա����
//	{
//		Get();//ͻ������+�����޶����Ϳ��Է��ʣ���������һ�����嶼���������У�������
//		//���ܷ����޶�������
//	}
//private:
//	static int n;//��ֻ����������������ĳ�����󣬶�����������࣬��Ҫ���ⶨ��
//};
//int A::n = 0;
//A f1(A a)
//{
//	return a;
//}
//int main()
//{
//	//staic��Ա
//	//��Ƴ�һ���࣬���Լ���������������˶��ٸ�����
//	A a1;
//	A a2;
//	f1(a1);//���β���һ��,����ֵ����һ��������������þͲ�������ʱ������
//	f1(a2);
//
//	//ͻ��������ʵ����ַ�ʽ���������֪�����ĸ�����+�����޶����Ƿ���Է���
//	a2.Get();
//	A::Get();
//	return 0;
//}
class Date;//ǰ������
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
	//��Ԫ����
	friend void f(const Date& d);
	
	friend ostream& operator<<(ostream& out, const Date& d);//��ֹthisָ����ռ��һ��������λ��
	//{
	//	out << _year << "/" << _month << "/" << _day << endl;
	//}
	friend istream& operator>>(istream& in, Date& d);//d��������const��Ϊ�����ʱ���Զ�������޸�
	void Print()
	{
		cout << _year << _month << _day << _t._hour << endl;
	}
private:
	//C++11����ʱ��ȱʡֵ
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
	return out;//֧���������
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