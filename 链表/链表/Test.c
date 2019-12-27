#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void TestSList1()
{
	SList s1;
	SListInit(&s1);
	SListPushFront(&s1, 2);
	SListPushFront(&s1, 1);
	SListPushFront(&s1, 0);
	SListPushBack(&s1, 3);
	SListPushBack(&s1, 4);
	SListPushBack(&s1, 5);
	SListPopFront(&s1);
	SListPopBack(&s1);
	SListPrint(&s1);
	SListDestory(&s1);
}
void TestSList2()
{
	SList s2;
	SListInit(&s2);
	SListPushFront(&s2, 2);
	SListPushFront(&s2, 1);
	SListPushFront(&s2, 0);
	SListPushBack(&s2, 3);
	SListPushBack(&s2, 0);
	SListPushBack(&s2, 3);
	SListPushBack(&s2, 0);
	SListPushBack(&s2, 5);
	SListRemove(&s2, 0);
	SListPrint(&s2);
}
void TestSList3()
{
	SList s3;
	SListInit(&s3); 
	SListPushFront(&s3, 2);
	SListPushFront(&s3, 1);
	SListPushFront(&s3, 0);
	SListPushBack(&s3, 3);
	SListPushBack(&s3, 4);
	SListPushBack(&s3, 5);
	SListNode* pos = SListFind(&s3, 3);
	SListInsertAfter(pos, 99);
	SListEraseAfter(pos);
	SListPrint(&s3);
}

int main()
{
	//TestSList1();
	//TestSList2();
	TestSList3();
	system("pause");
	return 0;
}