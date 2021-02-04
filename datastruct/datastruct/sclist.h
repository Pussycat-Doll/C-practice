#pragma once
#include"commen.h"

#define ElemType int
typedef struct SCListNode
{
	ElemType data;
	struct SCListNode* next;
}SCListNode;
typedef SCListNode* SCList;