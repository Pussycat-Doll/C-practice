#pragma once
#include"commen.h"

#define HEAP_DEFAULT_SIZE 20
typedef int HeapElemtype;
typedef struct MinHeap
{
	HeapElemtype* base;
	size_t capacity;
	size_t size;
}MinHeap;

void HeapInit(MinHeap* hp, int sz);
void HeapInit_1(MinHeap* hp, int arr[], int n);
void HeapShow(MinHeap hp);
void ShiftUp(MinHeap* hp, int start);
void ShiftDown(MinHeap* hp, int start, int n);
void HeapInsert(MinHeap* hp, HeapElemtype data);
void HeapErase(MinHeap* hp);
HeapElemtype HeapTop(MinHeap* hp);
void HeapSort(MinHeap* hp, int arr[], int n);

///////////////////////////////////////////////////

void HeapInit(MinHeap* hp, int sz)
{
	assert(hp != NULL);
	hp->capacity = sz > HEAP_DEFAULT_SIZE ? sz : HEAP_DEFAULT_SIZE;
	hp->base = (HeapElemtype*)malloc(sizeof(HeapElemtype) * hp->capacity);
	assert(hp->base != NULL);
	memset(hp->base, 0, sizeof(HeapElemtype) * hp->capacity);
	assert(hp->base);
	hp->size = 0;
}
void HeapInit_1(MinHeap* hp, int arr[], int n)
{
	assert(hp != NULL);
	hp->capacity = hp->size = n;
	hp->base = (HeapElemtype*)malloc(sizeof(HeapElemtype) * hp->capacity);
	assert(hp->base != NULL);
	for (int i = 0; i < n; ++i)
		hp->base[i] = arr[i];
	//堆调整
	int curpos = n / 2 - 1;//最后一个分支
	while (curpos >= 0)
	{
		ShiftDown(hp, curpos, n);
		--curpos;
	}
}
void HeapShow(MinHeap hp)
{
	for (int i = 0; i < hp.size; ++i)
		printf("%d ", hp.base[i]);
	printf("\n");
}
void ShiftUp(MinHeap* hp, int start)
{
	assert(hp != NULL);
	int child = start;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (hp->base[child] < hp->base[parent])
		{
			Swap(&hp->base[child], &hp->base[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void ShiftDown(MinHeap* hp, int start, int n)
{
	assert(hp != NULL);
	int parent = start;
	int child = parent * 2 + 1;
	while (child < n)//左孩子结点存在
	{
		//在右孩子存在时，寻找左右孩子最小的孩子结点
		if (child + 1 < n && hp->base[child] > hp->base[child + 1])
			++child;
		if (hp->base[parent] > hp->base[child])
		{
			Swap(&hp->base[parent], &hp->base[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapInsert(MinHeap* hp, HeapElemtype data)
{
	assert(hp != NULL);
	if (hp->size == hp->capacity)
	{
		printf("当前堆已满，%d 元素无法插入堆中\n", data);
		return;
	}
	hp->base[hp->size] = data;
	ShiftUp(hp, hp->size);
	++(hp->size);
}
void HeapErase(MinHeap* hp)
{
	assert(hp != NULL);
	if (hp->size == 0)
	{
		printf("当前堆为空，无法进行删除操作");
		return;
	}
	--(hp->size);//找到堆最后一个元素的下标，同时也更新的删除后的元素个数
	hp->base[0] = hp->base[hp->size];//将最后一个元素覆盖堆顶元素
	ShiftDown(hp, 0, hp->size);
}
HeapElemtype HeapTop(MinHeap* hp)
{
	assert(hp != NULL && hp->size > 0);
	return hp->base[0];
}
void HeapSort(MinHeap* hp, int n)
{
	assert(hp != NULL);
	int num = n;
	while (num > 0)
	{
		--num;
		Swap(&hp->base[num], &hp->base[0]);
		ShiftDown(hp, 0, num);
	}
}