#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数判断year是不是闰年。
#include<stdio.h>
#include<stdlib.h>
void leapyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		printf("%d是闰年\n", year);
	}
	else if (year % 400 == 0)
	{
		printf("%d是闰年\n", year);
	}
	else
	{
		printf("%d不是闰年\n", year);
	}
}
int main()
{
	int year;
	scanf("%d", &year);
	leapyear(year);
	system("pause");
	return 0;
}
