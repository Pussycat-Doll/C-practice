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
	//无参的和全缺省的不能同时存在
	//默认构造函数-编译器自动生成的、无参的、全缺省的
	~Date()
	{
		cout << "~Date" << this << endl;//先构造后析构，析构函数有且只有一个
	}
	
private:
	int _year;
	int _month;
	int _day;
	Time _t;
	//对于有自定义类型成员的，会调用它的构造函数和析构函数
};

class Stack
{
public:
	Stack(int n = 10)//对象创建时自动调用完成初始化工作
	{
		_a = (int*)malloc(sizeof(int) * n);
		_size = 0;
		_capacity = n;
	}
	~Stack()//对象生命周期到了之后，完成清理工作
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
	Date(const Date& d)//如果不用引用(即用传值构造会产生无穷递归)
		//const 是为了防止引用的对象内容被修改
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
	//自定义类型不能使用运算符，要用就得实现重载函数
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2020, 4, 21);
	Date d2(d1);//拷贝构造
	//Date d2 = d1;
	cout << (d1 == d2)<< endl;
	//d1.operator==(d2);
	return 0;

}