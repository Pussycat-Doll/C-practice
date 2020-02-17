#pragma once
#include<iostream>
using namespace std;
template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _root;

	std::pair<K, V> _kv;
	int _bf;//平衡因子

	AVLTreeNode(const std::pair<K,V>& kv)
		:_left(nullptr),
		_right(nullptr),
		_root(nullptr),
		_bf(0),
		_kv(kv)
	{}
};
template<class K,class V>
class AVLtree
{
	typedef AVLTreeNode<K, V> Node;
private:
	Node* _root;
public:
	AVLtree()
		:_root(nullptr)
	{}
	V& operator[](const K& key)
	{
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		return ret.first->_kv.second;
	}
	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			parent = cur;
			if (cur->_kv.second < kv.second)
				cur = cur->_right;
			else if (cur->_kv.second > kv.second)
				cur = cur->_left;
			else
				return make_pair(cur, false);//该结点已存在,插入失败
		}
		//成功找到插入结点的位置
		cur = new Node(kv);
		if (parent->_kv.second < cur->_kv.second)
			parent->_right = cur;
		else
			parent->_left = cur;
		cur->_root = parent;
		return make_pair(cur, true);
	}
};

void testAVL1()
{
	AVLtree<int, double> avl;
	avl.Insert(make_pair(1, 1.1));
	avl.Insert(make_pair(2, 6.6));
	avl[3];
	avl[3] = 5.5;
}

