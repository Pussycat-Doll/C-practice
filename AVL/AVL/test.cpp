#include"AVL Tree.h"


int main()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));//中序遍历证明是二叉搜索树
	}
	t.Inorder();
	cout<<t.IsBalance()<<endl;//还要判断这棵树是否高度平衡
	return 0;
}