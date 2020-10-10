//#include<iostream>
//using namespace std;//C++库中所有东西都是放到std命名空间里面的
//
//int main()
//{
//	std::cout << "Hello world" << std::endl;
//	int i = 99;
//	std::cout << i;
//}
//using std::cout;
//using std::endl;
////常用的库里面的一些对象或者类型可以展出来
////工程项目中推荐这样去做
//int main()
//{
//	int i, d;
//	cout << "hello world" << endl;
//	std::cin >> i >> d;
//	cout << i << " " << d<<endl;
//}
//#include<iostream>
//using namespace std;
//
//void Func(int c = 10)//缺省参数相等于备胎，如果传参了就用传的参数
//{
//	cout << c << endl;
//}
//
////全缺省
//void Func1(int a = 10, int b = 80, int c = 999)
//{
//	cout << "a = "<<a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
////半缺省(缺省部分参数)必须从右往左连续缺省
//void Func2(int a, int b = 880, int c = 9999)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	Func();
//	Func(999);
//	Func1();
//	Func1(1,2);
//	//传参的时候，必须从左往右传参
//	Func2(2);
//	return 0;
//}
//#include<iostream>
//using namespace std;
////函数重载要求：函数名相同，参数的类型/个数/类型的顺序不同
//int Add(int a, int b)
//{
//	return a + b;
//}
//int Add(int a, int b, int c)
//{
//	return a + b + c;
//} 
//double Add(double a, double b)
//{
//	return a + b;
//}
//long Add(long a, long b)
//{
//	return a + b;
//}
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1, 2, 3) << endl;
//	cout << Add(1.1, 2.2) << endl;
//	cout << Add(10L, 20L) << endl;
//
//	return 0;
//}
//面试问题：
//1、什么是函数重载
//2、C++是如何支持函数重载的？为什么C语言不支持

//预处理->展开头文件、宏替换、条件编译、去掉注释
//test.i
//编译->检查语法、生成汇编代码
//test.s
//汇编->汇编代码转成二进制的机器码
//test.o
//链接->将两个目标文件链接到一起
//生成可执行程序.exe文件

//extern关键字
//在C程序中使用
//C++实现打包并且编译成动态库或者静态库时
//要用extern "C"
//在C++中使用时，包其所在的头文件就可
//为什么呢？因为C中不包括C++的命名规则

//函数命名修饰规则

//引用
//#include<iostream>
//using namespace std;
//int main()
//{
//	//int a = 99;
//	//int& ra = a;//表示ra是a的别名,共用一块空间
//	//cout << "a = " << a << &a << endl;
//	//cout << "ra = " << ra << &ra << endl;
//	/*1、引用必须在定义的时候初始化
//	  2、一个变量可以有多个引用
//	  3、引用一旦引用一个实体，就不能引用其他实体*/
//
//	//常引用
//	const int a = 99;
//	//int& b = a;//编译不通过，原因：a是只读，b是可读可写的
//	const int& b = a;
//
//	int c = 100;
//	int& d = c;
//	const int& e = c;//c 是可读可写，e是只读
//	//总结：变量的权限只可以缩小，不能扩大
//
//	int i = 0;
//	double db = i;//隐式类型转换
//	const double& rd = i;
//	// 隐式类型转换产生了一个double的临时变量
//	//rd 引用的就是临时变量，临时变量具有常性
//
//	const int x = 99;
//	int y = x;//y的修改不影响x,这是一个普通的赋值的过程
//
//	int h = 89;
//	const int gg = h;//道理同上
//
//	//权限的缩小只适用引用和指针
//
//	/*const int* cp1 = &a;
//	int* p1 = cp1;*///不能通过编译，属于权限的放大
//
//	int* p2 = &h;
//	const int* cp2 = p2;//属于权限的缩小
//
//	return 0; 
//}

//引用的使用场景：1、作参数
//				  2、引用作返回值

//#include<iostream>
//using namespace std;
//
//void swap_c(int *p1, int *p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 1,b = 99;
//	swap_c(&a, &b);
//	swap(a,b);
//	return 0;
//}

#include<iostream>
using namespace std;

int Count1()//传值返回
{
    static int n = 0;
    n++;

    return n;
    //临时变量会多开一块空间
}

int& Count2()//传引用返回
{
    static int m = 0;
    m++;

    return m;
    //临时变量是m的别名，不会再开一块空间
}

int main()
{
    //int& r1 = Count1();编译不通过，Count1的返回值会产生一个临时变量，具有常性，是只读的
    const int& r1 = Count1();
    int& r2 = Count2();//Count2的返回值返回的是n的别名，是可读可写的，权限没有发生改变
    return 0;
 }
//
