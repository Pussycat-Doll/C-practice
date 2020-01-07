#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdlib>
using namespace std;
int& array(int i)
{
	static int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	return a[i];
}
//int array(int i)
//{
//	 int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	return a[i];
//}
int main()
{
	int a = 10;
	//int &b = a;//b、c为ade 别名
	//int &c = a;
	//c = 20;//a\b\c同时发生改变
	/*int a = 10;
	int &b;
	b = a;*///错误的例子，引用在定义的时候必须初始化。
	//int &r = 10;//10是一个常量，无法修改,下面的就对了。
	//指针和引用的赋值：权限只能缩小，不能放大。
	const int& r = 10;
	const int &s = a;
	array(5) = 20;
	cout << array(5) << endl;
	system("pause");
	return 0;
}