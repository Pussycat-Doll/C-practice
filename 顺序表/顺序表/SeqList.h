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

void SeqListInit(SeqList* ps);//��ʼ��
void SeqListDestory(SeqList* ps);//����
SeqListCheckCapacity(SeqList* ps);//����Ƿ���Ҫ���ݣ���ִ��
void SeqListPushBack(SeqList* ps,DataType x);//β��
void SeqListPushFront(SeqList* ps, DataType x);//ͷ��
void SeqListPopBack(SeqList* ps);//βɾ
void SeqListPopFront(SeqList* ps);//ͷɾ
void SeqListInsert(SeqList* ps,size_t pos, DataType x);//��ĳ��λ�ò���һ��Ԫ��
void SeqListErase(SeqList* ps, size_t pos);//ɾ��ĳ��λ�õ�Ԫ��
size_t SeqListSize(SeqList* ps);//����˳���ʵ������Ԫ�صĸ���
size_t SeqListFind(SeqList* ps, DataType x);//����ĳһ��Ԫ��,�������±�
DataType SeqListAt(SeqList* ps, size_t pos);//����λ��pos��ֵ


void SeqListBubbleSort(SeqList* ps);//��˳������ð������
size_t SeqListBinaryFind(SeqList* ps, DataType x);//���ֲ���
//Ҫ��ʱ�临�Ӷȣ�O(N)   �ռ临�Ӷȣ�O(1)
void SeqListRemoveAll(SeqList* ps, DataType x);//ɾ�������ظ���Ԫ��