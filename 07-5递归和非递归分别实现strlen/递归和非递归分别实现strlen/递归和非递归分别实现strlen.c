#define _CRT_SECURE_NO_WARNINGS 1
//5.递归和非递归分别实现strlen
//递归实现strlen
#include<stdio.h>
#include<stdlib.h>
int get_strlen(char* str)
{
	if (*str != '\0')
	{
		str++;
		return 1 + get_strlen(str);
	}
	else
	{
		return 0;
	}
}
int main()
{
	char str[100] = "0";
	scanf("%s", str);
	printf("%d\n",get_strlen(str));
	system("pause");
	return 0;
}
//非递归实现strlen
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char str[100];
	scanf("%s", str);
	int len = 0;
	int i = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		len++;
	}
	printf("%d\n", len);
	system("pause");
	return 0;
}
