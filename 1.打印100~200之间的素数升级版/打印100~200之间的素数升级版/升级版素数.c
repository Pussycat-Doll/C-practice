#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	for (int i = 100; i <= 200; i++)
	{
		int j;
		for (j = 2; j < i/2; j++)//���� ����ֻ�ܱ�1������������������ 
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j > i/2)//�����ڼ䣬������If���һ��д��for��������˵���ѭ��һֱ���� 
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
