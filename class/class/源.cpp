#include<iostream>
using namespace std;
/*class Time
{
public:
	Time()
	{
		cout << "Time" << this << endl;
	}
	~Time()
	{
		cout << "~Time" << this << endl;
	}
private:
	int _hour;
	int _minnute;
	int _second;
};
class Date
{
public:
	/*Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date" << this << endl;
	}
	//�޲εĺ�ȫȱʡ�Ĳ���ͬʱ����
	//Ĭ�Ϲ��캯��-�������Զ����ɵġ��޲εġ�ȫȱʡ��
	~Date()
	{
		cout << "~Date" << this << endl;//�ȹ����������������������ֻ��һ��
	}
	
private:
	int _year;
	int _month;
	int _day;
	Time _t;
	//�������Զ������ͳ�Ա�ģ���������Ĺ��캯������������
};

class Stack
{
public:
	Stack(int n = 10)//���󴴽�ʱ�Զ�������ɳ�ʼ������
	{
		_a = (int*)malloc(sizeof(int) * n);
		_size = 0;
		_capacity = n;
	}
	~Stack()//�����������ڵ���֮�����������
	{
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
	}
	void Push(int x);
	void Pop();
	size_t  Size();
private:
	int* _a;
	int _size;
	int _capacity;
};
int main()
{
	Date d2(2020,02, 02);
	//Stack st;
	return 0;
}*/
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 0)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)//�����������(���ô�ֵ������������ݹ�)
		//const ��Ϊ�˷�ֹ���õĶ������ݱ��޸�
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator== (const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		else
			return false;
	}
	bool operator> (const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;
		else
			return false;
	}
	//�Զ������Ͳ���ʹ���������Ҫ�þ͵�ʵ�����غ���
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2020, 4, 21);
	Date d2(d1);//��������
	//Date d2 = d1;
	cout << (d1 == d2)<< endl;
	//d1.operator==(d2);
	return 0;

}