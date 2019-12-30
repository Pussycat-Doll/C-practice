#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//#define N 100

typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	size_t _size;
	size_t _capacity;
}SeqList;

void SeqListInit(SeqList* ps);//初始化
void SeqListDestory(SeqList* ps);//销毁
SeqListCheckCapacity(SeqList* ps);//检查是否需要增容，并执行
void SeqListPushBack(SeqList* ps,DataType x);//尾插
void SeqListPushFront(SeqList* ps, DataType x);//头插
void SeqListPopBack(SeqList* ps);//尾删
void SeqListPopFront(SeqList* ps);//头删
void SeqListInsert(SeqList* ps,size_t pos, DataType x);//在某个位置插入一个元素
void SeqListErase(SeqList* ps, size_t pos);//删除某个位置的元素
size_t SeqListSize(SeqList* ps);//返回顺序表实际容纳元素的个数
size_t SeqListFind(SeqList* ps, DataType x);//查找某一个元素,返回其下标
DataType SeqListAt(SeqList* ps, size_t pos);//返回位置pos的值


void SeqListBubbleSort(SeqList* ps);//对顺序表进行冒泡排序
size_t SeqListBinaryFind(SeqList* ps, DataType x);//二分查找
//要求：时间复杂度：O(N)   空间复杂度：O(1)
void SeqListRemoveAll(SeqList* ps, DataType x);//删除所有重复的元素