#pragma once
#include"commen.h"


/////////////////////////////////�������Ķ���
typedef char BinTreeDataType;
typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* _left;
	struct BinTreeNode* _right;
}BinTreeNode;

typedef BinTreeNode* BinTree;

////////////////////////////////����������������
void BinTreeInit(BinTree* t);
void BinTreeCreat(BinTree* t);//�Դ���(��ַ)��ʽ����
BinTree BinTreeCreat_1();//�Է���ֵ��ʽ����
BinTree BinTreeCreat_2(const char* s,int* i);//���������ַ������Է���ֵ��ʽ����
BinTree BinTreeCreat_3(const char* vlr, const char* lvr, int n);//������������򴴽�������
BinTree BinTreeCreat_4(const char* lvr, const char* lrv, int n);//��������ͺ��򴴽�������
int BinTreeSize(BinTree t);//������������
void BinTreePreOrder(BinTree t);//�������
void BinTreeInOrder(BinTree t);//�������
void BinTreePostOrder(BinTree t);//�������
void BinTreeLevelOrder(BinTree t);//�������
void BinTreePreOrder_No(BinTree t);//��������ǵݹ�
void BinTreeInOrder_No(BinTree t);//��������ǵݹ�
void BinTreePostOrder_No(BinTree t);//��������ǵݹ�
int Hight(BinTree t);//���ĸ߶�
BinTreeNode* Left(BinTreeNode* p);
BinTreeNode* Right(BinTreeNode* p);
BinTreeNode* BinTreeFind(BinTree t, ElemType key);
BinTreeNode* BinTreeParent(BinTree t, BinTreeNode* p);
BinTreeNode* BinTreeClone(BinTree t);//��¡һ�ö�����
bool Equal(BinTree t1, BinTree t2);

////////////////////////////////////
////////////////////////////////////���ڶ��еĶ��弰����ʵ��
typedef BinTreeNode* QueElemType;

typedef struct LinkQueueNode
{
	struct LinkQueueNode* next;
	QueElemType data;
}LinkQueueNode;
typedef struct LinkQueue
{
	LinkQueueNode* head;
	LinkQueueNode* tail;
}LinkQueue;

void LinkQueueInit(LinkQueue* q)
{
	q->head = q->tail = NULL;
}
void LinkQueueEn(LinkQueue* q, QueElemType x)
{
	LinkQueueNode* node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	node->next = NULL;
	node->data = x;

	if (q->head == NULL)//��ǰ����Ϊ��
	{
		q->head = q->tail = node;
	}
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
}
void LinkQueueDe(LinkQueue* q)
{
	if (q->head == NULL)
		printf("��ǰ����Ϊ�գ��޷����г��Ӳ���\n");
	else
	{
		LinkQueueNode* node = q->head;

		if (q->head == q->tail)//ֻ��һ��ͷ���
			q->head = q->tail = NULL;
		else
			q->head = node->next;

		free(node);
		node = NULL;
	}
}
QueElemType LinkQueueFront(LinkQueue* q)
{
	if (q->head == NULL)
		return -1;
	else
		return q->head->data;
}
int LinkQueueSize(LinkQueue* q)
{
	int sz = 0;
	LinkQueueNode* cur = q->head;
	while (cur != NULL)
	{
		++sz;
		cur = cur->next;
	}
	return sz;
}
bool LinkQueueEmpty(LinkQueue* q)
{
	return q->head == NULL;
}
void LinkQueueDestroy(LinkQueue* q)
{
	assert(q != NULL);
	LinkQueueNode* cur = q->head;
	while (cur != NULL)
	{
		q->head = cur->next;
		free(cur);
		cur = q->head;
	}
}
/////////////////////////////////////////
/////////////////////////////////////////����ջ�Ķ�����ʵ��
typedef BinTreeNode* StackElemType;
typedef struct LinkStackNode
{
	StackElemType val;
	struct LinkStackNode* next;
}LinkStackNode;
typedef LinkStackNode* LinkStack;

void LinkStackInit(LinkStack* pst)
{
	assert(pst);
	*pst = NULL;
}
bool LinkStackIsEmpty(LinkStack* pst)
{
	assert(pst != NULL);
	if (*pst == NULL)
		return true;
	return false;
}
void LinkStackPop(LinkStack* pst)
{
	assert(pst != NULL);
	if (LinkStackIsEmpty(pst))
		printf("��ǰջΪ�գ��޷�����pop����\n");
	else
	{
		LinkStackNode* head = (*pst);
		*pst = head->next;
		free(head);
	}
}
void LinkStackPush(LinkStack* pst, StackElemType x)
{
	assert(pst != NULL);
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->val = x;
	//��ջ
	node->next = *pst;
	*pst = node;
}

StackElemType LinkStackTop(LinkStack* pst)
{
	assert(pst != NULL);
	if (!LinkStackIsEmpty(pst))
		return (*pst)->val;
}
void LinkStackDestroy(LinkStack* pst)
{
	assert(pst != NULL);
	LinkStackNode* cur = (*pst);
	while (cur != NULL)
	{
		*pst = cur->next;
		free(cur);
		cur = *pst;
	}
}
/////////////////////////////////////////
/////////////////////////////////////////���ڶ��������ܵ�ʵ��
void BinTreeInit(BinTree* t)
{
	*t = NULL;
}
void BinTreeCreat(BinTree* t)//���򴴽�������
{
	assert(t != NULL);
	BinTreeDataType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreat(&((*t)->_left));
		BinTreeCreat(&((*t)->_right));
	}
}
BinTree BinTreeCreat_1()
{
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = item;
	t->_left = BinTreeCreat_1();
	t->_right = BinTreeCreat_1();
	return t;
}
BinTree BinTreeCreat_2(const char* s, int* i)
{
	assert(s != NULL);
	if (s[*i] == '\0' || s[*i] == '#')
		return NULL;
	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = s[*i];
	(*i)++;
	t->_left = BinTreeCreat_2(s, i);
	(*i)++;
	t->_right = BinTreeCreat_2(s, i);
	return t;
}
BinTree BinTreeCreat_3(const char* vlr, const char* lvr, int n)//������������򴴽�������
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (vlr[0] != lvr[k])
		++k;
	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	t->data = vlr[0];
	t->_left = BinTreeCreat_3(vlr+1,lvr,k);
	t->_right = BinTreeCreat_3(vlr+k+1,lvr+k+1,n-k-1);
	return t;
}
BinTree BinTreeCreat_4(const char* lvr, const char* lrv, int n)//��������ͺ��򴴽�������
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (lrv[n-1] != lvr[k] && k < n)
		++k;
	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	t->data = lrv[n-1];
	t->_left = BinTreeCreat_4(lvr, lrv, k);
	t->_right = BinTreeCreat_4(lvr + k + 1, lrv + k, n - k - 1);
	return t;
}
int BinTreeSize(BinTree t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + BinTreeSize(t->_left) + BinTreeSize(t->_right);
}
void BinTreePreOrder(BinTree t)
{
	if (t == NULL)
		return;
	printf("%c", t->data);
	BinTreePreOrder(t->_left);
	BinTreePreOrder(t->_right);
}
void BinTreeInOrder(BinTree t)
{
	if (t == NULL)
		return;
	BinTreeInOrder(t->_left);
	printf("%c", t->data);
	BinTreeInOrder(t->_right);
}
void BinTreePostOrder(BinTree t)
{
	if (t == NULL)
		return;
	BinTreePostOrder(t->_left);
	BinTreePostOrder(t->_right);
	printf("%c", t->data);
}
void BinTreeLevelOrder(BinTree t)
{
	if (t == NULL)
		return;
	LinkQueue q;
	LinkQueueInit(&q);
	LinkQueueEn(&q, t);
	while (!LinkQueueEmpty(&q))
	{
		BinTreeNode* node = LinkQueueFront(&q);
		if (node->_left != NULL)
			LinkQueueEn(&q, node->_left);
		if (node->_right != NULL)
			LinkQueueEn(&q, node->_right);
		printf("%c", node->data);
		LinkQueueDe(&q);
	}
}
void BinTreePreOrder_No(BinTree t)//��������ǵݹ�
{
	if (t == NULL)
		return;
	LinkStack st;
	LinkStackInit(&st);
	LinkStackPush(&st, t);
	while (!(LinkStackIsEmpty(&st)))
	{
		BinTreeNode* cur = LinkStackTop(&st);
		printf("%c", cur->data);
		LinkStackPop(&st);
		if (cur->_right != NULL)
			LinkStackPush(&st, cur->_right);
		if (cur->_left != NULL)
			LinkStackPush(&st, cur->_left);
	}
	LinkStackDestroy(&st);
}
void BinTreeInOrder_No(BinTree t)//��������ǵݹ�
{
	if (t == NULL)
		return;
	LinkStack st;
	LinkStackInit(&st);
	do{
		while (t != NULL)
		{
			LinkStackPush(&st, t);
			t = t->_left;
		}
		BinTreeNode* cur = LinkStackTop(&st);
		printf("%c", cur->data);
		LinkStackPop(&st);
		if (cur->_right != NULL)
			t = cur->_right;
	} while (!(LinkStackIsEmpty(&st)) || t != NULL);
}
void BinTreePostOrder_No(BinTree t)//��������ǵݹ�
{
	if (t == NULL)
		return;
	LinkStack st;
	LinkStackInit(&st);
	BinTreeNode* pre = NULL;
	do
	{
		while (t != NULL)
		{
			LinkStackPush(&st, t);
			t = t->_left;
		}
		BinTreeNode* p = LinkStackTop(&st);
		if (p->_right == NULL || p->_right == pre)
		{
			printf("%c", p->data);
			LinkStackPop(&st);
			pre = p;
		}
		else
			t = p->_right;
	} while (!(LinkStackIsEmpty(&st)));
}
int Hight(BinTree t)
{
	if (t == NULL)
		return 0;
	return 1 + max(Hight(t->_left), Hight(t->_right));
}
BinTreeNode* Left(BinTreeNode* p)
{
	assert(p != NULL);
	return p->_left;
}
BinTreeNode* Right(BinTreeNode* p)
{
	assert(p != NULL);
	return p->_right;
}
BinTreeNode* BinTreeFind(BinTree t, ElemType key)
{
	if (t == NULL || t->data == key)
		return t;
	BinTreeNode* leftfind = BinTreeFind(t->_left, key);
	BinTreeNode* rightfind = BinTreeFind(t->_right, key);
	return leftfind == NULL ? rightfind : leftfind;
}
BinTreeNode* BinTreeParent(BinTree t, BinTreeNode* p)
{
	if (t == NULL || t == p || p == NULL)
		return NULL;
	else if (t->_left == p || t->_right == p)
		return t;
	
	BinTreeNode* node1 = BinTreeParent(t->_left, p);
	if (node1 != NULL)
		return node1;
	return BinTreeParent(t->_right, p);	
}
BinTreeNode* BinTreeClone(BinTree t)
{
	if (t == NULL)
		return NULL;
	BinTreeNode* bt = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	bt->data = t->data;
	bt->_left = BinTreeClone(t->_left);
	bt->_right = BinTreeClone(t->_right);
	return bt;
}
bool Equal(BinTree t1, BinTree t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	else if (t1 == NULL || t2 == NULL)
		return false;
	else 
		return (t1->data == t2->data) && Equal(t1->_left, t2->_left) && Equal(t1->_right, t2->_right);
}