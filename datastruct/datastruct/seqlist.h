#pragma once

#include"commen.h"

//定义顺序表的结构
#define SEQLIST_SIZE 8
#define DateType int
typedef struct SeqList
{
	DateType* base;//头指针
	size_t _capacity;
	size_t _size;
}SeqList;
void Swap(DateType* a, DateType* b)
{
	DateType tmp = *a;
	*a = *b;
	*b = tmp;
}
bool IsFull(SeqList* pList);
bool IsEmpty(SeqList* pList);
void SeqListShow(SeqList* pList);
void SeqListInit(SeqList* pList);
void SeqListDestory(SeqList* pList);
void SeqListPushBack(SeqList* pList, DateType x);
void SeqListPushFront(SeqList* pList, DateType x);
void SeqListPopBack(SeqList* pList);
void SeqListPopFront(SeqList* pList);
void SeqListInsertPos(SeqList* pList, size_t pos, DateType x);
void SeqListInsertVal(SeqList* pList, DateType val);
void SeqListErasePos(SeqList* pList, size_t pos);
void SeqListEraseVal(SeqList* pList, DateType val);
size_t SeqListFind(SeqList* pList, DateType val);
size_t SeqListLength(SeqList* pList);
size_t SeqListCapacity(SeqList* pList);
void SeqListSort(SeqList* pList);
void SeqListClean(SeqList* pList);
/// ///////////////////////////////////////////////////////////////
bool IsFull(SeqList* pList)
{
	assert(pList != NULL);
	return pList->_capacity == pList->_size;
}
bool IsEmpty(SeqList* pList)
{
	assert(pList != NULL);
	return pList->_size == 0;
}
void SeqListShow(SeqList* pList)
{
	assert(pList != NULL);
	for (size_t i = 0; i < pList->_size; ++i)
	{
		printf("%d ", pList->base[i]);
	}
	printf("\n");
}
void SeqListInit(SeqList* pList)
{
	pList->_capacity = SEQLIST_SIZE;
	pList->base = (DateType*)malloc(pList->_capacity * sizeof(DateType));
	pList->_size = 0;
}
void SeqListDestory(SeqList* pList)
{
	assert(pList != NULL);
	free(pList->base);
	pList->_capacity = pList->_size = 0;
	pList->base = NULL;
}
void SeqListPushBack(SeqList* pList, DateType x)
{
	assert(pList != NULL);
	if (IsFull(pList))
	{
		printf("顺序表已满，元素%d无法正常插入\n",x);
	}
	else
	{
		pList->base[pList->_size++] = x;
	}
}
void SeqListPushFront(SeqList* pList, DateType x)
{
	assert(pList != NULL);
	if (IsFull(pList))
		printf("该顺序表已满\n");
	else
	{
		for (int i = pList->_size-1; i >= 0; --i)
		{
			pList->base[i + 1] = pList->base[i];
		}
		pList->base[0] = x;
		++pList->_size;
	}
}
void SeqListPopBack(SeqList* pList)
{
	assert(pList != NULL);
	if(IsEmpty(pList))
		printf("该顺序表为空，无法正常尾删\n");
	else
		--pList->_size;
}
void SeqListPopFront(SeqList* pList)
{
	assert(pList != NULL);
	if (IsEmpty(pList))
	{
		printf("该顺序表为空，无法正常头删\n");
	}
	else if(pList->_size > 1)
	{
		for (int i = 1; i < pList->_size; ++i)
		{
			pList->base[i - 1] = pList->base[i];
		}
		--pList->_size;
	}
	else
	{
		SeqListPopBack(pList);//只有一个元素的情况下等于尾删
	}
}
void SeqListInsertPos(SeqList* pList, size_t pos, DateType x)
{
	assert(pList != NULL && pos <= pList->_size);
	if (IsFull(pList))
		printf("顺序表已满，无法正常进行插入\n");
	else
	{
		for (int i = pList->_size; i > pos; --i)
		{
			pList->base[i] = pList->base[i-1];
		}
		pList->base[pos] = x;
		++pList->_size;
	}
}
void SeqListInsertVal(SeqList* pList, DateType val)
{
	assert(pList != NULL);
	if(IsFull(pList))
		printf("顺序表已满，无法正常进行插入\n");
	else if (IsEmpty(pList))
	{
		SeqListPushFront(pList, val);
	}
	else if (pList->base[pList->_size - 1] <= val)
	{
		SeqListPushBack(pList, val);
	}
	else
	{
		for (int i = 0; i < pList->_size; ++i)
		{
			if (pList->base[i] > val)
			{
				SeqListInsertPos(pList, i, val);
				break;
			}
		}
	}
}
void SeqListErasePos(SeqList* pList, size_t pos)
{
	assert(pList != NULL && pos < pList->_size);
	if(IsEmpty(pList))
		printf("该顺序表为空，无法正常尾删\n");
	else
	{
		for (int i = pos; i < pList->_size-1; ++i)
		{
			pList->base[i] = pList->base[i + 1];
		}
		--pList->_size;
	}
}
size_t SeqListFind(SeqList* pList, DateType val)
{
	assert(pList != NULL);
	size_t pos = -1;
	for (int i = 0; i < pList->_size; ++i)
	{
		if (pList->base[i] == val)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

void SeqListEraseVal(SeqList* pList, DateType val)
{
	assert(pList != NULL);
	if (IsEmpty(pList))
		printf("该顺序表为空，无法正常尾删\n");
	else
	{
		size_t pos = SeqListFind(pList,val);
		if (pos == -1)
			printf("该元素不存在，删除失败!\n");
		else
			SeqListErasePos(pList, pos);
	}
}
size_t SeqListLength(SeqList* pList)
{
	assert(pList);
	return pList->_size;
}
size_t SeqListCapacity(SeqList* pList)
{
	assert(pList);
	return pList->_capacity;
}
void SeqListSort(SeqList* pList)
{
	assert(pList != NULL);
	for (int i = 0; i < pList->_size - 1; ++i)
	{
		for (int j = 0; j < pList->_size - i - 1; ++j)
		{
			if (pList->base[j] > pList->base[j + 1])
				Swap(&pList->base[j], &pList->base[j + 1]);
		}
	}
}
void SeqListClean(SeqList* pList)
{
	assert(pList);
	pList->_size = 0;
}