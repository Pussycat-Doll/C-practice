#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SListInit(SList* plt)//��ʼ��
{
	assert(plt);
	plt->_head = NULL;
}
void SListDestory(SList* plt)//����
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

void SListPushFront(SList* plt, SLTDatatype x)//ͷ��
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//����һ���½��
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next = plt->_head;
	plt->_head = newnode;
}

void SListPushBack(SList* plt, SLTDatatype x)//β��(1.������2.�ǿ�����)
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//����һ���½��
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

void SListPrint(SList* plt)//��ӡ����
{
	assert(plt);
	SListNode* cur = plt->_head;
	while(cur!= NULL)//ע������һ��ҲҪ��ӡ����������Ҫ�����һ���ĺ������
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void SListPopFront(SList* plt)//ͷɾ(1.������2.�ǿ�����)
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

void SListPopBack(SList* plt)//βɾ(1.������2.ֻ��һ����㣻3.�������������)
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

void SListInsertAfter(SListNode* pos, SLTDatatype x)//��ĳһλ�ú����X	
{
	assert(pos);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//�����½��
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next= pos->_next;
	pos->_next = newnode;
}
void SListEraseAfter(SListNode* pos)//ɾ��ĳһλ��֮��Ľ��
{
	assert(pos);
	if (pos->_next = NULL)//1.ɾ����λ�������һ������λ�ã�����û��Ԫ��;
	{
		return;
	}
	else//2.ɾ����λ�����м�;
	{
		SListNode* node = pos->_next;
		pos->_next = node->_next;
		free(node);
		node = NULL;
	}
}

void SListRemove(SList* plt, SLTDatatype x)//ɾ��ֵΪX�Ľ��
//1.��һ��������ֵΪx�Ľ��; 2.���x������λ��
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

SListNode* SListFind(SList* plt, SLTDatatype x)//����ֵΪx�Ľ���λ��
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
