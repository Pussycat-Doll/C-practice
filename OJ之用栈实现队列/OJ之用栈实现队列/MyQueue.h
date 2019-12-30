#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"stack.h"

typedef struct {
	Stack _pushst;
	Stack _popst;

} MyQueue;

/** Initialize your data structure here.生成队列 */
MyQueue* myQueueCreate();
/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x);
/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj);
/** Get the front element. */
int myQueuePeek(MyQueue* obj);
/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj);
void myQueueFree(MyQueue* obj);