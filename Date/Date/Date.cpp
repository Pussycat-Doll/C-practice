# include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)//构造函数
		:_year(year)
		,_month(month)
		,_day(day)
	{}
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
	bool islooneryear()
	{
		return ((_year % 4 == 0) || (_year % 400 == 0 && _year % 4 != 0));
	}
	int getmonthday()
	{
		switch (_month)
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
			if (islooneryear())
				return 29;
			else
				return 28;
			break;
		default:
			break;
		}
	}
	Date operator+(int days)
	{
		Date d1(*this);
		d1._day += days;
		while (d1._day > d1.getmonthday())//判断月份是否需要进位
		{
			d1._day -= getmonthday();
			++d1._month;
		}
		while (d1._month > 12)
		{
			d1._month -= 12;
			++d1._year;
		}
		return d1;
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
			d1._day = d1._day + d1.getmonthday() - days;
		}
	}
	int operator-(const Date& d);
	Date& operator++();//前置++
	Date operator++(int);//后置++
	Date& operator--();//前置--
	Date operator--(int);//后置--
	bool operator>(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator!=(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator>=(const Date& d)const;
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
	cout << d1.getmonthday() << endl;

	Date d2 = d1.operator+(27);
	d2.print();
	return 0;
}