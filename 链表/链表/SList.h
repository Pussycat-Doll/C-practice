#pragma once
//������
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
typedef int SLTDatatype;
typedef struct SListNode//����һ�����
{
	SLTDatatype _data;
	struct SListNode* _next;//ָ���¸�����ָ��
}SListNode;

typedef struct SList
{
	SListNode* _head;//ͷָ��
}SList;

void SListInit(SList* plt);//�����ʼ��
void SListDestory(SList* plt);//��������
void SListPushFront(SList* plt,SLTDatatype x);//ͷ��
void SListPushBack(SList* plt, SLTDatatype x);//β��
void SListPopFront(SList* plt);//ͷɾ
void SListPopBack(SList* plt);//βɾ
void SListInsertAfter(SListNode* pos, SLTDatatype x);//��ĳһλ�ú����X
void SListEraseAfter(SListNode* pos);//ɾ��ĳһλ��֮��Ľ��
void SListRemove(SList* plt,SLTDatatype x);//ɾ�����е�ΪX�Ľ��
SListNode* SListFind(SList* plt, SLTDatatype x);//����ֵΪx�Ľ���λ��
void SListPrint(SList* plt);//��ӡ����

