#pragma once
#include"commen.h"
enum Color
{
	BLACK,
	RED,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Color _col;
	RBTreeNode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_col(RED)
	{}
};
template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
public:
	RBTreeIterator(Node* n = nullptr)
		:node(n)
	{}
	//����ָ�����Ƶķ���
	T& operator* ()
	{
		return node->_data;
	}
	T* operator->()
	{
		return &(operator* ());
	}
	//Ҫ�ܹ��ƶ�

	Self& ++operator()
	{
		Increment();
		return *this;
	}
	Self& operator++(int)
	{
		Self tmp(*this);
		Increment();
		return *this;
	}
	Self& --operator()
	{
		Decrement();
		return *this;
	}
	Self& operator--(int)
	{
		Self tmp(*this);
		Decrement();
		return *this;
	}
	//�ұ�it��Ľ�㣬���it��Ӧ�������������ڣ�Ӧ����������������С��(������)���
	//���it��Ӧ���������������ڣ�Ӧ������˫���в���Ѱ��
	void Increment()//�ҵ�ǰ����������һ��λ��
	{
		if (node->_right)
		{
			node = node->_right//����������;
			while (node->_left)
				node = node->_left;
		}
		else//������������
		{
			Node* parent = node->_parent;
			while (parent && node == parent->_right)
			{
				node = parent;
				parent = node->_parent;
			}
			//��node�����ӣ�ѭ����ֹ
			if(node->_right != parent)
				node = parent;
		}
	}
	//�ұ�itС�Ľ�㣬���it�����������ڣ���ô�����������ұߵĽ�㼴Ϊ��itС��ǰһ�����
	//���it�������������ڣ���ô������˫�׽�㣨cur == parent->right��
	void Decrement()//�ҵ�ǰ��������ǰһ��λ��
	{
		if (node == node->_parent->_parent && RED == node->_col)
		{
			//Node��end()��λ��
			node = node->_right;
		}
		else if (node->_left)
		{
			node = node->_left;//����������
			while (node->_right)
				node = node->_right;
		}
		else
		{
			Node* parent = node->_parent;
			while (parent && parent->_left == node)
			{
				node = parent;
				parent = node->_parent;
			}
				node = parent;
		}
	}
	//�ܹ��Ƚ�
	bool operator !=(const Self& s)const
	{
		return node != s.node;
	}
	bool operator ==(const Self& s)const
	{
		return node == s.node;
	}
private:
	Node* node;
};
//map->RBTree<K,pair<K,V>>
//set->RBTree<K,K>

//KeyOfValue��ʾ��δ�T����ȡkey
template<class K,class T,class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;
	///////////////////////////////////////������
	iterator begin()
	{
		return iterator(head->_left);
	}
	iterator end()
	{
		return iterator(head);
	}
	///////////////////////////////////////
	pair<Node*, bool> Insert(const T& data)
	{
		//1.���ն����������Ĺ�����в���
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair<_root,true>;
		}
		KeyOfValue kov;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur != nullptr)
		{
			if (kov(cur->_data) < kov(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kov(cur->_data) > kov(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return make_pair(cur,false);
		}
		//�ҵ��������λ��cur
		cur = new Node(data);
		if (kov(parent->_data) > kov(data))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;
		//������½����Ϊ��ɫ��Ϊ��ɫ֮��Ҳ���ܲ���Ҫ����
		cur->_col = RED;
		while (parent && parent->_col == RED)
		{
			//������ĵ��ڿ�����
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//���1:��ɫ
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}//���2��3:��ת+��ɫ
				else
				{
					//�������˫���䵥��
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}//�ڶ������
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
				}

			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{//uncle������Ϊ��
					grandfather->_col = RED;
					parent->_col = uncle->_col = BLACK;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{//uncle��������Ϊ��ɫ
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
						//�ѵ��������ת��Ϊ�ڶ������
					}
					RotateL(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
				}

			}
		}

		_root->_col = BLACK;
		return make_pair(cur,true);
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
	}
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_data << endl;
		_Inorder(root->_right);
	}
	void Inorder()
	{
		_Inorder(_root);
	}
	iterator Find(const T& data)
	{
		Node* cur = _root;
		KeyOfValue kov;
		while (cur)
		{
			if (kov(data) == kov(cur->_data))
				return iterator(cur);
			else if (kov(data) < kov(cur->_data))
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return end();
	}
private:
	Node* _root = nullptr;

};