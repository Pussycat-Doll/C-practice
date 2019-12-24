#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<list>
#include<assert.h>
#include<algorithm>
using namespace std;
namespace qwq
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;

		_list_node(const T& x)
			:_data(x),
			_next(nullptr),
			_prev(nullptr)
		{ }
	};
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_iterator<T> node;
		typedef __list_iterator<T, Ref, Ptr> Self;
		node* _node;//定义一个结点指针

		__list_iterator(node* node)
			:_node(node);
		{}
		Ref operator*()//重载解引用
		{
			return _node->_data;
		}
		Self& operator++()//前置++
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self& operator++(int)//后置++
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--(int)
		{
			__list_iterator<T> temp(*this);
			_node = _node->_prev;
			return temp;
		}
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
	};
	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*>, iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		//void push_back(const T& x)
		//{
		//	node* tail = _head->_prev;
		//	node* newnode = new node(x);
		//	//head ... tail newnode
		//	//head  newnode tail
		//	tail->_next = newnode;
		//	newnode->_prev = tail;
		//	newnode->_next = _head;
		//	_head->_prev = newnode;
		//}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);
			prev->_next = newnode;// prev newnode cur
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		void erase(iterator pos)
		{
			node* cur = pos._node;
			assert(cur != _head);
			node* prev = cur->_prev;
			node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete[] cur;
		}
	private:
		node* _head;
	};
	template<class T>
	void print_list(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			*it = 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
};
	void test1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		//print_list(l);
	}
int main()
{
	test1();
	system("pause");
	return 0;
}