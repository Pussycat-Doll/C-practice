#define _CRT_SECURE_NO_WARNINGS 1
//ʵ��һ�������ж�year�ǲ������ꡣ
#include<stdio.h>
#include<stdlib.h>
void leapyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		printf("%d������\n", year);
	}
	else if (year % 400 == 0)
	{
		printf("%d������\n", year);
	}
	else
	{
		printf("%d��������\n", year);
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
