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
	//int &b = a;//b��cΪade ����
	//int &c = a;
	//c = 20;//a\b\cͬʱ�����ı�
	/*int a = 10;
	int &b;
	b = a;*///��������ӣ������ڶ����ʱ������ʼ����
	//int &r = 10;//10��һ���������޷��޸�,����ľͶ��ˡ�
	//ָ������õĸ�ֵ��Ȩ��ֻ����С�����ܷŴ�
	const int& r = 10;
	const int &s = a;
	array(5) = 20;
	cout << array(5) << endl;
	system("pause");
	return 0;
}