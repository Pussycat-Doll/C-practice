#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int array[] = { 9, 2, 1, 6, 4, 3, 7, 0, 8, 5 };
	int size = sizeof(array) / sizeof(array[0]);
	int end = size;
	int i = 0;
	while (end > 1)
	{

		for (i = 0; i < end; i++)
		{
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
		end--;
	}
	for (i = 0; i < size; i++)
	{
		printf("%d\n", array[i]);
	}
	return 0;
}