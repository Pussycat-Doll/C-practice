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
	bool InsertR(const K& key,const V& value)//�ݹ�汾
	{
		return _InsertR(_root, key,value);
	}
	bool _InsertR(Node* &root, const K& key, const V& value)//�ǵ������ã������������ܸı�ʵ�ε�ֵ
		//�����ڵݹ�����в���Ҫ��¼���׽ڵ㣬��Ϊ���׽ڵ���ǵݹ���һ��ĸ��ڵ�
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
	//bool Insert(const K& key)//��Ϊ�ջ�������Ϊ��
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
	void InOrder()//���ڸ��ڵ㡪_root��˽�еģ��޷�ֱ�Ӵ���ȥ
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
	Node* FindR(const K& key)//�ݹ�汾����
	{
		return _FindR(_root, key);
	}
	Node* _FindR(Node* root,const K& key)//�ݹ�汾�Ӳ���
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
	bool Erase(const K& k)//�ص�
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
				//�ҵ��ˣ�����ɾ��
				//1.��ɾ���Ľ��������Ϊ�ջ���������Ϊ��(������ɾ�����������)
				//2.��ɾ���Ľ��������������Ϊ��
				Node* del = cur;
				if (cur->_left == nullptr)//��Ϊ��
				{
					if (parent == nullptr)//��curΪ���ڵ�ʱ
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
				else if (cur->_right == nullptr)//��Ϊ��
				{
					if (parent == nullptr)//��curΪ���ڵ�ʱ
						_root = cur->_left;
					else
					{
						if (parent->_right == cur)
							parent->_right = cur->_left;
						else
							parent->_left = cur->_left;
					}
				}
				else//���Ҷ���Ϊ��
					/*�ñ�ɾ���Ľ���������������ֵ��������������Сֵ���н�����Ȼ����ɾ��*/
				{
					//��ʼ���ܹؼ��������ʼ��Ϊ�յĻ�����һ�����ѭ��û�н�ȥ���ͻ�ʹ�������
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

