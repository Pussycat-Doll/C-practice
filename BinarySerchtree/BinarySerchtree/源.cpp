#define _CRT_SECURE_NO_WARNINGS 1
//������������ʱ�临�Ӷ�Ϊ��
//���������Ϊ��O(logN)
//��������Ϊ:O(N)---N/2
#include<cstdlib>
#include"BST.h"

//void testBST1()
//{
//	int a[] = {5,3,4,1,7,8,2,6,0,9};
//	BSTree<int> tree;
//	for (auto e : a)
//	{
//		tree.Insert(e);
//	}
//	tree.InOrder();
//	//���Ը��ݴ����߼�����(�׺в���)
//	tree.erase(2);
//	tree.erase(8);
//	tree.erase(1);
//	tree.erase(7);
//	tree.erase(5);
//	tree.InOrder();
//
//}
//void testBST2()
//{
//	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
//	BSTree<int> tree;
//	for (auto e : a)
//	{
//		tree.InsertR(e);
//	}
//	tree.InOrder();
//}
void testBStreeKV1()
{
	BSTree<string, string> BS;
	BS.InsertR("��ɫ", "white");
	BS.InsertR("��ɫ", "black");
	BS.InsertR("��ɫ", "green");
	BS.InsertR("��ɫ", "yellow");
	BS.InOrder();
}
void testBStreeKV2()
{
	string str[] = { "��ݮ", "ƻ��", "⨺���", "�㽶","�㽶", "ƻ��" };
	BSTree<string, int> fruittimes;
	for (auto &e : str)
	{
		BSTreeNode<string, int>* Node = fruittimes.FindR(e);
		if (Node)
			Node->_value++;
		else
			fruittimes.InsertR(e, 1);
	}
	fruittimes.InOrder();
}
int main()
{
	//testBST1();
	//testBST2();
	//testBStreeKV1();
	testBStreeKV2();
	system("pause");
	return 0;
}