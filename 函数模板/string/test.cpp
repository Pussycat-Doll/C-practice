#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<typename T>
//template<class T>函数模板类似于一个模具，在使用时被参数化，根据实参类型产生函数的特定类型版本。
//模板的推演和实例化
//如果模板和现成的同时存在，那么就用现成的

void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}
template<typename M>
M ADD(M x1, M x2)
{
	return x1 + x2;
}
int main()
{
	int a = 10;
	int b = 11;
	Swap(a, b);
	double c = 10.01, d = 11.11;
	Swap(c, d);
	Swap(a,(int)d);
	cout << a <<" "<< d << endl;
	
	system("pause");
	return 0;
}

////typedef int DateType;
////类模板
//template <class T>
//class Vector
//{
//public:
//	void Pushback(const T& x);
//private:
//	T* _arr;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//
//	Vector<int> vc;
//	vc.Pushback(2);	
//
//	Vector<double> vcpp;
//	vcpp.Pushback(2.098);
//
//	system("pause");
//	return 0;
//}
