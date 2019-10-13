#include<stdio.h>
int main()
{
	int sum = 0;
	int a = 1; 
	for(int i = 1;i < 101;i++)
	{
		sum += a/i;
		a = -a;
	}
	printf("%d",sum); 
	return 0;
}
