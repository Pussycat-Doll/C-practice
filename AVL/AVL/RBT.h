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
	//具有指针类似的方法
	T& operator* ()
	{
		return node->_data;
	}
	T* operator->()
	{
		return &(operator* ());
	}
	//要能够移动

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
	//找比it大的结点，如果it对应结点的右子树存在，应该在其右子树找最小的(最左侧的)结点
	//如果it对应结点的右子树不存在，应该在其双亲中不断寻找
	void Increment()//找当前迭代器的下一个位置
	{
		if (node->_right)
		{
			node = node->_right//右子树存在;
			while (node->_left)
				node = node->_left;
		}
		else//右子树不存在
		{
			Node* parent = node->_parent;
			while (parent && node == parent->_right)
			{
				node = parent;
				parent = node->_parent;
			}
			//当node是左孩子，循环终止
			if(node->_right != parent)
				node = parent;
		}
	}
	//找比it小的结点，如果it的左子树存在，那么左子树的最右边的结点即为比it小的前一个结点
	//如果it的左子树不存在，那么找它的双亲结点（cur == parent->right）
	void Decrement()//找当前迭代器的前一个位置
	{
		if (node == node->_parent->_parent && RED == node->_col)
		{
			//Node在end()的位置
			node = node->_right;
		}
		else if (node->_left)
		{
			node = node->_left;//左子树存在
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
	//能够比较
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

//KeyOfValue表示如何从T中提取key
template<class K,class T,class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;
	///////////////////////////////////////迭代器
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
		//1.按照二叉搜索树的规则进行插入
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
		//找到插入结点的位置cur
		cur = new Node(data);
		if (kov(parent->_data) > kov(data))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;
		//插入的新结点置为红色置为红色之后也可能不需要调整
		cur->_col = RED;
		while (parent && parent->_col == RED)
		{
			//红黑树的调节看叔叔
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//情况1:变色
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}//情况2、3:旋转+变色
				else
				{
					//情况三：双旋变单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}//第二种情况
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
				}

			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{//uncle存在且为红
					grandfather->_col = RED;
					parent->_col = uncle->_col = BLACK;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{//uncle不存在且为黑色
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
						//把第三种情况转化为第二种情况
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