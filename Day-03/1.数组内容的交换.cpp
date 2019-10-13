//将数组A中的内容和数组B中的内容进行交换。（数组一样大） 
#include<stdio.h>
int main()
{
	int a[10],b[10],c[10];
	for(int i = 0;i < 10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 0;i < 10;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i = 0;i < 10;i++)
	{
		c[i] = a[i];
		a[i] = b[i];
		b[i] = c[i];
	}
	for(int i = 0;i < 10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i = 0;i < 10;i++)
	{
		printf("%d ",b[i]);
	}	
	return 0;
}
