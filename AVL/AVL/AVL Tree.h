#pragma once
#include"commen.h"
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;//balance factor 平衡因子
	pair<K, V> _kv;
	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_kv(kv),
		_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//step1、先按照搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}
		//cur为nullptr
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
			parent->_left = cur;
		cur->_parent = parent;
		//step2、更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;
			if (parent->_bf == 0)//对树的平衡没有影响
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else//parent->_bf == 2 || parent->_bf == -2,paren所在的子树发生了不平衡
			{
				//当前子树不平衡，需要进行旋转
				//1、旋转的前提是保持它依旧是二叉搜索树
				//2、旋转成平衡树
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)//左单旋
						RotateL(parent);
					else //cur->_bf == -1 双旋
						RotateRL(parent);
				}
				else//parent->_bf == -2
				{
					if (cur->_bf == -1)//右单旋
						RotateR(parent);
					else//cur->_bf == 1 双旋
						RotateLR(parent);
				}
				//旋转完成，更新结束
				break;
			}
		}
		return true;
	}
	void RotateL(Node* parent)//左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = subR;
		//判断parent是否为这个树的根
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}
		parent->_bf = subR->_bf = 0;
	}
	void RotateR(Node* parent)//右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR != nullptr)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* pparent = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		subL->_bf = parent->_bf = 0;
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		//根据subRL的平衡因子判断插入结点是在其左边还是右边
		//若是-1则是在左边插入，若是1则是在右边插入。

		RotateR(subR);
		RotateL(parent);

		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if(bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else//bf == 0
		{
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);
		if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subLR->_bf = -1;
			subL->_bf = 0;
		}
		else//bf == 0
		{
			parent->_bf = subLR->_bf = subL->_bf = 0;
		}
	}
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}
	void Inorder()
	{
		_Inorder(_root);
	}
	int Hight(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = Hight(root->_left);
		int right = Hight(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int lefthight = Hight(root->_left);
		int righthight = Hight(root->_right);
		return abs(lefthight - righthight) <= 1
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
private:
	Node* _root = nullptr;
};