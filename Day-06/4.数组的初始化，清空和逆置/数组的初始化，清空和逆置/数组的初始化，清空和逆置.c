#define _CRT_SECURE_NO_WARNINGS 1
/*����һ�����飬 
ʵ�ֺ���init������ʼ�����顢 
ʵ��empty����������顢 
ʵ��reverse���������������Ԫ�ص����á� 
Ҫ���Լ���ƺ����Ĳ���������ֵ��*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void init(int arr[])
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
}
void empty(int arr[10])
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i]='\0';
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void reverse(int arr[10])
{
	int i = 0;
	int j = 0;
	int left = 0;
	int right = 10;
	for (i = 0; i < 5; i++)
	{
		do
		{
			j = arr[i];
			arr[i] = arr[9 - i];
			arr[9 - i] = j;
			left++;
			right--;
		} while (left < right);
		
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10] = { 0 };
	init(arr);
	reverse(arr);
	empty(arr);
	system("pause");
	return 0;
}