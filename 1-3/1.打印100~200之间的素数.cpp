#include<stdio.h>

int main()
{
	for(int i = 100; i <= 200; i++)
	{
		int j;
		for( j = 2; j < i; j++)//素数 就是只能被1和它本身整除的数； 
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(i == j)//做题期间，把两个If语句一起写到for语句里面了导致循环一直进行 
		{
			printf("%d\n",i);
		}
	}	
} 
