#define _CRT_SECURE_NO_WARNINGS 1
//1.
//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	 ���� 1��λ�� 
//}
#include<stdio.h>
#include<stdlib.h>
int count_one_bits(unsigned int value)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((value>>i) & 1) == 1)
			count++;
	}
	return count;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n",count_one_bits(num));
	system("pause");
	return 0;
}
