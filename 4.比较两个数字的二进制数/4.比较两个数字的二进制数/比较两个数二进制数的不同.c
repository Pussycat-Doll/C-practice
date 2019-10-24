#define _CRT_SECURE_NO_WARNINGS 1
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num1 = 0;
	int num2 = 0;
	int i = 0;
	int count = 0;
	scanf("%d%d", &num1, &num2);
	for (i = 0; i < 32; i++)
	{
		if (((num1 >> i) & 1) != ((num2 >> i) & 1))
			count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}