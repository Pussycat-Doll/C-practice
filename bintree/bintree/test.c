#define _CRT_SECURE_NO_WARNINGS

#include"commen.h"
#include"bintree.h"

void main()
{

	BinTree tree;
	BinTreeInit(&tree);

	BinTreeCreat(&tree);
	printf("�ö������Ľ�����Ϊ��%d\n",BinTreeSize(tree));

	BinTreePreOrder(tree);
	printf("\n");
	BinTreeInOrder(tree);
	printf("\n");
	BinTreePostOrder(tree);
	printf("\n");
	BinTreeLevelOrder(tree);
	printf("\n");
}