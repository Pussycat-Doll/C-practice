#pragma once
#include"commen.h"

typedef int BstElemType;
typedef struct BSTNode
{
	BstElemType data;
	struct BSTNode* leftchild;
	struct BSTNode* rightchild;
}BSTNode;

typedef BSTNode* BSTree;

void BstInit(BSTree* t);
bool BstInsert(BSTree* t, BstElemType x);
BstElemType BstMin(BSTree t);
BstElemType BstMax(BSTree t);
void BstsortPrint(BSTree t);
BSTNode* BstFind(BSTree bst, BstElemType x);
bool BstErase(BSTree* t, BSTNode* p);

//////////////////////////////////////////////

void BstInit(BSTree* t)
{
	assert(t != NULL);
	*t = NULL;
}
bool BstInsert(BSTree* t, BstElemType x)
{
	assert(t != NULL);
	if (*t == NULL)
	{
		*t = (BSTNode*)malloc(sizeof(BSTNode));
		(*t)->data = x;
		(*t)->leftchild = NULL;
		(*t)->rightchild = NULL;
		return true;
	}
	if (x > (*t)->data)
		return BstInsert(&(*t)->rightchild, x);
	else if (x < (*t)->data)
		return BstInsert(&(*t)->leftchild, x);
	else
		return false;//不插入重复元素
}
BstElemType BstMin(BSTree t)
{
	assert(t != NULL);
	BSTNode* cur = t;
	while (cur->leftchild != NULL)
		cur = cur->leftchild;
	return cur->data;
}
BstElemType BstMax(BSTree t)
{
	assert(t != NULL);
	BSTNode* cur = t;
	while (cur->rightchild != NULL)
		cur = cur->rightchild;
	return cur->data;
}
void BstsortPrint(BSTree t)
{
	if (t == NULL)
		return;
	BstsortPrint(t->leftchild);
	printf("%d ", t->data);
	BstsortPrint(t->rightchild);
}
BSTNode* BstFind(BSTree bst, BstElemType x)
{
	assert(bst != NULL);
	BSTNode* cur = bst;
	while (cur != NULL)
	{
		if (x > cur->data)
			cur = cur->rightchild;
		else if (x < cur->data)
			cur = cur->leftchild;
		else
			return cur;
	}
	return NULL;
}
bool BstErase(BSTree* t, BSTNode* p)
{
	if (*t != NULL)
	{
		if (p->data > (*t)->data)
			return BstErase(&(*t)->rightchild, p);
		else if(p->data < (*t)->data)
			return BstErase(&(*t)->leftchild, p);
		else
		{
			if (p->leftchild && p->rightchild)//具有两个子女结点
			{
				BSTNode* leftmax = p->leftchild;
				//当前结点左子树的最大值
				while (leftmax->rightchild != NULL)
					leftmax = leftmax->rightchild;
				p->data = leftmax->data;
				return BstErase(&(*t)->leftchild, leftmax);
			}
			else//只有一个子女结点，或者没有结点
			{
				if (p->leftchild != NULL)
					(*t) = p->leftchild;
				else
					(*t) = p->rightchild;
			}
			free(p);
			p = NULL;
			return true;
		}
	}
	return false;
}
