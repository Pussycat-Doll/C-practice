#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"heap.h"
void swap(HPDatatype*p1, HPDatatype* p2)
{
	HPDatatype temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void AdjustDown(HPDatatype* a, size_t n, size_t parent)//向下调整（小堆）
{
	size_t child = parent * 2 + 1;//左孩子其实
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])//选出左右孩子中较小的那个孩子
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(HPDatatype* a, size_t child)//向上调整（小堆）
{
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap* hp, HPDatatype* a, int n)
{
	hp->_a = (HPDatatype* )malloc(sizeof(HPDatatype)*n);
	memcpy(hp->_a, a, sizeof(HPDatatype)*n);
	hp->_size = n;
	hp->_capacity = n;
	for (int i = n - 1 ; i > 0; i--)
	{
		AdjustUp(hp->_a, i);
	}
}
void HeapDestroy(Heap* hp)
{
	if (!HeapEmpty(hp))
	{
		free(hp->_a);
	}
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}


void HeapPush(Heap* hp, HPDatatype x)
//考虑增容的问题，而且插入该数据之后仍然保持该堆为小堆（大堆）
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity = 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDatatype*)realloc(hp->_a, sizeof(HPDatatype)*hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	for (int i = (hp->_size-2)/2; i  >= 0; i--)
	{
		AdjustDown(hp->_a,hp->_size, i);
	}
}
void HeapPop(Heap* hp)//删除小堆里的最小值（大堆里的最大值）
{
	assert(hp->_a);
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	for (int i = (hp->_size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

HPDatatype HeapTop(Heap* hp)
{
	assert(hp->_a);
	return hp->_a[0];

}
int HeapSize(Heap* hp)
{
	return hp->_size;
}
bool HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void HeapSort(int* a, int n)//排升序用大堆---排降序用小堆（交换）
{
	int sub = n - 1;
	for (int i = (sub - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	
	while (sub > 0)
	{
		swap(&a[0], &a[sub]);
		AdjustDown(a, sub, 0);
		sub--;
	}
}

void Testheap1()
{
	Heap p1;;
	int a[] = { 1, 3, 4, 6, 2, 7, 5, 0, 9, 8 };
	HeapInit(&p1, a, 10);
	HeapPrint(&p1);
	HeapPush(&p1, -1);
	HeapPrint(&p1);
	HeapPop(&p1);
	HeapPrint(&p1);
	printf("HeapTop = %d\n", HeapTop(&p1));
	printf("HeapSize = %d\n", HeapSize(&p1));
	HeapSort(a,10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}


}
