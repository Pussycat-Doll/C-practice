//��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9
#include<stdio.h>
int main()
{
	int n = 0;
	for(int i = 1;i < 100;i++)
	{
		if(i%10 == 9)//��λ�� �� 
		{
			n ++;
		}
		 else if(i%100/10 == 9)//ʮλ���� 
		{
			n ++;
		}	
	}
	printf("%d",n);
	return 0;
}
