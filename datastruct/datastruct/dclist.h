#pragma once
#include"commen.h"

typedef struct DCListNode
{
	ElemType data;
	struct DCListNode* prev;
	struct DCListNode* next;
}DCListNode;

typedef DCListNode* DCList;

DCListNode* BuyNode(ElemType v);
void DCListInit(DCList* phead);
void DCListDestroy(DCList* phead);
void DCListShow(DCList phead);
void DCListPushBack(DCList* phead, ElemType x);
void DCListPushFront(DCList* phead, ElemType x);
void DCListPopBack(DCList* phead);
void DCListPopFront(DCList* phead);
size_t DCListLength(DCList phead);
DCListNode* DCListFind(DCList phead, ElemType key);
void DCListEraseByVal(DCList* phead, ElemType key);
void DCListSort(DCList* phead);
void DCListInsertByVal(DCList* phead, ElemType x);
ElemType DCListFront(DCList* phead);
ElemType DCListBack(DCList* phead);
void DCListEraseAll(DCList* phead, ElemType x);
void DCListClean(DCList* phead);
void DCListReverse(DCList* phead);

/////////////////////////////////////////////////////////////////////////

DCListNode* BuyNode(ElemType v)
{
	DCListNode* node = (DCListNode*)malloc(sizeof(DCListNode));
	assert(node != NULL);
	node->data = v;
	node->next = node->prev = node;
	return node;
}
void DCListInit(DCList* phead)
{
	*phead = BuyNode(0);
}
void DCListDestroy(DCList* phead)
{
	assert(phead != NULL);
	DCListClean(phead);
	free(*phead);
	*phead = NULL;
}
void DCListShow(DCList phead)
{
	DCListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
void DCListPushBack(DCList* phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode* node = BuyNode(x);

	node->prev = (*phead)->prev;
	node->next = *phead;
	node->prev->next = node;
	(*phead)->prev = node;
}
void DCListPushFront(DCList* phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode* node = BuyNode(x);

	node->next = (*phead)->next;
	node->prev = *phead;
	(*phead)->next = node;
	node->next->prev = node;
}
void DCListPopBack(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* tail = (*phead)->prev;
	if (tail == (*phead))
		printf("当前链表中没有有效结点，无法进行尾删操作\n");
	else
	{
		(*phead)->prev = tail->prev;
		tail->prev->next = *phead;
		free(tail);
		tail = NULL;
	}
}
void DCListPopFront(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* first = (*phead)->next;
	if(first == (*phead))
		printf("当前链表中没有有效结点，无法进行头删操作\n");
	else
	{
		(*phead)->next = first->next;
		first->next->prev = *phead;
		free(first);
		first = NULL;
	}
}
size_t DCListLength(DCList phead)
{
	assert(phead != NULL);
	DCListNode* cur = phead->next;

	size_t len = 0;
	while (cur != phead)
	{
		++len;
		cur = cur->next;
	}
	return len;
}
DCListNode* DCListFind(DCList phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == key)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void DCListEraseByVal(DCList* phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode* cur = (*phead)->next;
	while (cur != *phead && cur->data != key)
	{
		cur = cur->next;
	}
	if (cur == *phead)
	{
		printf("链表中没有此元素，无法进行删除\n");
	}
	else
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		free(cur);
		cur = NULL;
	}
}
void DCListSort(DCList* phead)
{
	assert(phead != NULL);

	if (DCListLength(*phead) == 1)
		return;
	DCListNode* p = (*phead)->next;
	DCListNode* q = p->next;

	p->next = *phead;
	(*phead)->prev = p;

	DCListNode* cur = p;
	while (q != *phead)
	{
		p = q;
		q = q->next;
		while (cur != *phead && cur->data < p->data)
			cur = cur->next;
		p->next = cur;
		p->prev = cur->prev;
		cur->prev = p;
		p->prev->next = p;

		cur = (*phead)->next;
	}
}
void DCListInsertByVal(DCList* phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode* node = BuyNode(x);
	DCListNode* cur = (*phead)->next;
	while (cur != *phead && cur->data < x)
		cur = cur->next;
	node->next = cur;
	node->prev = cur->prev;
	node->prev->next = node;
	node->next->prev = node;
}
ElemType DCListFront(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* first = (*phead)->next;
	if (first == *phead)
		return -1;
	return first->data;
}
ElemType DCListBack(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* tail = (*phead)->prev;
	if (tail == *phead)
		return -1;
	return tail->data;
}
void DCListEraseAll(DCList* phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode* cur = (*phead)->next;
	while (cur != (*phead))
	{
		if (cur->data == x)
		{
			DCListNode* pre = cur->prev;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			free(cur);
			cur = pre;
		}
		cur = cur->next;
	}
}
void DCListReverse(DCList* phead)
{
	assert(phead != NULL);

	if (DCListLength(*phead) == 1)
		return;
	DCListNode* p = (*phead)->next;
	DCListNode* q = p->next;

	p->next = *phead;
	(*phead)->prev = p;

	while (q != *phead)
	{
		p = q;
		q = q->next;

		p->next = (*phead)->next;
		p->prev = *phead;
		(*phead)->next = p;
		p->next->prev = p;
	}
}
void DCListClean(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* head = *phead;
	DCListNode* cur = head->next;
	while (cur != head)
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		free(cur);
		cur = head->next;
	}
}
