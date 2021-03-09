#pragma once
#include"commen.h"
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;//balance factor ƽ������
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
		//step1���Ȱ����������Ĺ�����в���
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
		//curΪnullptr
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
			parent->_left = cur;
		cur->_parent = parent;
		//step2������ƽ������
		while (parent)
		{
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;
			if (parent->_bf == 0)//������ƽ��û��Ӱ��
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else//parent->_bf == 2 || parent->_bf == -2,paren���ڵ����������˲�ƽ��
			{
				//��ǰ������ƽ�⣬��Ҫ������ת
				//1����ת��ǰ���Ǳ����������Ƕ���������
				//2����ת��ƽ����
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)//����
						RotateL(parent);
					else //cur->_bf == -1 ˫��
						RotateRL(parent);
				}
				else//parent->_bf == -2
				{
					if (cur->_bf == -1)//�ҵ���
						RotateR(parent);
					else//cur->_bf == 1 ˫��
						RotateLR(parent);
				}
				//��ת��ɣ����½���
				break;
			}
		}
		return true;
	}
	void RotateL(Node* parent)//����
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = subR;
		//�ж�parent�Ƿ�Ϊ������ĸ�
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
	void RotateR(Node* parent)//�ҵ���
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
		//����subRL��ƽ�������жϲ�������������߻����ұ�
		//����-1��������߲��룬����1�������ұ߲��롣

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