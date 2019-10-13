/*打印以下图形 
* 
*** 
***** 
******* 
********* 
*********** 
************* 
*********** 
********* 
******* 
***** 
*** 
* 
*/
#include<stdio.h>
int main()
{
	int i,j;
	for(i = 0;i < 7;i++)
	{
		for(j = 0;j < 2*i+1;j++)
		{
			printf("*");
		}
		printf("\n"); 
	}
	for(i = 5;i >= 0;i--)
	{
		for(j = 0;j < 2*i+1;j++)
		{
			printf("*");
		}
		printf("\n"); 
	}
	return 0;
}
