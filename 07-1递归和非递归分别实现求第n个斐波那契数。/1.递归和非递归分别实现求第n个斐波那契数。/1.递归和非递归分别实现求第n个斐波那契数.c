#define _CRT_SECURE_NO_WARNINGS 1
//1.递归和非递归分别实现求第n个斐波那契数。
#include<stdio.h>
#include<stdlib.h>
int fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}
int main()
{
	//int arr[100] = { 0 };
	//int num = 0;
	//int n = 0;
	//int i = 0;
	//scanf("%d", &n);
	//for (i = 1; i <= n; i++)
	//{
	//	if (i == 1 || i == 2)
	//	{
	//		arr[i] = 1;
	//	}
	//	else
	//	{
	//		arr[i] = arr[i - 2] + arr[i - 1];
	//	}
	//}
	//num = arr[n];
	//printf("%d\n", num);
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", fib(n));
	system("pause");
	return 0;
}