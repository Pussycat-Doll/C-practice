#pragma once

#include"commen.h"

//����˳���Ľṹ
#define SEQLIST_SIZE 8
#define DateType int
typedef struct SeqList
{
	DateType* base;//ָ�����ݵ�ָ��
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
bool _Inc(SeqList* pList, size_t new_capacity);//���ݲ���
void SeqListInit(SeqList* pList);
void SeqListDestory(SeqList* pList);
void SeqListPushBack(SeqList* pList, DateType x);
void SeqListPushFront(SeqList* pList, DateType x);
void SeqListPopBack(SeqList* pList);
void SeqListPopFront(SeqList* pList);
void SeqListInsertByPos(SeqList* pList, size_t pos, DateType x);
void SeqListInsertByVal(SeqList* pList, DateType val);
void SeqListEraseByPos(SeqList* pList, size_t pos);
void SeqListEraseByVal(SeqList* pList, DateType val);
size_t SeqListFind(SeqList* pList, DateType val);
size_t SeqListLength(SeqList* pList);
size_t SeqListCapacity(SeqList* pList);
void SeqListSort(SeqList* pList);
void SeqListClean(SeqList* pList);
void SeqListReverse(SeqList* pList);
DateType SeqListFront(SeqList* pList);
DateType SeqListBack(SeqList* pList);
size_t SeqListBinarySearch(SeqList* pList, DateType val);
void SeqListEraseAll(SeqList* pList);
//////////////////////////////////////////////////////////////
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
bool _Inc(SeqList* pList, size_t new_capacity)//���ݲ���
{
#if 0
	assert(pList != NULL && new_capacity > pList->_capacity);
	DateType* newbase = (DateType*)realloc(pList->base, sizeof(DateType) * new_capacity);
	//realloc���������µ�ǰ��������
	if (newbase == NULL)
		return false;
	pList->base = newbase;
	pList->_capacity = new_capacity;
	return true;
#endif
	assert(pList != NULL && new_capacity > pList->_capacity);
	//�� �����¿ռ�
	DateType* newbase = (DateType*)malloc(sizeof(DateType) * new_capacity);
	if (newbase == NULL)
		return false;
	//�� ����ԭ������
	memcpy(newbase, pList->base, sizeof(DateType) * pList->_capacity);
	//�� �ͷžɿռ�
	free(pList->base);
	//�� ָ���¿ռ䣬�ı�������
	pList->base = newbase;
	pList->_capacity = new_capacity;
	return true;
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
	if (IsFull(pList) && !_Inc(pList,pList->_capacity*2))
	{
		printf("˳���������Ԫ��%d�޷���������\n",x);
	}
	else
	{
		pList->base[pList->_size++] = x;
	}
}
void SeqListPushFront(SeqList* pList, DateType x)
{
	assert(pList != NULL);
	if (IsFull(pList) && !_Inc(pList, pList->_capacity * 2))
		printf("��˳�������\n");
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
		printf("��˳���Ϊ�գ��޷�����βɾ\n");
	else
		--pList->_size;
}
void SeqListPopFront(SeqList* pList)
{
	assert(pList != NULL);
	if (IsEmpty(pList))
	{
		printf("��˳���Ϊ�գ��޷�����ͷɾ\n");
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
		SeqListPopBack(pList);//ֻ��һ��Ԫ�ص�����µ���βɾ
	}
}
void SeqListInsertByPos(SeqList* pList, size_t pos, DateType x)
{
	assert(pList != NULL && pos <= pList->_size);
	if (IsFull(pList) && !_Inc(pList, pList->_capacity * 2))
		printf("˳����������޷��������в���\n");
	else
	{
		for (int i = pList->_size - 1; i >= (int)pos; --i)
		{
			pList->base[i + 1] = pList->base[i];
		}
		pList->base[pos] = x;
		++pList->_size;
	}
}
void SeqListInsertByVal(SeqList* pList, DateType val)
{
	assert(pList != NULL);
	if(IsFull(pList) && !_Inc(pList, pList->_capacity * 2))
		printf("˳����������޷��������в���\n");
	else
	{
		size_t end = pList->_size - 1;
		while (end >= 0 && pList->base[end] > val)
		{
			pList->base[end + 1] = pList->base[end];
			--end;
		}
		pList->base[end + 1] = val;
		++pList->_size;
	}
}
void SeqListEraseByPos(SeqList* pList, size_t pos)
{
	assert(pList != NULL && pos < pList->_size);
	if(IsEmpty(pList))
		printf("��˳���Ϊ�գ��޷�����βɾ\n");
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

void SeqListEraseByVal(SeqList* pList, DateType val)
{
	assert(pList != NULL);
	if (IsEmpty(pList))
		printf("��˳���Ϊ�գ��޷�����ɾ��\n");
	else
	{
		size_t pos = SeqListFind(pList,val);
		if (pos == -1)
			printf("��Ԫ�ز����ڣ�ɾ��ʧ��!\n");
		else
			SeqListEraseByPos(pList, pos);
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
void SeqListReverse(SeqList* pList)
{
	assert(pList);
	if (pList->_size == 1)
		return;
	int start = 0, end = pList->_size - 1;
	while (start < end)
	{
		Swap(&pList->base[start], &pList->base[end]);
		++start;
		--end;
	}
}
DateType SeqListFront(SeqList* pList)
{
	assert(pList != NULL);
	if (IsEmpty(pList))
		return -1;
	else
		return pList->base[0];
}
DateType SeqListBack(SeqList* pList)
{
	assert(pList != NULL);
	if (IsEmpty(pList))
		return -1;
	else
		return pList->base[pList->_size-1];
	
}
size_t SeqListBinarySearch(SeqList* pList, DateType val)
{
	assert(pList != NULL);
	int low = 0, high = pList->_size - 1;
	while (low <= high)
	{
		int mid = low + ((high - low)>>1);
		if (val < pList->base[mid])
			high = mid - 1;
		else if (val > pList->base[mid])
			low = mid + 1;
		else
		{
			return mid;
		}
	}
	return -1;
}
void SeqListEraseAll(SeqList* pList)
{
	assert(pList != NULL);
	if (IsEmpty(pList))
		return;
	pList->_size = 0;
}