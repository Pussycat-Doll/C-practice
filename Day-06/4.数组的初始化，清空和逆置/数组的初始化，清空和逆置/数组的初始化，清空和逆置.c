#define _CRT_SECURE_NO_WARNINGS 1
/*创建一个数组， 
实现函数init（）初始化数组、 
实现empty（）清空数组、 
实现reverse（）函数完成数组元素的逆置。 
要求：自己设计函数的参数，返回值。*/
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