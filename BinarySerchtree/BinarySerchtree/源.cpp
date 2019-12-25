#define _CRT_SECURE_NO_WARNINGS 1
//搜索二叉树的时间复杂度为：
//最优情况下为：O(logN)
//最差情况下为:O(N)---N/2
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
//	//测试根据代码逻辑设置(白盒测试)
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
	BS.InsertR("白色", "white");
	BS.InsertR("黑色", "black");
	BS.InsertR("绿色", "green");
	BS.InsertR("黄色", "yellow");
	BS.InOrder();
}
void testBStreeKV2()
{
	string str[] = { "草莓", "苹果", "猕猴桃", "香蕉","香蕉", "苹果" };
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