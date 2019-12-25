#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class K,class V>
struct BSTreeNode
{
	BSTreeNode<K,V>* _left;
	BSTreeNode<K,V>* _right;
	K _key;
	V _value;
	BSTreeNode(const K& key, const V& value)
		:_key(key),
		_value(value),
		_left(nullptr),
		_right(nullptr)
	{}

};
template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K,V> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	~BSTree()
	{}
	bool InsertR(const K& key,const V& value)//递归版本
	{
		return _InsertR(_root, key,value);
	}
	bool _InsertR(Node* &root, const K& key, const V& value)//记得用引用，在这里插入才能改变实参的值
		//而且在递归过程中不需要记录父亲节点，因为父亲节点就是递归上一层的根节点
	{
		if (root == nullptr)
		{
			root = new Node(key,value);
		}
		if (root->_key < key)
			return _InsertR(root->_right, key,value);
		else if (root->_key > key)
			return _InsertR(root->_left, key,value);
		else
			return false;
	}
	//bool Insert(const K& key)//树为空或者树不为空
	//{
	//	if (_root == nullptr)
	//	{
	//		_root = new Node(key);
	//		return true;
	//	}
	//	Node* cur = _root;
	//	Node* prev = nullptr;
	//	while (cur != nullptr)
	//	{
	//		prev = cur;
	//		if (key > cur->_key)
	//		{
	//			cur = cur->_right;
	//		}
	//		else if (key < cur->_key)
	//		{
	//			cur = cur->_left;
	//		}
	//		else
	//			return false;
	//	}
	//	cur = new Node(key);
	//	if (key > prev->_key)
	//		prev->_right = cur;
	//	else
	//		prev->_left = cur;
	//	return true;
	//}
	void InOrder()//由于根节点—_root是私有的，无法直接传进去
	{
		_InOrder(_root);
		cout << endl;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " "<<root->_value<<endl;
		_InOrder(root->_right);
	}
	Node* FindR(const K& key)//递归版本查找
	{
		return _FindR(_root, key);
	}
	Node* _FindR(Node* root,const K& key)//递归版本子查找
	{
		if (root == nullptr)
			return nullptr;
		if (root->_key == key)
			return root;
		else if (root->_key > key)
			return _FindR(root->_left, key);
		else
			return _FindR(root->_right, key);
	}
	/*Node* Find(const K& k)
	{
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_key == k)
				return cur;
			else if (cur->_key < k)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		return nullptr;
	}*/
	bool Erase(const K& k)//重点
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur != nullptr)
		{
			if (k > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (k < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到了，进行删除
				//1.被删除的结点左子树为空或者右子树为空(包括被删除结点无子树)
				//2.被删除的结点左右子树均不为空
				Node* del = cur;
				if (cur->_left == nullptr)//左为空
				{
					if (parent == nullptr)//当cur为根节点时
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_right == cur)
							parent->_right = cur->_right;
						else
							parent->_left = cur->_right;
					}	
				}
				else if (cur->_right == nullptr)//右为空
				{
					if (parent == nullptr)//当cur为根节点时
						_root = cur->_left;
					else
					{
						if (parent->_right == cur)
							parent->_right = cur->_left;
						else
							parent->_left = cur->_left;
					}
				}
				else//左右都不为空
					/*让被删除的结点与左子树的最大值或者右子树的最小值进行交换，然后再删除*/
				{
					//初始化很关键，如果初始化为空的话，万一下面的循环没有进去，就会使程序崩溃
					Node* MaxParent = cur;
					Node* LeftMaxNode = cur->_left;
					while (LeftMaxNode->_right != nullptr)
					{
						MaxParent = LeftMaxNode;
						LeftMaxNode = LeftMaxNode->_right;
					}
					cur->_key = LeftMaxNode->_key;
					if (MaxParent->_left == LeftMaxNode)
						MaxParent->_left = LeftMaxNode->_left;
					else
						MaxParent->_right = LeftMaxNode->_right;
					del = LeftMaxNode;
				}
				delete del;
				return true;
			}
		}
		return false;
	}
	bool EraseR(const K& key){}
	bool _EraseR(Node* root, K& key){}
private:
	Node* _root;
};

