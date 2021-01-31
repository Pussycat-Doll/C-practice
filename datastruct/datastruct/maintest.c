#define _CRT_SECURE_NO_WARNINGS

#include"commen.h"
#include"seqlist.h"



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
		printf("��ѡ��->\n");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 0:
			select = 0;
			break;
		case 1:
			printf("������Ҫ�����Ԫ�أ���Ҫ�˳�������-1->\n");
			while (scanf("%d", &item),item != -1)
			{
				SeqListPushBack(&list, item);
			}
			break;
		case 2:
			printf("������Ҫ�����Ԫ�أ���Ҫ�˳�������-1->\n");
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
			printf("������Ҫ�����λ��->\n");
			scanf("%d", &pos);
			printf("������Ҫ�����Ԫ��->\n");
			scanf("%d", &item);
			SeqListInsertByPos(&list, pos, item);
			break;
		case 7:
			printf("������Ҫ�����Ԫ��->\n");
			scanf("%d", &item);
			SeqListInsertByVal(&list, item);
			break;
		case 8:
			printf("������Ҫɾ����λ��->\n");
			scanf("%d", &pos);
			SeqListEraseByPos(&list, pos);
			break;
		case 9:
			printf("������Ҫɾ����Ԫ��->\n");
			scanf("%d", &item);
			SeqListEraseByVal(&list, item);
			break;
		case 10:
			printf("������Ҫ���ҵ�Ԫ��->\n");
			scanf("%d", &item);
			pos = SeqListFind(&list, item);
			if (pos == -1)
				printf("Ԫ��%d������\n",item);
			else
				printf("Ԫ��%d�����±�Ϊ%d", item, pos);
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
				printf("��˳���Ϊ�գ��޷���ȡ��ͷ��Ԫ��\n");
			else
				printf("ͷԪ��Ϊ%d\n", SeqListFront(&list));
			break;
		case 17:
			if (SeqListBack(&list) == -1)
				printf("��˳���Ϊ�գ��޷���ȡ��β��Ԫ��\n");
			else
				printf("ĩβԪ��Ϊ%d\n", SeqListBack(&list));
			break;
		case 18:
			printf("������Ҫ���ҵ�Ԫ��->\n");
			scanf("%d", &item);
			pos = SeqListBinarySearch(&list, item);
			if (pos == -1)
				printf("Ԫ��%d������\n", item);
			else
				printf("Ԫ��%d�����±�Ϊ%d", item, pos);
			break;
		case 19:
			SeqListEraseAll(&list);
			break;
		default:
			printf("����Ƿ���������ѡѡ��->\n");
			break;
		}
		Sleep(900);
		system("cls");

	}
	SeqListDestory(&list);
return 0;
}