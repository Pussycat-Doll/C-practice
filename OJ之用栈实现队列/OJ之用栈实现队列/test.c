#define _CRT_SECURE_NO_WARNINGS 1
#include"MyQueue.h"
#include"stack.h"

int main()
{
	MyQueue* obj = myQueueCreate();
	myQueuePush(obj, 9);

	int param_2 = myQueuePop(obj);

	int param_3 = myQueuePeek(obj);

	bool param_4 = myQueueEmpty(obj);

	myQueueFree(obj);
	system("pause");
	return 0;
}