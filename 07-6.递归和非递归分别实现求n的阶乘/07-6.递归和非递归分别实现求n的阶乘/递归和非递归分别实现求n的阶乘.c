#define _CRT_SECURE_NO_WARNINGS 1
//6.递归和非递归分别实现求n的阶乘
//递归
#include<stdio.h>
#include<stdlib.h>
int factorial(int n)
{
	if (n < 2)
		return 1;
	else
		return n*factorial(n - 1);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n",factorial(n));
	system("pause");
	return 0;
}
//非递归
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num = 0;
	int sum = 0;
	int i = 1;
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		sum += i;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}