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
	Date& operator=(Date& d)//赋值操作符重载
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
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
	}
	Date operator+(int days)
	{
		Date d1(*this);
		d1._day += days;
		while (d1._day > d1.getmonthday(d1._year,d1._month))//判断月份是否需要进位
		{
			d1._day -= getmonthday(d1._year,d1._month);
			++d1._month;
			if (d1._month == 13)
			{
				d1._month = 1;
				++d1._year;
			}
		}
		return d1;
	}
	Date& operator+=(int days)
	{
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
		Date d1(*this);
		if (d1._day > days)
		{
			d1._day -= days;
			return d1;
		}
		while (d1._day <= days)
		{
			--d1._month;
			d1._day = d1._day + d1.getmonthday(_year,_month) - days;
		}
	}
	int operator-(const Date& d);
	Date& operator++();//前置++
	Date operator++(int);//后置++
	Date& operator--();//前置--
	Date operator--(int);//后置--
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
int main()
{
	Date d1(2000, 2, 3);



	return 0;
}