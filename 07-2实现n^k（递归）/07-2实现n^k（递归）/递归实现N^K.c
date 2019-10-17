#define _CRT_SECURE_NO_WARNINGS 1
//2.用函数实现n^k(递归实现)
#include<stdio.h>
#include<stdlib.h>
int power(int n, int k)
{
	if (n == 0)
		return 0;
	else if (k == 0)
		return 1;
	else
	{
		return n*power(n, k - 1);
	}

}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n,&k);
	printf("%d\n", power(n, k));
	system("pause");
	return 0;
}

