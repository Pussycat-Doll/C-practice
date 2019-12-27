#pragma once
//单链表
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
typedef int SLTDatatype;
typedef struct SListNode//定义一个结点
{
	SLTDatatype _data;
	struct SListNode* _next;//指向下个结点的指针
}SListNode;

typedef struct SList
{
	SListNode* _head;//头指针
}SList;

void SListInit(SList* plt);//链表初始化
void SListDestory(SList* plt);//链表销毁
void SListPushFront(SList* plt,SLTDatatype x);//头插
void SListPushBack(SList* plt, SLTDatatype x);//尾插
void SListPopFront(SList* plt);//头删
void SListPopBack(SList* plt);//尾删
void SListInsertAfter(SListNode* pos, SLTDatatype x);//在某一位置后插入X
void SListEraseAfter(SListNode* pos);//删除某一位置之后的结点
void SListRemove(SList* plt,SLTDatatype x);//删除所有的为X的结点
SListNode* SListFind(SList* plt, SLTDatatype x);//查找值为x的结点的位置
void SListPrint(SList* plt);//打印链表

