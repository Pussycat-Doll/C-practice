#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if(a%4 == 0&&a%100 != 0)
	{
		printf("%d������",a);
	}
	else if(a%400 == 0)
	{
		printf("%d������",a);
	}
	else  
	{
		printf("%d��������",a);
	}
	return 0;
}
