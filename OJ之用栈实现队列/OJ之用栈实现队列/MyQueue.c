
#include"MyQueue.h"
/** Initialize your data structure here.生成队列 */
MyQueue* myQueueCreate() {
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&(obj->_pushst), x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (Stackempty(&(obj->_popst)))
	{
		while (!Stackempty(&(obj->_pushst)))
		{
			int x = StackTop(&(obj->_pushst));
			StackPop(&(obj->_pushst));
			StackPush(&(obj->_popst), x);
		}
	}
	int top = StackTop(&(obj->_popst));
	StackPop(&(obj->_popst));
	return top;
}
/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	if (Stackempty(&(obj->_popst)))
	{
		while (!Stackempty(&(obj->_pushst)))
		{
			int x = StackTop(&(obj->_pushst));
			StackPop(&(obj->_pushst));
			StackPush(&(obj->_popst), x);
		}
	}
	return StackTop(&(obj->_popst));
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	if (Stackempty(&(obj->_popst)) && Stackempty(&(obj->_pushst)))
	{
		return true;
	}
	return false;
}

void myQueueFree(MyQueue* obj) {
	if (!Stackempty(&(obj->_popst)))
	{
		StackDestory(&(obj->_popst));
	}
	if (!Stackempty(&(obj->_pushst)))
	{
		StackDestory(&(obj->_pushst));
	}
}
