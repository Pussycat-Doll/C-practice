#pragma once
#include"commen.h"
/// <summary>

/// </summary>

typedef char BinTreeDataType;
typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* _left;
	struct BinTreeNode* _right;
}BinTreeNode;

typedef BinTreeNode* BinTree;

void BinTreeInit(BinTree* t);
void BinTreeCreat(BinTree* t);
int BinTreeSize(BinTree t);
void BinTreePreOrder(BinTree t);
void BinTreeInOrder(BinTree t);
void BinTreePostOrder(BinTree t);
void BinTreeLevelOrder(BinTree t);


/////////////////////////////////////////////////

typedef BinTreeNode* QueElemType;

typedef struct LinkQueueNode
{
	struct LinkQueueNode* next;
	QueElemType data;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode* head;
	LinkQueueNode* tail;
}LinkQueue;


void LinkQueueInit(LinkQueue* q)
{
	q->head = q->tail = NULL;
}
void LinkQueueEn(LinkQueue* q, QueElemType x)
{
	LinkQueueNode* node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	node->next = NULL;
	node->data = x;

	if (q->head == NULL)//当前队列为空
	{
		q->head = q->tail = node;
	}
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
}
void LinkQueueDe(LinkQueue* q)
{
	if (q->head == NULL)
		printf("当前队列为空，无法进行出队操作\n");
	else
	{
		LinkQueueNode* node = q->head;

		if (q->head == q->tail)//只有一个头结点
			q->head = q->tail = NULL;
		else
			q->head = node->next;

		free(node);
		node = NULL;
	}
}
QueElemType LinkQueueFront(LinkQueue* q)
{
	if (q->head == NULL)
		return -1;
	else
		return q->head->data;
}
int LinkQueueSize(LinkQueue* q)
{
	int sz = 0;
	LinkQueueNode* cur = q->head;
	while (cur != NULL)
	{
		++sz;
		cur = cur->next;
	}
	return sz;
}
bool LinkQueueEmpty(LinkQueue* q)
{
	return q->head == NULL;
}
void LinkQueueDestroy(LinkQueue* q)
{
	assert(q != NULL);
	LinkQueueNode* cur = q->head;
	while (cur != NULL)
	{
		q->head = cur->next;
		free(cur);
		cur = q->head;
	}
}
///////////////////////////////////////////////////////

void BinTreeInit(BinTree* t)
{
	*t = NULL;
}
void BinTreeCreat(BinTree* t)//先序创建二叉树
{
	assert(t != NULL);
	BinTreeDataType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreat(&((*t)->_left));
		BinTreeCreat(&((*t)->_right));
	}
}
int BinTreeSize(BinTree t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + BinTreeSize(t->_left) + BinTreeSize(t->_right);
}
void BinTreePreOrder(BinTree t)
{
	if (t == NULL)
		return;
	printf("%c", t->data);
	BinTreePreOrder(t->_left);
	BinTreePreOrder(t->_right);
}
void BinTreeInOrder(BinTree t)
{
	if (t == NULL)
		return;
	BinTreeInOrder(t->_left);
	printf("%c", t->data);
	BinTreeInOrder(t->_right);
}
void BinTreePostOrder(BinTree t)
{
	if (t == NULL)
		return;
	BinTreePostOrder(t->_left);
	BinTreePostOrder(t->_right);
	printf("%c", t->data);
}
void BinTreeLevelOrder(BinTree t)
{
	if (t == NULL)
		return;
	LinkQueue q;
	LinkQueueInit(&q);
	LinkQueueEn(&q, t);
	while (!LinkQueueEmpty(&q))
	{
		BinTreeNode* node = LinkQueueFront(&q);
		if (node->_left != NULL)
			LinkQueueEn(&q, node->_left);
		if (node->_right != NULL)
			LinkQueueEn(&q, node->_right);
		printf("%c", node->data);
		LinkQueueDe(&q);
	}
}




















////////////////////////////////////////////////////////



