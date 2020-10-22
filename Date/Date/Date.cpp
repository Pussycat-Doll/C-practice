# include<iostream>
using namespace std;

class Date
{
public:
	//Date(int year = 1900, int month = 1, int day = 1)//构造函数
	//	:_year(year)
	//	,_month(month)
	//	,_day(day)
	//{}
	Date(int year = 0, int month = 1, int day = 1)//构造函数
	{
		if (year >= 0 && month >= 0 && month <= 12 && day >= 1 && day <= getmonthday(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "该日期为非法日期"<<endl;
		}
	}
	Date(const Date& d)//拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//运算符的重载是为了像自定义类型一样去使用
	Date& operator=(Date& d)//赋值操作符重载
	{
		if (this != &d)//防止自己传给自己的情况
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//使用引用返回是为了减少一次传值拷贝(调用拷贝构造)
	}
	bool islooneryear(int year)
	{
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
		//四年一润且百年不润或者400年一润
	}
	int getmonthday(int year, int month)
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		case 2:
			if (islooneryear(year))
				return 29;
			else
				return 28;
			break;
		}
		return 0;
	}
	Date operator+(int days)
	{
		//Date d1(*this);
		//d1._day += days;
		//while (d1._day > d1.getmonthday(d1._year,d1._month))//判断月份是否需要进位
		//{
		//	d1._day -= getmonthday(d1._year,d1._month);
		//	++d1._month;
		//	if (d1._month == 13)
		//	{
		//		d1._month = 1;
		//		++d1._year;
		//	}
		//}
		//return d1;
		Date d1(*this);
		d1 += days;
		return d1;
	}
	Date& operator+=(int days)
	{
		if (days < 0)
			return *this -= (-days);
		_day += days;
		while (_day > getmonthday(_year, _month))//判断月份是否需要进位
		{
			_day -= getmonthday(_year, _month);
			++_month;
			if (_month == 13)
			{
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	Date operator-(int days)
	{
	/*	Date d1(*this);
		d1._day -= days;
		while (d1._day <= 0)
		{
			--d1._month;
			if (d1._month == 0)
			{
				d1._month = 12;
				--d1._year;
			}
			d1._day = d1._day + d1.getmonthday (_year,_month);
			
		}
		return d1;*/
		//复用
		Date d1(*this);
		d1 += days;
		return d1;
	}
	Date& operator-=(int days)
	{
		if (days < 0)
			return *this += (-days);
		_day -= days;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				_month = 12;
				--_year;
			}
			_day = _day + getmonthday(_year, _month);

		}
		return *this;
	}
	int operator-(const Date& d);
	Date& operator++()//前置++
	{
		/*++_day;
		if (_day > getmonthday(_year, _month))
		{
			++_month;
			_day = 1;
		}
		if (_month == 13)
		{
			_month = 1;
			++_year;
		}
		return *this;*/
		* this += 1;
		return *this;
	}
	Date operator++(int)//后置++,为了构成函数重载
	{
		Date d1(*this);
		/*++_day;
		if (_day > getmonthday(_year, _month))
		{
			++_month;
			_day = 1;
		}
		if (_month == 13)
		{
			_month = 1;
			++_year;
		}*/
		* this += 1;
		return d1;

	}
	Date& operator--()//前置--
	{
		*this -= 1;
		return *this;
	}
	Date operator--(int)//后置--
	{
		Date d1(*this);
		*this -= 1;
		return d1;
	}
	bool operator>(const Date& d)const
	{
		return (!(*this <= d));
	}
	bool operator==(const Date& d)const
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	//高内聚，低耦合
	bool operator<(const Date& d)const
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		else
			return false;
	}
	bool operator!=(const Date& d)const
	{
		return (!(*this == d));
	}
	bool operator<=(const Date& d)const
	{
		return (*this < d || *this == d);
	}
	bool operator>=(const Date& d)const
	{
		return (!(*this < d));
	}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

class Stack
{
public:
	Stack(int n)
	{
		_a = (int*)malloc(sizeof(int) * n);
		_size = 0;
		_capacity = n;
	}
	~Stack()
	{
		free (_a);
		_a = nullptr;
		_size = _capacity = 0;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};
int main()
{
	//Date d1(2000, 4, 3);
	//d1.print();

	//Date d2(2000, 4, 8);
	//d2.print();

	//d1 = d2;//两个对象都已经存在且初始化好了，现在需要把d2赋值(复制拷贝)给d1
	//Date d3(d1);//D3还不存在,构造d3时用d1去初始化
	//Date d4 = d1;//特别注意，这里调用的是拷贝构造，因为d4还不存在

	/*
	浅拷贝(值拷贝)--将对象按照一个一个字节拷贝
	1、我们不实现时，编译器生成的默认构造函数和析构函数，针对成员变量，内置类型
	就不处理，自定义类型会调用这个成员对象的构造和析构函数
	2、我们不实现时，编译器生成的拷贝构造函数和赋值运算符的重载，就会完成按照字节的浅拷贝
	也就是说，有些类，不需要我们自己去实现这些函数，因为编译器默认生成就可以用
	*/
	//Date d1(2000, 4, 3);
	//d1.print();

	//Date d2(2000, 4, 8);
	//d2.print();

	//浅拷贝问题
	/*Stack st1(10);
	Stack st2(st1);*/
	//st2析构free(_a)
	//st1析构free(_a)
	//同一块空间被析构了两次，导致崩溃，需要自己去实现深拷贝的具体内容

	/*Stack st3(30);
	st1 = st3;*/

	Date d1(2020, 4, 25);
	d1 += 100;
	d1.print();
	d1 -= 100;
	d1.print();
	d1+= -100;
	d1.print();
	return 0;
}