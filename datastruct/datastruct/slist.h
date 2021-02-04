#pragma once

#include"commen.h"

#define ElemType int
typedef struct SListNode
{
	ElemType data;
	struct SListNode* next;
}SListNode;

//����ͷ���ĵ�����
typedef SListNode* SList;

void SListInit(SList* phead);
void SListDestroy(SList* phead);
void SListShow(SList phead);
void SListPushBack(SList* phead,ElemType x);
void SListPushFront(SList* phead,ElemType x);
void SListPopBack(SList* phead);
void SListPopFront(SList* phead);
size_t SListLength(SList phead);
SListNode* SListFind(SList phead, ElemType key);
void SListEraseByVal(SList* phead, ElemType key);
void SListSort(SList* phead);
void SListInsertByVal(SList* phead,ElemType x);
ElemType SListFront(SList* phead);
ElemType SListBack(SList* phead);
void SListEraseAll(SList* phead, ElemType x);
void SListClean(SList* phead);
void SListReverse(SList* phead);
///////////////////////////////////////////////////////////////////////////////////////////////

void SListInit(SList* phead)
{
	assert(phead != NULL);
	*phead = NULL;
}

void SListShow(SList phead)
{
	//assert(phead != NULL);//���������Ϊ�յ������ʹ�ÿ�����Ҳ���Դ�ӡ����
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
void SListPushBack(SList* phead, ElemType x)
{
	assert(phead != NULL);
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	assert(node != NULL);
	node->data = x;
	node->next = NULL;

	//���ӽ��
	SListNode* cur = *phead;
	if (cur == NULL)//����Ľ��Ϊ��һ�����
		*phead = node;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = node;
	}
}
void SListPushFront(SList* phead, ElemType x)
{
	assert(phead != NULL);
	//�����½��
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	assert(newnode);
	newnode->data = x;
	//���½����в���
	newnode->next = *phead;
	*phead = newnode;

}

size_t SListLength(SList phead)
{
	assert(phead != NULL);
	SListNode* cur = phead;
	size_t count = 0;
	while (cur != NULL)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

void SListPopBack(SList* phead)
{
	assert(phead != NULL);
	SListNode* cur = *phead;
	SListNode* pre = NULL;
	if (*phead == NULL)
		printf("������Ϊ�գ��޷�ɾ��\n");
	else
	{
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		//���ֻ��һ�����ʱ��pre == NULL
		if (pre == NULL)
			*phead = NULL;
		else
			pre->next = NULL;
	}	
}
void SListPopFront(SList* phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
		printf("������Ϊ�գ��޷�ɾ��\n");
	else
	{
		SListNode* cur = *phead;
		*phead = cur->next;
		free(cur);
		cur = NULL;
	}
}
SListNode* SListFind(SList phead, ElemType key)
{
#if 0
	SListNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == key)
			return cur;
		cur = cur->next;
	}
	return NULL;
#endif
	SListNode* cur = phead;
	while (cur != NULL && cur->data != key)
		cur = cur->next;
	return cur;
}
void SListEraseByVal(SList* phead, ElemType key)
{
#if 0
	assert(phead != NULL);
	SListNode* node = SListFind(*phead, key);
	if (node == NULL)
		printf("��Ԫ��%d�����ڣ��޷�ɾ��\n", key);
	else
	{
		if (node->next == NULL)//��Ҫɾ���Ľ�������һ�����
			SListPopBack(phead);
		else
		{
			//���Ҫɾ��������һ�����
			SListNode* p = node->next;
			//����һ������Ԫ�ظ��ǵ�Ҫɾ��Ԫ�ص�λ�ã���ôҪɾ����Ԫ�ر����node->next
			node->data = p->data;
			//�Ƴ�Ҫɾ���Ľ��
			node->next = p->next;
			free(p);
			p = NULL;
		}
	}
#endif
	assert(phead != NULL);
	SListNode* p = SListFind(*phead, key);
	if (p == NULL)
		printf("Ԫ��%d�����ڣ��޷�����ɾ��\n",key);
	else
	{
		SListNode* prev = *phead;
		while (prev != p && prev->next != p)
		{
			prev = prev->next;
		}
		if (prev == p)//��һ��������Ҫ�ҵĽ��p
			*phead = p->next;
		else
			prev->next = p->next;
		free(p);
		p == NULL;
	}
}

void SListSort(SList* phead)
{
	assert(phead != NULL);
	if (SListLength(*phead) == 1)
		return;
	//������ֳɳ�����
	SListNode* p = *phead;
	SListNode* q = p->next;
	p->next = NULL;

	SListNode* prev = NULL;
	SListNode* cur = *phead;

	while (q != NULL)
	{
		p = q;
		q = q->next;
		while (cur != NULL && p->data > cur->data)
		{
			prev = cur;
			cur = cur->next;
		}
		if (prev == NULL)//ͷ��
		{
			p->next = *phead;
			*phead = p;
		}
		else
		{
			p->next = cur;
			prev->next = p;
		}
		prev = NULL;
		cur = *phead;
	}
}
void SListInsertByVal(SList* phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *cur = *phead,*prev = NULL;
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	assert(node != NULL);
	node->data = x;
	
	while (cur != NULL && cur->data < x)
	{
		prev = cur;
		cur = cur->next;
	}
	if (prev == NULL)
	{
		node->next = *phead;
		*phead = node;
	}
	else
	{
		node->next = cur;
		prev->next = node;
	}
}
ElemType SListFront(SList* phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
		return -1;
	else
		return (*phead)->data;
}
ElemType SListBack(SList* phead)
{
	assert(phead);
	if (*phead == NULL)
		return -1;
	SListNode* cur = *phead;
	while (cur->next != NULL)
		cur = cur->next;
	return cur->data;
}
void SListEraseAll(SList* phead,ElemType x)
{
	assert(phead != NULL);
	SListNode* node = NULL;
	while (*phead != NULL && (*phead)->data == x)//�����һ��Ԫ�ؾ���Ҫɾ����Ԫ��
	{
		node = *phead;
		*phead = (*phead)->next;
		free(node);
		node = NULL;
	}
	if (*phead == NULL)
		return;
	SListNode* cur = *phead;
	SListNode* prev = NULL, * next = cur->next;
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
}

void SListClean(SList* phead)
{
	assert(phead);
	SListNode* cur = NULL;
	while (*phead != NULL)
	{
		cur = *phead;
		*phead = (*phead)->next;
		free(cur);
		cur = NULL;
	}
}
void SListDestroy(SList* phead)
{
	SListClean(phead);//����ͷ���������������ٲ���һ��
}
void SListReverse(SList* phead)//ͷ��
{
	assert(phead != NULL);
	SListNode* p = *phead;
	SListNode* q = p->next;
	p->next = NULL;

	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = *phead;
		*phead = p;
	}
}













