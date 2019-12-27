#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SListInit(SList* plt)//初始化
{
	assert(plt);
	plt->_head = NULL;
}
void SListDestory(SList* plt)//销毁
{
	assert(plt);
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		plt->_head= cur->_next;
		free(cur);
		cur = plt->_head;
	}
}

void SListPushFront(SList* plt, SLTDatatype x)//头插
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//创建一个新结点
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next = plt->_head;
	plt->_head = newnode;
}

void SListPushBack(SList* plt, SLTDatatype x)//尾插(1.空连表；2.非空链表)
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//创建一个新结点
	newnode->_data = x;
	newnode->_next = NULL;
	if (plt->_head == NULL)
	{
		plt->_head = newnode;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}

}

void SListPrint(SList* plt)//打印链表
{
	assert(plt);
	SListNode* cur = plt->_head;
	while(cur!= NULL)//注意点最后一个也要打印出来，所以要到最后一个的后面才行
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void SListPopFront(SList* plt)//头删(1.空连表；2.非空链表)
{
	assert(plt);
	if (plt->_head == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		plt->_head = cur->_next;
		free(cur);
		cur = NULL;
	}
}

void SListPopBack(SList* plt)//尾删(1.空连表；2.只有一个结点；3.有两个结点以上)
{
	assert(plt);
	SListNode* cur = plt->_head;
	if (plt->_head == NULL)
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		free(cur);
		cur = NULL;
		plt->_head = NULL;
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
}

void SListInsertAfter(SListNode* pos, SLTDatatype x)//在某一位置后插入X	
{
	assert(pos);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//创建新结点
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next= pos->_next;
	pos->_next = newnode;
}
void SListEraseAfter(SListNode* pos)//删除某一位置之后的结点
{
	assert(pos);
	if (pos->_next = NULL)//1.删除的位置是最后一个结点的位置，后面没有元素;
	{
		return;
	}
	else//2.删除的位置在中间;
	{
		SListNode* node = pos->_next;
		pos->_next = node->_next;
		free(node);
		node = NULL;
	}
}

void SListRemove(SList* plt, SLTDatatype x)//删除值为X的结点
//1.第一个结点就是值为x的结点; 2.结点x在其它位置
{
	assert(plt);
	SListNode* prev = NULL;
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			if (prev == NULL)
			{
				plt->_head = cur->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}
			free(cur);
			cur = NULL;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

SListNode* SListFind(SList* plt, SLTDatatype x)//查找值为x的结点的位置
{
	assert(plt);
	SListNode* cur = plt->_head;
	while ( cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;
}
