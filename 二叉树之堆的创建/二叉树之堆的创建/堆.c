#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int HPDataType;
typedef struct Heap//创建一个堆
{
	HPDataType* _a;//动态开辟的数组
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	hp->_a = malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	// 构建成堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

void AdjustDown(HPDataType* a, size_t n, size_t parent)//小堆
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出小的那个孩纸
		if (child + 1 < n && a[child + 1] < a[child])
			++child;

		// 孩纸小于父亲，则交换
		if (a[child] < a[parent])
		{
			Swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
