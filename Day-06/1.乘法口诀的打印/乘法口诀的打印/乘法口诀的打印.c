#define _CRT_SECURE_NO_WARNINGS 1
/*.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ���� 
����9�����9*9�ھ�������12�����12*12�ĳ˷��ھ��� 
*/
#include<stdio.h>
#include<stdlib.h>
void multiply(int row, int col)
{
	int a[20][20] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			a[i][j] = i*j;
		}
	}
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int row = 0;
	int col = 0;
	scanf("%d", &row);
	col = row;
	multiply(row, col);
	system("pause");
	return 0;
}
