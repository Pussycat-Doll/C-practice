#pragma once
#include"commen.h"
#define ElemType int
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
int LinkStackTop(LinkStack* pst);
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
int LinkStackTop(LinkStack* pst)
{
	assert(pst != NULL);
	if (LinkStackIsEmpty(pst))
		return (*pst)->val;
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