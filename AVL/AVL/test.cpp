#include"AVL Tree.h"


int main()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));//�������֤���Ƕ���������
	}
	t.Inorder();
	cout<<t.IsBalance()<<endl;//��Ҫ�ж�������Ƿ�߶�ƽ��
	return 0;
}