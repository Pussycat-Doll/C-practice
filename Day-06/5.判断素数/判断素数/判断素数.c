#define _CRT_SECURE_NO_WARNINGS 1
/*ʵ��һ���������ж�һ�����ǲ�������*/
#include<stdio.h>
#include<stdlib.h>
void prime_numbe(int input)
{
	int i = 0;
	for (i = 2; i < input; i++)
	{
		if (input%i == 0)
			break;
	}
	if (input == 1)
	{
		printf("1 ��������");
	}
	else if (i == input)
	{
		printf("%d������\n");
	}
	else
	{
		printf("%d��������\n");
	}

}
int main()
{
	int input = 0;
	scanf("%d", &input);
	prime_numbe(input);
	system("pause");
	return 0;
}