//编写程序数一下 1到 100 的所有整数中出现多少次数字9
#include<stdio.h>
int main()
{
	int n = 0;
	for(int i = 1;i < 100;i++)
	{
		if(i%10 == 9)//个位数 。 
		{
			n ++;
		}
		 else if(i%100/10 == 9)//十位数。 
		{
			n ++;
		}	
	}
	printf("%d",n);
	return 0;
}
