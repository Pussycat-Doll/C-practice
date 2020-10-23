#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	//Date(int year = 1900, int month = 1, int day = 1)//���캯��
	//	:_year(year)
	//	,_month(month)
	//	,_day(day)//��ʼ����˳����������˳���й�
	//{}
	Date(int year = 0, int month = 1, int day = 1)//���캯��,��ʼ���б�
		//���ú�const��Ա��û��Ĭ�Ϲ��캯�����Զ������ͳ�Ա�����ڳ�ʼ���б��г�ʼ��
		//��ʼ���б��Ƕ���ĳ�Ա��������ĵط�
		:_year(year),
		_month(month),
		_day(day)
	{
			if (year >= 0 && month >= 0 && month <= 12 && day >= 1 && day <= getmonthday(year, month))
			{
				_year = year;
				_month = month;
				_day = day;
			}
			else
			{
				cout << "������Ϊ�Ƿ�����" << endl;
			}
	}
	//�������������Ϊ�����Զ�������һ��ȥʹ��
	Date& operator=(const Date& d);//��ֵ����������
	bool islooneryear(int year);
	int getmonthday(int year, int month);
	Date operator+(int days)const;
	Date& operator+=(int days);	
	Date operator-(int days)const;
	Date& operator-=(int days);
	int operator-(const Date& d)const;	
	Date& operator++();//ǰ��++
	Date operator++(int);//����++,Ϊ�˹��ɺ�������
	Date& operator--();//ǰ��--	
	Date operator--(int);//����--
	bool operator>(const Date& d)const;
	bool operator==(const Date& d)const;	
	//���ھۣ������
	bool operator<(const Date& d)const;
	bool operator!=(const Date& d)const;	
	bool operator<=(const Date& d)const;
	bool operator>=(const Date& d)const;	
	//ʲôʱ��Ӧ�ø���Ա������const��ֻҪ��Ա�����в���Ҫ�޸ĳ�Ա������ö�����const
	Date* operator&();
	const Date* operator& ()const;
	void print()const;
private:
	int _year;
	int _month;
	int _day;
};

//Date::Date(int year, int month, int day)//���캯��
//{
//	if (year >= 0 && month >= 0 && month <= 12 && day >= 1 && day <= getmonthday(year, month))
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	else
//	{
//		cout << "������Ϊ�Ƿ�����" << endl;
//	}
//}


Date& Date::operator=(const Date& d)//��ֵ����������
{
	if (this != &d)//��ֹ�Լ������Լ������
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;//ʹ�����÷�����Ϊ�˼���һ�δ�ֵ����(���ÿ�������)
}

bool Date::islooneryear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	//����һ���Ұ��겻�����400��һ��
}

int Date::getmonthday(int year, int month)
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

Date Date::operator+(int days)const
{
	//Date d1(*this);
	//d1._day += days;
	//while (d1._day > d1.getmonthday(d1._year,d1._month))//�ж��·��Ƿ���Ҫ��λ
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

Date& Date::operator+=(int days)
{
	if (days < 0)
		return *this -= (-days);
	_day += days;
	while (_day > getmonthday(_year, _month))//�ж��·��Ƿ���Ҫ��λ
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

Date Date::operator-(int days)const
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
		//����
	Date d1(*this);
	d1 += days;
	return d1;
}

Date& Date::operator-=(int days)
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

int Date::operator-(const Date& d)const
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (d > * this)
	{
		max = d;//operator =
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}
Date& Date::operator++()//ǰ��++
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

Date Date::operator++(int)//����++,Ϊ�˹��ɺ�������
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

Date& Date::operator--()//ǰ��--
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)//����--
{
	Date d1(*this);
	*this -= 1;
	return d1;
}
bool Date::operator>(const Date& d)const
{
	return (!(*this <= d));
}
bool Date::operator==(const Date& d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}
//���ھۣ������
bool Date::operator<(const Date& d)const
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
bool Date::operator!=(const Date& d)const
{
	return (!(*this == d));
}
bool Date::operator<=(const Date& d)const
{
	return (*this < d || *this == d);
}
bool Date::operator>=(const Date& d)const
{
	return (!(*this < d));
}
Date* Date::operator&()
{
	cout << "Date* operator&()" << endl;
	return this;
}
const Date* Date::operator& ()const
{
	cout << "const Date* operator& ()const" << endl;
	return this;
}
void Date::print()const
//const * this,����*this���������ݲ��ܱ��ı�
{
	cout << _year << "-" << _month << "-" << _day << endl;
}


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
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};