#define _CRT_SECURE_NO_WARNINGS 1
//3.在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[100][100];
	int i = 0;
	int j = 0;
	int num = 0;
	scanf("%d", &num);
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (i = 0; i < num; i++)
	{
		arr[i][0] = 1;
	}
	for (i = 1; i < num; i++)
	{
		for (j = 1; j < i+1; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < i+1; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
