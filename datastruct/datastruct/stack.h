#pragma once
#include"commen.h"

/*
#define STACK_DEFAULT_SIZE 8
typedef struct SeqStack
{
	ElemType* base;//栈空间
	size_t _capacity;//栈的容量
	int top;//栈顶元素的后一个位置
}SeqStack;

void SeqStackInit(SeqStack* pst, int sz);
bool SeqStackIsEmpty(SeqStack* pst);
bool SeqStackIsFull(SeqStack* pst);
void SeqStackPop(SeqStack* pst);
void SeqStackPush(SeqStack* pst, ElemType x);
void SeqStackShow(SeqStack* pst);
void SeqStackTop(SeqStack* pst);
void SeqStackDestroy(SeqStack* pst);
int SeqStackSize(SeqStack* pst);

///////////////////////////////////////////////////////////////

void SeqStackInit(SeqStack* pst, int sz)
{
	pst->_capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (ElemType*)malloc(sizeof(ElemType) * sz);
	pst->top = 0;
}
bool SeqStackIsEmpty(SeqStack* pst)
{
	assert(pst != NULL);
	if (pst->top == 0)
		return true;
	return false;
}
bool SeqStackIsFull(SeqStack* pst)
{
	assert(pst != NULL);
	if (pst->top >= pst->_capacity)
		return true;
	return false;
}
void SeqStackPop(SeqStack* pst)
{
	assert(pst != NULL);
	if (!SeqStackIsEmpty(pst))
		--(pst->top);
	else
		printf("该栈为空，无法正常Pop\n");
}
void SeqStackPush(SeqStack* pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst))
		printf("当前栈空间已满，无法正常push元素 %d\n", x);
	else
		pst->base[(pst->top)++] = x;
}
void SeqStackShow(SeqStack* pst)
{
	printf("|        |\n");
	for (int i = (pst->top) - 1; i >= 0; --i)
	{
		printf("|   %d    |\n", pst->base[i]);
	}
	printf("|————|\n");
}
void SeqStackTop(SeqStack* pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("当前栈为空，无法获取栈顶元素\n");
	}
	printf("top元素为%d\n", pst->base[(pst->top) - 1]);
}
void SeqStackDestroy(SeqStack* pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->top = pst->_capacity = 0;
}
int SeqStackSize(SeqStack* pst)
{
	assert(pst != NULL);
	return pst->top;
}
*/

typedef struct LinkStackNode
{
	ElemType val;
	struct LinkStackNode* next;
}LinkStackNode;
typedef LinkStackNode* LinkStack;

void LinkStackInit(LinkStack* pst);
bool LinkStackIsEmpty(LinkStack* pst);
void LinkStackPop(LinkStack* pst);
void LinkStackPush(LinkStack* pst, ElemType x);
void LinkStackShow(LinkStack* pst);
void LinkStackTop(LinkStack* pst);
void LinkStackDestroy(LinkStack* pst);
int  LinkStackSize(LinkStack* pst);

///////////////////////////////////////////////////////////////

void LinkStackInit(LinkStack* pst)
{
	assert(pst);
	*pst = NULL;
}
bool LinkStackIsEmpty(LinkStack* pst)
{
	assert(pst != NULL);
	if (*pst == NULL)
		return true;
	return false;
}
void LinkStackPop(LinkStack* pst)
{
	assert(pst != NULL);
	if (LinkStackIsEmpty(pst))
		printf("当前栈为空，无法进行pop操作\n");
	else
	{
		LinkStackNode* head = (*pst);
		*pst = head->next;
		free(head);
	}
}
void LinkStackPush(LinkStack* pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->val = x;
	//入栈
	node->next = *pst;
	*pst = node;
}
void LinkStackShow(LinkStack* pst)
{
	LinkStackNode* cur = *pst;
	printf("|        |\n");
	while (cur != NULL)
	{
		printf("|   %d    |\n", cur->val);
		cur = cur->next;
	}
	printf("|————|\n");
}
void LinkStackTop(LinkStack* pst)
{
	assert(pst != NULL);
	if (LinkStackIsEmpty(pst))
		printf("当前栈为空，无法正常获取栈顶元素\n");
	else
	{
		printf("栈顶元素为 %d\n", (*pst)->val);
	}
}
void LinkStackDestroy(LinkStack* pst)
{
	assert(pst != NULL);
	LinkStackNode* cur = (*pst);
	while (cur != NULL)
	{
		*pst = cur->next;
		free(cur);
		cur = *pst;
	}
}
int  LinkStackSize(LinkStack* pst)
{
	assert(pst != NULL);
	LinkStackNode* cur = *pst;
	int sz = 0;
	while (cur != NULL)
	{
		++sz;
		cur = cur->next;
	}
	return sz;
}