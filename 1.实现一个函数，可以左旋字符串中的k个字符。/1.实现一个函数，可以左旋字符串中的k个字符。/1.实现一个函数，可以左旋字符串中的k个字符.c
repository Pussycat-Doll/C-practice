#define _CRT_SECURE_NO_WARNINGS 1
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rotate_String(char str[])//����һ���֡�
{
	char temp = str[0];
	int len = strlen(str);
	int i = 0;
	for (i = 0; i < len - 1; i++)
	{
		str[i] = str[i + 1];
	}
	str[len - 1] = temp;
}
void move(char str[], int k)
{
	while (k)
	{
		rotate_String(str);
		k--;
	}
	printf("%s\n", str);
}
int main()
{
	char str[100];
	int k = 0;
	gets(str);
	scanf("%d", &k);
	move(str, k);
	system("pause");
	return 0;
}