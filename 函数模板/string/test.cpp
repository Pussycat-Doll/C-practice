#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<typename T>
//template<class T>����ģ��������һ��ģ�ߣ���ʹ��ʱ��������������ʵ�����Ͳ����������ض����Ͱ汾��
//ģ������ݺ�ʵ����
//���ģ����ֳɵ�ͬʱ���ڣ���ô�����ֳɵ�

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
////��ģ��
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
