#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdlib>
//using namespace std;//命名空间
//int main()
//{
//	//int printf = 10;
//	//printf("hello world\n");命名冲突，先考虑上面一句的局部变量。
//	//如何让解决这种冲突的发生呢？
//	system("pause");
//	return 0;
//}
/*命名空间三种使用方式：
  1.using nemaspace bit--访问便捷，但带来了命名污染（里面的都被放出来了）
  2.using bit::printf--指定放出某一个
  3.bit::printf--指定访问，但麻烦
  */
//命名空间可以嵌套
#include<iostream>
#include<cstdlib>
using namespace std;//C++标准库都放在std的命名空间中
namespace bit//->隔离
{
	int printf = 10;
	void strcpy()
	{
		cout << "hahahaha" << endl;
	}
}
//int main()
//{
//	printf("Hello :%d\n", bit::printf);
//	bit::strcpy();
//	system("pause");
//	return 0;
//}
using std::cin;
using std::cout;
using std::endl;
//int main()
//{	
//	//std::cout << "Hello World" << std::endl;
//	int i = 20;
//	float j = 3.14159;
//	int *p = &i;
//	cout << "Hello World" << endl;//IO流
//	cout << i << endl;
//	cout << j << endl;
//	cout << *p << endl;
//	cout << i << endl << j << endl;
//	system("pause");
//	return 0;
//}
void testfunc(int a = 100)
{
	cout << a << endl;
}
//全缺省
void testFunc1(int a = 100, int b = 20, int c = 5)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
//半缺省（只能从右向左）
void testFunc2(int a, int b = 20, int c = 5)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
//int main()
//{
//	testfunc();//没有参数时，使用默认参数。
//	testfunc(10);
//	testFunc1(1);
//	testFunc1(1,2);
//	testFunc1(1,2,3);
//	testFunc2(1);
//	system("pause");
//	return 0;
//}

//函数重载
/*为什么C语言不支持重载，C++支持重载？？
 *函数名修饰规则*/
void f(int i)
{

	printf("%d\n", i);
}
void f(double i)
{

	printf("%f\n", i);
}
int main()
{
	int i = 10;
	double d = 1.01;

	//cout << i;
	//cout.operator<<(i);

	//cout << d;
	//cout.operator<<(d);
	f(i);
	f(d);
	system("pause");
	return 0;
}
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{

	return 0;
}

