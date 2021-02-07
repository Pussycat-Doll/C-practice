#define _CRT_SECURE_NO_WARNINGS

#include"commen.h"

//#include"seqlist.h"
//#include"slist.h"

#include"sclist.h"
/*
int main()
{
	
	SeqList list;
	SeqListInit(&list);

	DateType item;
	int select = 1;
	size_t pos;
	while (select)
	{
		printf("**************************************************\n");
		printf("***********************MENU***********************\n");
		printf("*  [1]push_back                   [2]push_front  *\n");
		printf("*  [3]show_list                   [0]quit_system *\n");
		printf("*  [4]pop_back                    [5]pop_front   *\n");
		printf("*  [6]insert_pos                  [7]insert_val  *\n");
		printf("*  [8]erase_pos                   [9]erase_val   *\n");
		printf("*  [10]find                       [11]length     *\n");
		printf("*  [12]capacity                   [13]sort       *\n");
		printf("*  [14]reverse                    [15]clear      *\n");
		printf("*  [16]front                      [17]back       *\n");
		printf("*  [18]binary_search              [19]earse_all  *\n");
		printf("**************************************************\n");
		printf("请选择->\n");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 0:
			select = 0;
			break;
		case 1:
			printf("请输入要插入的元素，若要退出，输入-1->\n");
			while (scanf("%d", &item),item != -1)
			{
				SeqListPushBack(&list, item);
			}
			break;
		case 2:
			printf("请输入要插入的元素，若要退出，输入-1->\n");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&list, item);
			}
			break;
		case 3:
			SeqListShow(&list);
			break;
		case 4:
			SeqListPopBack(&list);
			break;
		case 5:
			SeqListPopFront(&list);
			break;
		case 6:
			printf("请输入要插入的位置->\n");
			scanf("%d", &pos);
			printf("请输入要插入的元素->\n");
			scanf("%d", &item);
			SeqListInsertByPos(&list, pos, item);
			break;
		case 7:
			printf("请输入要插入的元素->\n");
			scanf("%d", &item);
			SeqListInsertByVal(&list, item);
			break;
		case 8:
			printf("请输入要删除的位置->\n");
			scanf("%d", &pos);
			SeqListEraseByPos(&list, pos);
			break;
		case 9:
			printf("请输入要删除的元素->\n");
			scanf("%d", &item);
			SeqListEraseByVal(&list, item);
			break;
		case 10:
			printf("请输入要查找的元素->\n");
			scanf("%d", &item);
			pos = SeqListFind(&list, item);
			if (pos == -1)
				printf("元素%d不存在\n",item);
			else
				printf("元素%d所在下标为%d", item, pos);
			break;
		case 11:
			printf("length = %d\n", SeqListLength(&list));
			break;
		case 12:
			printf("capacity = %d\n", SeqListCapacity(&list));
			break;
		case 13:
			SeqListSort(&list);
			break;
		case 14:
			SeqListReverse(&list);
			break;
		case 15:
			SeqListClean(&list);
			break;
		case 16:
			if(SeqListFront(&list) == -1)
				printf("该顺序表为空，无法获取其头部元素\n");
			else
				printf("头元素为%d\n", SeqListFront(&list));
			break;
		case 17:
			if (SeqListBack(&list) == -1)
				printf("该顺序表为空，无法获取其尾部元素\n");
			else
				printf("末尾元素为%d\n", SeqListBack(&list));
			break;
		case 18:
			printf("请输入要查找的元素->\n");
			scanf("%d", &item);
			pos = SeqListBinarySearch(&list, item);
			if (pos == -1)
				printf("元素%d不存在\n", item);
			else
				printf("元素%d所在下标为%d", item, pos);
			break;
		case 19:
			SeqListEraseAll(&list);
			break;
		default:
			printf("输入非法，请重新选选择->\n");
			break;
		}
		Sleep(900);
		system("cls");

	}
	SeqListDestory(&list);
return 0;
}*/
///////////////////////////////////////////////////////////////////////

//int main()
//{
//	SList list;
//	SListInit(&list);
//
//	SListNode* p = NULL;
//	ElemType item;
//	int select = 1;
//	size_t pos;
//	while (select)
//	{
//		printf("**************************************************\n");
//		printf("***********************MENU***********************\n");
//		printf("*  [1]push_back                   [2]push_front  *\n");
//		printf("*  [3]show_list                   [0]quit_system *\n");
//		printf("*  [4]pop_back                    [5]pop_front   *\n");
//		printf("*  [6]insert_val                  [7]erase_val   *\n");
//		printf("*  [8]find                        [9]length      *\n");
//		printf("*  [10]earse_all                  [11]sort       *\n");
//		printf("*  [12]reverse                    [13]clean      *\n");
//		printf("*  [14]front                      [15]back       *\n");
//		printf("**************************************************\n");
//		printf("**************************************************\n");
//		printf("请选择->\n");
//		scanf("%d", &select);
//		if (select == 0)
//			break;
//		switch (select)
//		{
//		case 0:
//			select = 0;
//			break;
//		case 1:
//			printf("请输入要插入的元素，若要退出，输入-1->\n");
//			while (scanf("%d", &item), item != -1)
//			{
//				SListPushBack(&list, item);
//			}
//			break;
//		case 2:
//			printf("请输入要插入的元素，若要退出，输入-1->\n");
//			while (scanf("%d", &item), item != -1)
//			{
//				SListPushFront(&list, item);
//			}
//			break;
//		case 3:
//			SListShow(list);
//			break;
//		case 4:
//			SListPopBack(&list);
//			break;
//		case 5:
//			SListPopFront(&list);
//			break;
//		case 6:
//			printf("请输入要插入的元素->\n");
//			scanf("%d", &item);
//			SListSort(&list);
//			SListInsertByVal(&list, item);
//			break;
//		case 7:
//			printf("请输入要删除的元素->\n");
//			scanf("%d", &item);
//			SListEraseByVal(&list, item);
//			break;
//		case 8:
//			printf("请输入要查找的元素->\n");
//			scanf("%d", &item);
//			p = SListFind(list, item);
//			if (p == NULL)
//				printf("元素%d不存在\n", item);
//			else
//				printf("元素%d所在的位置为%d", item, p);
//			break;
//		case 9:
//			printf("length = %d\n", SListLength(list));
//			break;
//		case 10:
//			printf("请输入要删除的元素->\n");
//			scanf("%d", &item);
//			SListEraseAll(&list,item);
//			break;
//		case 11:
//			SListSort(&list);
//			break;
//		case 12:
//			SListReverse(&list);
//			break;
//		case 13:
//			SListClean(&list);
//			break;
//		case 14:
//			if (SListFront(&list) == -1)
//				printf("该顺序表为空，无法获取其头部元素\n");
//			else
//				printf("头元素为%d\n", SListFront(&list));
//			break;
//		case 15:
//			if (SListBack(&list) == -1)
//				printf("该顺序表为空，无法获取其尾部元素\n");
//			else
//				printf("末尾元素为%d\n", SListBack(&list));
//			break;
//		default:
//			printf("输入非法，请重新选选择->\n");
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//	SListDestroy(&list);
//	return 0;
//}


int main()
{
	SCList list;
	SCListInit(&list);

	SCListNode* p = NULL;
	ElemType item;
	int select = 1;
	size_t pos;
	while (select)
	{
		printf("**************************************************\n");
		printf("***********************MENU***********************\n");
		printf("*  [1]push_back                   [2]push_front  *\n");
		printf("*  [3]show_list                   [0]quit_system *\n");
		printf("*  [4]pop_back                    [5]pop_front   *\n");
		printf("*  [6]insert_val                  [7]erase_val   *\n");
		printf("*  [8]find                        [9]length      *\n");
		printf("*  [10]earse_all                  [11]sort       *\n");
		printf("*  [12]reverse                    [13]clean      *\n");
		printf("*  [14]front                      [15]back       *\n");
		printf("**************************************************\n");
		printf("**************************************************\n");
		printf("请选择->\n");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 0:
			select = 0;
			break;
		case 1:
			printf("请输入要插入的元素，若要退出，输入-1->\n");
			while (scanf("%d", &item), item != -1)
			{
				SCListPushBack(&list, item);
			}
			break;
		case 2:
			printf("请输入要插入的元素，若要退出，输入-1->\n");
			while (scanf("%d", &item), item != -1)
			{
				SCListPushFront(&list, item);
			}
			break;
		case 3:
			SCListShow(list);
			break;
		case 4:
			SCListPopBack(&list);
			break;
		case 5:
			SCListPopFront(&list);
			break;
		case 6:
			printf("请输入要插入的元素->\n");
			scanf("%d", &item);
			SCListSort(&list);
			SCListInsertByVal(&list, item);
			break;
		case 7:
			printf("请输入要删除的元素->\n");
			scanf("%d", &item);
			SCListEraseByVal(&list, item);
			break;
		case 8:
			printf("请输入要查找的元素->\n");
			scanf("%d", &item);
			p = SCListFind(list, item);
			if (p == NULL)
				printf("元素%d不存在\n", item);
			else
				printf("元素%d所在的位置为%d", item, p);
			break;
		case 9:
			printf("length = %d\n", SCListLength(list));
			break;
		case 10:
			printf("请输入要删除的元素->\n");
			scanf("%d", &item);
			SCListEraseAll(&list, item);
			break;
		case 11:
			SCListSort(&list);
			break;
		case 12:
			SCListReverse(&list);
			break;
		case 13:
			SCListClean(&list);
			break;
		case 14:
			if (SCListFront(&list) == -1)
				printf("该顺序表为空，无法获取其头部元素\n");
			else
				printf("头元素为%d\n", SCListFront(&list));
			break;
		case 15:
			if (SCListBack(&list) == -1)
				printf("该顺序表为空，无法获取其尾部元素\n");
			else
				printf("末尾元素为%d\n", SCListBack(&list));
			break;
		default:
			printf("输入非法，请重新选选择->\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SCListDestroy(&list);
	return 0;
}