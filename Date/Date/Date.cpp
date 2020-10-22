# include<iostream>
using namespace std;

class Date
{
public:
	//Date(int year = 1900, int month = 1, int day = 1)//���캯��
	//	:_year(year)
	//	,_month(month)
	//	,_day(day)
	//{}
	Date(int year = 0, int month = 1, int day = 1)//���캯��
	{
		if (year >= 0 && month >= 0 && month <= 12 && day >= 1 && day <= getmonthday(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "������Ϊ�Ƿ�����"<<endl;
		}
	}
	Date(const Date& d)//�������캯��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//�������������Ϊ�����Զ�������һ��ȥʹ��
	Date& operator=(Date& d)//��ֵ����������
	{
		if (this != &d)//��ֹ�Լ������Լ������
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//ʹ�����÷�����Ϊ�˼���һ�δ�ֵ����(���ÿ�������)
	}
	bool islooneryear(int year)
	{
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
		//����һ���Ұ��겻�����400��һ��
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
	Date& operator+=(int days)
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
		//����
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
	Date& operator++()//ǰ��++
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
	Date operator++(int)//����++,Ϊ�˹��ɺ�������
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
	Date& operator--()//ǰ��--
	{
		*this -= 1;
		return *this;
	}
	Date operator--(int)//����--
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
	//���ھۣ������
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

	//d1 = d2;//���������Ѿ������ҳ�ʼ�����ˣ�������Ҫ��d2��ֵ(���ƿ���)��d1
	//Date d3(d1);//D3��������,����d3ʱ��d1ȥ��ʼ��
	//Date d4 = d1;//�ر�ע�⣬������õ��ǿ������죬��Ϊd4��������

	/*
	ǳ����(ֵ����)--��������һ��һ���ֽڿ���
	1�����ǲ�ʵ��ʱ�����������ɵ�Ĭ�Ϲ��캯����������������Գ�Ա��������������
	�Ͳ������Զ������ͻ���������Ա����Ĺ������������
	2�����ǲ�ʵ��ʱ�����������ɵĿ������캯���͸�ֵ����������أ��ͻ���ɰ����ֽڵ�ǳ����
	Ҳ����˵����Щ�࣬����Ҫ�����Լ�ȥʵ����Щ��������Ϊ������Ĭ�����ɾͿ�����
	*/
	//Date d1(2000, 4, 3);
	//d1.print();

	//Date d2(2000, 4, 8);
	//d2.print();

	//ǳ��������
	/*Stack st1(10);
	Stack st2(st1);*/
	//st2����free(_a)
	//st1����free(_a)
	//ͬһ��ռ䱻���������Σ����±�������Ҫ�Լ�ȥʵ������ľ�������

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