#include"commen.h"
#include"seqlist.h"

int main()
{
	/*SeqList sq;
	SeqListInit(&sq);

	SeqListPushBack(&sq, 1);
	SeqListPushBack(&sq, 7);
	SeqListPushBack(&sq, 4);
	SeqListPushBack(&sq, 8);
	SeqListPushBack(&sq, 3);
	SeqListPushBack(&sq, 2);
	SeqListPushBack(&sq, 9);
	SeqListPushBack(&sq, 0);
	SeqListPushBack(&sq, 8);
	SeqListShow(&sq);*/

	/*SeqList sq1;
	SeqListInit(&sq1);

	SeqListPushFront(&sq1, 0);
	SeqListPushFront(&sq1, 1);
	SeqListPushFront(&sq1, 2);
	SeqListPushFront(&sq1, 3);
	SeqListPushFront(&sq1, 4);
	SeqListPushFront(&sq1, 5);
	SeqListPushFront(&sq1, 6);
	SeqListPushFront(&sq1, 7);
	SeqListPushFront(&sq1, 8);
	SeqListShow(&sq1);*/

	/*SeqListPopBack(&sq1);
	SeqListPopBack(&sq1);
	SeqListPopBack(&sq1);
	SeqListPopBack(&sq1);
	SeqListPopBack(&sq1);
	SeqListPopBack(&sq1);
	SeqListPopBack(&sq1);
	SeqListPopBack(&sq1);
	SeqListPopBack(&sq1);*/

	/*SeqListPopFront(&sq1);
	SeqListShow(&sq1);
	SeqListPopFront(&sq1);
	SeqListShow(&sq1);
	SeqListPopFront(&sq1);
	SeqListShow(&sq1);
	SeqListPopFront(&sq1);
	SeqListShow(&sq1);
	SeqListPopFront(&sq1);
	SeqListPopFront(&sq1);
	SeqListPopFront(&sq1);
	SeqListPopFront(&sq1);
	SeqListPopFront(&sq1);
	SeqListPopFront(&sq1);*/

	//SeqList sq2;
	//SeqListInit(&sq2);

	//SeqListInsertPos(&sq2, 0, 0);
	//SeqListShow(&sq2);
	////SeqListInsertPos(&sq2, 2, 2);
	//SeqListInsertPos(&sq2, 0, 2);
	//SeqListShow(&sq2);
	//SeqListInsertPos(&sq2, 1, 8);
	//SeqListShow(&sq2);
	//SeqListInsertPos(&sq2, 1, 7);
	//SeqListInsertPos(&sq2, 1, 6);
	//SeqListInsertPos(&sq2, 3, 8);

	SeqList sq3;
	SeqListInit(&sq3);

	SeqListInsertByVal(&sq3, 4);
	SeqListShow(&sq3);
	SeqListInsertByVal(&sq3, 1);
	SeqListShow(&sq3);
	SeqListInsertByVal(&sq3, 9);
	SeqListShow(&sq3);
	SeqListInsertByVal(&sq3, 2);
	SeqListShow(&sq3);
	SeqListInsertByVal(&sq3, 6);
	SeqListShow(&sq3);
	SeqListInsertByVal(&sq3, 0);
	SeqListShow(&sq3);
	SeqListInsertByVal(&sq3, 4);
	SeqListShow(&sq3);
	SeqListInsertByVal(&sq3, 7);
	SeqListShow(&sq3);
	SeqListInsertByVal(&sq3, 8);

	printf("元素%d的位置为%d",SeqListBinarySearch(&sq3, 9));
	SeqListDestory(&sq3);

	/*SeqListErasePos(&sq3, 7);
	SeqListShow(&sq3);
	SeqListErasePos(&sq3, 6);
	SeqListShow(&sq3);
	SeqListErasePos(&sq3, 1);
	SeqListShow(&sq3);
	SeqListErasePos(&sq3, 0);
	SeqListShow(&sq3);
	SeqListErasePos(&sq3, 2);
	SeqListShow(&sq3);*/

	/*SeqListEraseVal(&sq3, 8);
	SeqListShow(&sq3);
	SeqListEraseVal(&sq3, 9);
	SeqListShow(&sq3);
	SeqListEraseVal(&sq3, 7);
	SeqListShow(&sq3);
	SeqListEraseVal(&sq3, 0);
	SeqListShow(&sq3);
	SeqListEraseVal(&sq3, 3);
	SeqListShow(&sq3);
	SeqListEraseVal(&sq3, 9);
	SeqListShow(&sq3);*/

	/*SeqListSort(&sq);
	SeqListShow(&sq);*/

	return 0;
}