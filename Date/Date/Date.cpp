# include"Date.h"



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

	/*Date d1(2020, 4, 25);
	Date d2(2020, 4, 25);

	d1 += 100;
	d1.print();
	d1 -= 100;
	d1.print();
	d1+= -100;
	d1.print();
	cout << d1 - d2 << endl;*/
	Date d3;
	const Date d4;
	cout << &d3 << endl;
	
	cout << &d4 << endl;

	Date d1(1);//构造
	Date d2 = 2;//隐式类型的转换 构造出tmp(2) + 再用tmp拷贝构造d2(tmp)+优化成直接构造
	Date d3 = d1;//拷贝构造函数
	//C++11的新语法
	Date d7 = { 2020,9,27 };

	int i = 1;
	double d = i;//隐式类型转换 中间产生临时对象(具有常性，可用引用来验证) double类型的res(i)
	//double& d = i;//这样就编译不通过，因为临时对象具有常性
	//防止隐式类型转换的产生在函数前面加上explicit
	//const double& d = i;//这样才可以，引用就是中间产生的临时对象
	
	
	return 0;
}