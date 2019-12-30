#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void TestSeqList1()
{
	size_t i = 0;
	SeqList s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 0);
	SeqListPushFront(&s1, 4);
	//SeqListPopBack(&s1);
	//SeqListPopFront(&s1);
	SeqListBubbleSort(&s1);
	for (i = 0; i < SeqListSize(&s1); i++)
	{
		printf("%d\n",SeqListAt(&s1, i));
	}
	//printf("%d\n", SeqListFind(&s1, 3));
	printf("%d\n", SeqListBinaryFind(&s1,0));
	printf("%d\n", SeqListBinaryFind(&s1, 1));
	printf("%d\n", SeqListBinaryFind(&s1, 2));
	printf("%d\n", SeqListBinaryFind(&s1, 7));

	SeqListDestory(&s1);
}

void TestSeqList2()
{
	SeqList s2;
	SeqListInit(&s2);
	SeqListPushFront(&s2, 1);
	SeqListPushFront(&s2, 0);
	SeqListPushFront(&s2, 99);
	SeqListPushBack(&s2, 2);
	SeqListPushBack(&s2, 99);
	SeqListPushBack(&s2, 3);
	SeqListPushBack(&s2, 4);
	SeqListRemoveAll(&s2, 99);
	for (size_t i = 0; i < SeqListSize(&s2); i++)
	{
		printf("%d\n", SeqListAt(&s2, i));
	}

}
int main()
{
	//TestSeqList1();
	TestSeqList2();
	system("pause");
	return 0;
}