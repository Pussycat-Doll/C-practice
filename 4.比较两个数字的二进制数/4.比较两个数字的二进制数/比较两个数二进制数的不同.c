#define _CRT_SECURE_NO_WARNINGS 1
//4.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num1 = 0;
	int num2 = 0;
	int i = 0;
	int count = 0;
	scanf("%d%d", &num1, &num2);
	for (i = 0; i < 32; i++)
	{
		if (((num1 >> i) & 1) != ((num2 >> i) & 1))
			count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}