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
void HeapShow(MinHeap hp);
void ShiftUp(MinHeap* hp, int start);
void HeapInsert(MinHeap* hp, HeapElemtype data);

///////////////////////////////////////////////////

void HeapInit(MinHeap* hp, int sz)
{
	assert(hp != NULL);
	hp->capacity = sz > HEAP_DEFAULT_SIZE ? sz : HEAP_DEFAULT_SIZE;
	hp->base = (HeapElemtype*)malloc(sizeof(HeapElemtype) * hp->capacity);
	memset(hp->base, 0, sizeof(HeapElemtype) * hp->capacity);
	assert(hp->base);
	hp->size = 0;
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