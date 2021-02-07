#pragma once
#include"commen.h"

#define ElemType int
typedef struct SCListNode
{
	ElemType data;
	struct SCListNode* next;
}SCListNode;

typedef SCListNode* SCList;

void SCListInit(SCList* phead);
void SCListDestroy(SCList* phead);
void SCListShow(SCList phead);
void SCListPushBack(SCList* phead, ElemType x);
void SCListPushFront(SCList* phead, ElemType x);
void SCListPopBack(SCList* phead);
void SCListPopFront(SCList* phead);
size_t SCListLength(SCList phead);
SCListNode* SCListFind(SCList phead, ElemType key);
void SCListEraseByVal(SCList* phead, ElemType key);
void SCListSort(SCList* phead);
void SCListInsertByVal(SCList* phead, ElemType x);
ElemType SCListFront(SCList* phead);
ElemType SCListBack(SCList* phead);
void SCListEraseAll(SCList* phead, ElemType x);
void SCListClean(SCList* phead);
void SCListReverse(SCList* phead);
///////////////////////////////////////////////////////////////////////////////////////////////
void SCListInit(SCList* phead)
{
	*phead = NULL;
}
void SCListShow(SCList phead)
{
	SCListNode* cur = phead;
	if (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
		while (cur != NULL && cur != phead)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
	}
	printf("over\n");
}

void SCListPushBack(SCList* phead, ElemType x)
{
	assert(phead != NULL);
	SCListNode* node = (SCListNode*)malloc(sizeof(SCListNode));
	assert(node != NULL);
	node->data = x;
	SCListNode* cur = *phead;
	if (cur == NULL)//����Ľ���ǵ�һ�����
		*phead = node;
	else
	{
		while (cur->next != *phead)
			cur = cur->next;
		cur->next = node;
	}
	node->next = *phead;//���һ�����ָ��ͷ��
}
void SCListPushFront(SCList* phead, ElemType x)
{
	assert(phead != NULL);
	SCListNode* node = (SCListNode*)malloc(sizeof(SCListNode));
	node->data = x;
	SCListNode* last = *phead;
	if (*phead == NULL)//����Ϊ��ʱ����ͷ��
	{
		*phead = node;
		node->next = *phead;
	}
	else
	{
		//�ҵ����һ�����
		while (last->next != *phead)
			last = last->next;
		node->next = *phead;
		*phead = node;
		last->next = *phead;
	}
}
void SCListPopBack(SCList* phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
		printf("��ǰ����Ϊ�գ��޷�����ɾ������\n");
	else if (SCListLength(*phead) == 1)//ֻ��һ�����
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SCListNode* cur = *phead;
		SCListNode* prev = NULL;
		while (cur->next != *phead)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		prev->next = *phead;
	}
}
void SCListPopFront(SCList* phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
		printf("��ǰ����Ϊ�գ��޷�����ɾ������\n");
	else if (SCListLength(*phead) == 1)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SCListNode* cur = *phead;
		SCListNode* newhead = cur->next;
		while (cur->next != *phead)
			cur = cur->next;
		cur->next = newhead;
		free(*phead);
		*phead = newhead;
	}
}
size_t SCListLength(SCList phead)
{
	if (phead == NULL)
		return 0;
	size_t len = 1;
	SCListNode* cur = phead->next;
	while (cur != NULL && cur != phead)
	{
		cur = cur->next;
		++len;
	}
	return len;
}
void SCListDestroy(SCList* phead)
{
	assert(phead != NULL);
	SCListNode* cur = *phead;
	while (*phead != NULL)
	{
		SCListPopBack(phead);
	}
}
SCListNode* SCListFind(SCList phead, ElemType key)
{
	assert(phead != NULL);
	SCListNode* cur = phead;
	while (cur != NULL && cur->data != key)
	{
		cur = cur->next;
		if (cur->next == phead)
			return NULL;
	}
	return cur;
}
void SCListEraseByVal(SCList* phead, ElemType key)
{
	assert(phead != NULL);
	if (*phead == NULL)
		printf("������Ϊ�գ��޷�����ɾ������\n");
	else if((*phead)->data == key)
	{
		SCListPopFront(phead);
	}
	else
	{
		SCListNode* cur = *phead;
		SCListNode* prev = NULL;
		while (cur->data != key)
		{
			if (cur->next == *phead)
			{
				printf("��������û��Ԫ��%d,�޷�����ɾ������\n", key);
				return;
			}
			prev = cur;
			cur = cur->next;
		}
		if (cur->next == *phead)
			SCListPopBack(phead);
		else
		{
			prev->next = cur->next;
			free(cur);
			cur = NULL;
		}
	}
}
ElemType SCListFront(SCList* phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
		return -1;
	else
		return (*phead)->data;
}
ElemType SCListBack(SCList* phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
		return -1;
	else
	{
		SCListNode* cur = *phead;
		while (cur->next != *phead)
			cur = cur->next;
		return cur->data;
	}
}
void SCListSort(SCList* phead)
{
	assert(phead != NULL);
	if (SCListLength(*phead) == 1 || SCListLength(*phead)== 0)
		return;
	SCListNode* p = *phead;
	SCListNode* q = (*phead)->next;
	p->next = *phead;

	SCListNode* node = q;
	while (node->next != *phead)
		node = node->next;
	node->next = NULL;

	SCListNode* cur = *phead;
	SCListNode* prev = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;

		while (cur != NULL && cur->data < p->data)
		{
			prev = cur;
			cur = cur->next;
			if (cur == *phead)
				break;
		}
		if (prev == NULL)//ͷ��
		{
			SCListNode* last = *phead;
			while (last->next != *phead)
				last = last->next;
			p->next = *phead;
			*phead = p;
			last->next = *phead;
		}
		else
		{
			prev->next = p;
			p->next = cur;
		}
		prev = NULL;
		cur = *phead;
	}
}
void SCListInsertByVal(SCList* phead, ElemType x)
{
	assert(phead != NULL);
	SCListNode* node = (SCListNode*)malloc(sizeof(SCListNode));
	node->data = x;
	if (SCListLength(*phead) == 0)
		SCListPushFront(phead, node);
	else
	{
		SCListNode* cur = *phead;
		SCListNode* prev = NULL;
		while (cur->data < x)
		{
			prev = cur;
			cur = cur->next;
			if (cur == *phead)
				break;
		}
		if (prev == NULL)//ͷ��
		{
			SCListNode* last = *phead;
			while (last->next != *phead)
				last = last->next;
			node->next = *phead;
			*phead = node;
			last->next = *phead;
		}
		else
		{
			node->next = cur;
			prev->next = node;
		}
	}
}
void SCListEraseAll(SCList* phead, ElemType x)
{
	assert(phead != NULL);
	if (*phead == NULL)
	{
		printf("��ǰ����Ϊ�գ��޷�����ɾ������\n");
	}
	else
	{
		SCListNode* cur = *phead;
		SCListNode* node = NULL;
		while (cur->next != *phead)
			cur = cur->next;
		cur->next = NULL;//��ѭ����ʱ�Ͽ�������ɾ�����
		while (*phead != NULL && (*phead)->data == x)
		{
			node = *phead;
			*phead = node->next;
			free(node);
			node = NULL;
		}
		if (*phead == NULL)
			return;
		cur = *phead;
		SCListNode* prev = NULL,* next = cur->next;
		while (cur != NULL)
		{
			if (cur->data == x)
			{
				free(cur);
				cur = prev;
				prev->next = next;
			}
			prev = cur;
			cur = next;
			if(cur != NULL)
				next = cur->next;
		}
		prev->next = *phead;//��������ͷ��
	}
}
void SCListClean(SCList* phead)
{
	SCListDestroy(phead);
}
void SCListReverse(SCList* phead)
{
	assert(phead != NULL);
	if (SCListLength(*phead) == 1 || SCListLength(*phead) == 0)
		return;
	SCListNode* p = *phead;
	SCListNode* q = p->next;

	SCListNode* last = q;
	while (last->next != *phead)
		last = last->next;
	last->next = NULL;
	p->next = *phead;//�ֳɵ���ѭ������p�͵�����q

	while (q != NULL)//��q�еĽ��һ��ͷ����p��
	{
		p = q;
		q = q->next;

		last = *phead;
		while (last->next != *phead)
			last = last->next;
		p->next = *phead;
		*phead = p;
		last->next = *phead;
	}
}