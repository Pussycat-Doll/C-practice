#pragma once
#include"commen.h"

typedef struct LinkQueueNode
{
	struct LinkQueueNode* next;
	ElemType data;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode* head;
	LinkQueueNode* tail;
}LinkQueue;

void LinkQueueInit(LinkQueue* q);
void LinkQueueEn(LinkQueue* q, ElemType x);
void LinkQueueDe(LinkQueue* q);
ElemType LinkQueueFront(LinkQueue* q);
int LinkQueueSize(LinkQueue* q);
bool LinkQueueEmpty(LinkQueue* q);
void LinkQueueShow(LinkQueue* q);
void LinkQueueDestroy(LinkQueue* q);

///////////////////////////////////////////////////////////////

void LinkQueueInit(LinkQueue* q)
{
	q->head = q->tail = NULL;
}
void LinkQueueEn(LinkQueue* q, ElemType x)
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
ElemType LinkQueueFront(LinkQueue* q)
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
void LinkQueueShow(LinkQueue* q)
{
	LinkQueueNode* cur = q->head;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
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

#define SEQQUEUE_DEFAULT_SIZE 8
typedef struct SeqQueue
{
	ElemType* base;
	int capacity;
	int head;
	int tail;
}SeqQueue;

void SeqQueueInit(SeqQueue* psq, int sz);
void SeqQueueEn(SeqQueue* psq, ElemType x);
void SeqQueueDe(SeqQueue* psq);
ElemType SeqQueueFront(SeqQueue* psq);
int SeqQueueSize(SeqQueue* psq);
bool SeqQueueEmpty(SeqQueue* psq);
void SeqQueueDestroy(SeqQueue* psq);
void SeqQueueShow(SeqQueue* psq);

////////////////////////////////////////////////////////////

void SeqQueueInit(SeqQueue* psq, int sz)
{
	psq->capacity = sz > SEQQUEUE_DEFAULT_SIZE ? sz : SEQQUEUE_DEFAULT_SIZE;
	psq->base = (ElemType*)malloc(sizeof(ElemType) * psq->capacity);
	assert(psq->base);
	psq->head = psq->tail = 0;
}
void SeqQueueEn(SeqQueue* psq, ElemType x)
{
	if (psq->tail == psq->capacity)//队列已满
	{
		printf("当前队列已满，无法进行入队操作\n");
		return;
	}
	else if (psq->head == 0)//队列为空时
	{
		psq->base[0] = x;
		++(psq->head);
	}
	else
	{
		psq->base[psq->tail] = x;
	}
	++(psq->tail);
}
void SeqQueueDe(SeqQueue* psq)
{
	if (psq->head == 0)
		printf("当前队列为空，无法进行出队操作\n");
	else if (psq->tail == 1)//只有一个结点时
	{
		--(psq->head);
		--(psq->tail);
	}
	else
	{
		for (int i = 1; i < psq->tail; ++i)
		{
			psq->base[i - 1] = psq->base[i];
		}
		--(psq->tail);
	}
}
ElemType SeqQueueFront(SeqQueue* psq)
{
	if (psq->head > 0)
		return psq->base[0];
	return -1;
}
int SeqQueueSize(SeqQueue* psq)
{
	return psq->tail;
}
bool SeqQueueEmpty(SeqQueue* psq)
{
	return psq->head == 0;
}
void SeqQueueDestroy(SeqQueue* psq)
{
	free(psq->base);
	psq->base = NULL;
	psq->capacity = psq->head = psq->tail = 0;
}
void SeqQueueShow(SeqQueue* psq)
{
	for (int i = 0; i < psq->tail; ++i)
	{
		printf("%d ", psq->base[i]);
	}
	printf("\n");
}

#define CYCLESEQQUEUE_DEFAULT_SIZE 8
typedef struct CycleSeqQueue
{
	ElemType* base;
	int capacity;
	int head;
	int tail;
}CycleSeqQueue;

void CycleSeqQueueInit(CycleSeqQueue* psq, int sz);
void CycleSeqQueueEn(CycleSeqQueue* psq, ElemType x);
void CycleSeqQueueDe(CycleSeqQueue* psq);
ElemType CycleSeqQueueFront(CycleSeqQueue* psq);
int CycleSeqQueueSize(CycleSeqQueue* psq);
bool CycleSeqQueueEmpty(CycleSeqQueue* psq);
bool CycleSeqQueueFull(CycleSeqQueue* psq);
void CycleSeqQueueDestroy(CycleSeqQueue* psq);
void CycleSeqQueueShow(CycleSeqQueue* psq);

////////////////////////////////////////////////////////////
bool CycleSeqQueueFull(CycleSeqQueue* psq)
{
	assert(psq != NULL);
	return (psq->tail + 1) % (psq->capacity + 1) == psq->head;
}
bool CycleSeqQueueEmpty(CycleSeqQueue* psq)
{
	assert(psq != NULL);
	return psq->head == psq->tail;
}
void CycleSeqQueueInit(CycleSeqQueue* psq, int sz)
{
	psq->capacity = sz > CYCLESEQQUEUE_DEFAULT_SIZE ? sz : CYCLESEQQUEUE_DEFAULT_SIZE;
	psq->base = (ElemType*)malloc(sizeof(ElemType) * (psq->capacity+1));
	assert(psq->base);
	psq->head = psq->tail = 0;
}
void CycleSeqQueueEn(CycleSeqQueue* psq, ElemType x)
{
	assert(psq != NULL);
	if (CycleSeqQueueFull(psq))
	{
		printf("当前队列已满，%d 无法入队\n", x);
		return;
	}
	psq->base[psq->tail] = x;
	psq->tail = (psq->tail + 1) % (psq->capacity + 1);
}
void CycleSeqQueueDe(CycleSeqQueue* psq)
{
	assert(psq != NULL);
	if (CycleSeqQueueEmpty(psq))
	{
		printf("当前队列为空，无法进行出队操作\n");
		return;
	}
	psq->head = (psq->head + 1) % (psq->capacity + 1);
}
ElemType CycleSeqQueueFront(CycleSeqQueue* psq)
{
	assert(psq != NULL);
	if (!CycleSeqQueueEmpty(psq))
	{
		return psq->base[psq->head];
	}
}
int CycleSeqQueueSize(CycleSeqQueue* psq)
{
	assert(psq != NULL);
	int sz = 0,i = psq->head;
	while (i != psq->tail)
	{
		++sz;
		i = (i + 1) % (psq->capacity + 1);
	}
	return sz;
}
void CycleSeqQueueDestroy(CycleSeqQueue* psq)
{
	assert(psq != NULL);
	free(psq->base);
	psq->base = NULL;
	psq->capacity = psq->head = psq->tail = 0;
}
void CycleSeqQueueShow(CycleSeqQueue* psq)
{
	assert(psq != NULL);
	int i = psq->head;
	while (i != psq->tail)
	{
		printf("%d ", psq->base[i]);
		i = (i + 1) % (psq->capacity + 1);
	}
	printf("\n");
}