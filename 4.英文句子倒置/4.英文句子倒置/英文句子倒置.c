#define _CRT_SECURE_NO_WARNINGS 1
//4.
//��һ���ַ����������Ϊ:"student a am i",
//			���㽫��������ݸ�Ϊ"i am a student".
//			Ҫ��
//			����ʹ�ÿ⺯����
//			ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//			student a am i
//			i am a student
//˼·���Ȱ����������ٰ�ÿ����������
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int length(char str[])//�ж��ַ������ȡ�
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
void reverse(char* str, char* end)//�����ַ�����
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
	reverse(str, str+len-1);//������ת
	while (*str)
	{
		char* start = str;
		while (*str != '\0' && *str != ' ')//��ȡ���ʵĽ���
		{
			str++;
		}
		reverse(start, str - 1);//������ת
		while (*str == ' ')//�ƶ�����һ�����ʵ���ʼλ��
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