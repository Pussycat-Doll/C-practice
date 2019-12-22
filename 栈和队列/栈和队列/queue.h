#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>

typedef int QuDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QuDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur != NULL)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}

QueueNode* BuyQueueNode(QuDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QuDataType x)
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_front == NULL)
	{
		pq->_front = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
	}
	pq->_tail = newnode;
}
void QueuePop(Queue* pq)
{
	assert(pq && pq->_front);
	if ((pq->_front == pq->_tail))
	{
		free(pq->_front);
		pq->_front = pq->_tail = NULL;
	}
	else
	{
		QueueNode* next = pq->_front->_next;
		free(pq->_front);
		pq->_front = next;
	}
}

QuDataType QueueFront(Queue* pq)//���ض�ͷ��ֵ
{
	assert(pq && pq->_front);
	return pq->_front->_data;
}
QuDataType QueueBack(Queue* pq)//���ض�β��ֵ
{
	assert(pq && pq->_tail);
	return pq->_tail->_data;
}

bool Queueempty(Queue* pq)
{
	assert(pq);
	return pq->_tail == NULL;
}
void Queuetest()
{
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, 0);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	while (!Queueempty(&q1))
	{
		printf("%d ", QueueFront(&q1));
		QueuePop(&q1);
	}
	printf("\n");
	QueueDestory(&q1);
}

