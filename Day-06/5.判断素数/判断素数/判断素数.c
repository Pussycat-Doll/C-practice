#define _CRT_SECURE_NO_WARNINGS 1
/*实现一个函数，判断一个数是不是素数*/
#include<stdio.h>
#include<stdlib.h>
void prime_numbe(int input)
{
	int i = 0;
	for (i = 2; i < input; i++)
	{
		if (input%i == 0)
			break;
	}
	if (input == 1)
	{
		printf("1 不是素数");
	}
	else if (i == input)
	{
		printf("%d是素数\n");
	}
	else
	{
		printf("%d不是素数\n");
	}

}
int main()
{
	int input = 0;
	scanf("%d", &input);
	prime_numbe(input);
	system("pause");
	return 0;
}