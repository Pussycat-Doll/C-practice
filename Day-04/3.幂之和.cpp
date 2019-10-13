//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
#include<stdio.h>
#include<math.h>
int main()
{
	int a,n,i;
	int num = 0;
	int sum = 0;
	scanf("%d %d",&a,&n);
	for( i = 1; i <= n; i++)
	{
		num = num*10+a;
		sum += num;	
	}
	printf("sum = %d\n",sum);
	
	return 0;
}
