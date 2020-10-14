//#include<iostream>
//using namespace std;
//
//
//class Student
//{
//	//成员函数（方法）成员函数如果在类中定义，
//	//编译器可能会将其当成内联函数处
//public:
//	void ShowInfor()
//	{
//		cout << _age << endl;
//		cout << _name << endl;
//		cout << _stuid << endl;
//	}
//	int GetAGe()
//	{
//		return _age;
//	}
//private:
//	char _name[10];//成员变量一般情况都是比较隐私的,被定义成私有或者保护
//	int _age;
//	int _stuid;
//	 	 
//};
////struct的默认限定符是Public
////class默认是公有的
////int main()
////{
////	Student s1;
////	Student s2;
////	//s1._age = 19;
////	cout << s1.GetAGe() << endl;
////	return 0;
////}
////1、C语言中struct是用来定义结构体的
////2、C++中，兼容C的struct定义结构体的用法，但是同时struct也可用来定义类
//
////定义一个数据结构栈的类
//class Stack
//{
//public:
//	void Init(size_t n);
//	void Destory();
//	void Push(int x)//类里面定义
//	{
//
//	}
//	void Pop();//类内定义，类外声明
//	bool empty();
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//void Stack::Pop()//类外定义
//{
//
//}
////如何定义出一个类
////封装：1、将数据和方法定义到一起
////		2、把想给你看的给你看，不想给你看的封装起来(访问限定符public private protected)
///*
//1.声明和定义的区别？
//声明是一种承诺，但是实际上还没做
//定义就是把这个事情已经落地了
//*/
//int main()
//{
//
//	//类实例化出对象,相当于定义出了类的成员变量
//	Stack s1;
//	Stack s2;
//	Stack s3;
//	//s1._a = nullptr;不能访问
//	s1.Push(1);
//
//	cout << sizeof(s1) << endl;//对象中只存储类的成员变量,不存储类的成员函数
//	//因为每个对象的一个类可以实例化出多个对象，每个对象的成员变量可以存储不同的
//	//的值，但是调用的函数确实是同一个
//	//如果每个对象都放成员函数，而这些成员函数却是一样的，这是很浪费空间的
//	//如何计算一个类实例化出的对象的大小---计算成员变量之和，并且考虑内存对齐规则
//
//	//复习内存对齐
//	//没有成员变量的类的大小是1，为什么不是0
//	//开一个字节不是为了存数据，而是为了表示对象存在
//	return 0;
//}

/*
实例化就是用自己定义的类型定义出对象
1、内置类型
2、自定义类型
*/
#include<iostream>
using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;//cout<<this->_a<<endl;
//	}
//	void Show()
//	{
//		cout << "show()" <<endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;
//	p->Print();//程序崩溃
//	p->Show();//正常运行
//	/*
//	调用show函数的时候，传的this指针是一个空指针，但是在函数中并没有访问this指针
//	而在Print函数中，实际上访问了this指针，而该指针为空，所以发生了程序崩溃
//	*/
//	return 0;
//}
class Time
{
private:
	int _hour;
	int _minute;
	int _second;

};
class Date
{
public:
//	void Init(int year, int month, int day)//void Init(Date* this,int year,int month,int day)
//	{
///*this->*/_year = year;
//		_month = month;
//		_day = day;
//	}
	//Date(int year, int month, int day)//构造函数，与类名相同，可以重载，完成初始化，无返回值
	//	//实例化时自动调用
	//	//如果类中没有显示定义构造函数，则C++编译器会生成默认的构造函数
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	/*双标：
	1、针对内置类型的成员变量没有做处理
	2、针对自定义类型的成员变量，调用它的构造函数初始化
	*/
	/*Date()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}*/
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//无参的和全缺省的构造函数只能有一个
	/*
	默认的构造函数--》1、自己实现的无参的构造函数
					  2、自己实现的全缺省的构造函数
					  3、编译器自动生成的
	*/
	void Print()//void Print(Date* this)
		//谁调用这个函数，输就是this指针s
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	/*
	this存在哪个地方储存
	存在栈上的，因为它是一个形参(vs下是在ecx这个寄存器上的)
	*/
private:
	int _year;
	int _month;
	int _day;

	//Time t;

};
int main()
{
	Date d2;

	d2.Print();
	return 0;
}