#define _CRT_SECURE_NO_WARNINGS 1
//4.
//有一个字符数组的内容为:"student a am i",
//			请你将数组的内容改为"i am a student".
//			要求：
//			不能使用库函数。
//			只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//			student a am i
//			i am a student
//思路：先把整体逆序，再把每个单词逆序；
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int length(char str[])//判断字符串长度。
{
	char *p = str;
	int len = 0;
	while (*p != '\0')
	{
		len++;
		p++;
	}
	return len;
}
void reverse(char* str, char* end)//倒置字符串。
{
	while (str < end)
	{
		char temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
	}
}
void reverse_Words(char* str)
{
	int len = length(str);
	reverse(str, str+len-1);//整体逆转
	while (*str)
	{
		char* start = str;
		while (*str != '\0' && *str != ' ')//获取单词的结束
		{
			str++;
		}
		reverse(start, str - 1);//单词逆转
		while (*str == ' ')//移动到下一个单词的起始位置
		{
			++str;
		}
	}
}
int main()
{
	char str[100];
	gets(str);
	reverse_Words(str);
	printf("%s\n",str);
	return 0;
	system("pause");
}