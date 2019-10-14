#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*写代码可以在整型有序数组中查找想要的数字， 
找到了返回下标，找不到返回-1.（折半查找） 
*/
int main()
{
	int k = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = left + (right - left) / 2;
	scanf("%d", &k);
	while (left <= right)
	{
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else 
		{
			printf("%d\n",mid);
			break;
		}
	}
	if (left > right)
	{
		printf("-1");
	}
	system("pause");
	return 0;
}
