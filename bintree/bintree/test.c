#define _CRT_SECURE_NO_WARNINGS

#include"commen.h"
//#include"bintree.h"
#include"heap.h"

//ABCDEFGH
//CBEDFAGH
//CEFDBHGA
void main()
{
	/*
	const char* s = "ABD##E##CF##G##";
	int index = 0;
	BinTree tree;
	BinTreeInit(&tree);
	//BinTreeCreat(&tree);
	//tree = BinTreeCreat_1();
	//tree = BinTreeCreat_2(s, &index);
	const char* vlr = "ABCDEFGH";
	const char* lvr = "CBEDFAGH";
	const char* lrv = "CEFDBHGA";
	//tree = BinTreeCreat_3(vlr,lvr,strlen(vlr));
	tree = BinTreeCreat_4(lvr, lrv, strlen(lvr));

	printf("该二叉树的结点个数为：%d\n",BinTreeSize(tree));

	BinTreePreOrder(tree);
	printf("\n");
	BinTreeInOrder(tree);
	printf("\n");
	BinTreePostOrder(tree);
	printf("\n");
	BinTreeLevelOrder(tree);
	printf("\n");

	printf("当前二叉树的高度为：%d\n", Hight(tree));

	BinTreeNode* p = BinTreeFind(tree, 'C');
	BinTreeNode* ptr = BinTreeParent(tree, p);

	BinTreeNode* bt = BinTreeClone(tree);
	BinTreeLevelOrder(bt);
	printf("\n");
	printf("%d\n",Equal(tree, bt));

	BinTreePreOrder_No(tree);
	printf("\n");
	BinTreeInOrder_No(tree);
	printf("\n");
	BinTreePostOrder_No(tree);
	printf("\n");
	*/

	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MinHeap mhp;
	HeapInit(&mhp, 10);

	for (int i = 0; i < n; ++i)
	{
		HeapInsert(&mhp, arr[i]);
	}
	HeapShow(mhp);

	
}