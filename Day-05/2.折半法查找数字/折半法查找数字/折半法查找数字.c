#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*д����������������������в�����Ҫ�����֣� 
�ҵ��˷����±꣬�Ҳ�������-1.���۰���ң� 
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
