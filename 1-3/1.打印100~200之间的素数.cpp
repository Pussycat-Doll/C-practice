#include<stdio.h>

int main()
{
	for(int i = 100; i <= 200; i++)
	{
		int j;
		for( j = 2; j < i; j++)//���� ����ֻ�ܱ�1������������������ 
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(i == j)//�����ڼ䣬������If���һ��д��for��������˵���ѭ��һֱ���� 
		{
			printf("%d\n",i);
		}
	}	
} 
