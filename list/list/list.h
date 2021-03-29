#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace mystl
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _data;

		__list_node(const T& x = T())
			:_next(nullptr),
			_prev(nullptr),
			_data(x)
		{}
	};

	//__list_iterator<T,T&,T*> 调用 iterator
	//__list_iterator<T,const T&,const T*>调用 const_iterator
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &(_node->_data);
		}
		Self& operator++()//前置++
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator--()//前置--
		{
			_node = _node->_prev;
			return *this;
		}
		Self& operator++(int)//后置++
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;;
		}
		Self& operator--(int)//后置--
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> Node;
	public://带头双向循环链表
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(const list<T>& l)//深拷贝
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			/*list<int>::const_iterator it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}*/
			for (auto e : l)
			{
				push_back(e);
			}
		}
		//l1 = l2;
	/*	list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (auto e : lt)
				{
					push_back(e);
				}
			}
			return *this;
		}*/
		list<T>& operator=(list<T> lt)//现代写法——通过传参产生临时拷贝的方式
		{
			swap(_head, lt._head);
			return *this;
			//lt出了作用域之后，析构函数会销毁掉lt，也就是交换之前的_head
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()//最后一个的下一位
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const//最后一个的下一位
		{
			return const_iterator(_head);
		}
		void push_back(const T& x)
		{
			//Node* newnode = new Node(x);
			//Node* tail = _head->_prev;
			////只有头结点的情况也适用
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;
			insert(end(), x);
		}
		void pop_back()
		{
			/*if (_head->_next != _head)
			{
				Node* tail = _head->_prev;
				tail->_prev->_next = _head;
				_head->_prev = tail->_prev;
				delete tail;
				tail = nullptr;
			}*/
			erase(--end());
		}
		void push_front(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* first = _head->_next;
			_head->_next = newnode;
			newnode->_next = first;
			newnode->_prev = _head;
			first->_prev = newnode;*/
			insert(begin(), x);
		}
		void pop_front()
		{
			/*if (_head->_next != _head)
			{
				Node* first = _head->_next;
				_head->_next = first->_next;
				first->_next->_prev = _head;
				delete first;
				first = nullptr;
			}*/
			erase(begin());
		}	
		void insert(iterator pos,const T& x)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(x);
			cur->_prev->_next = newnode;
			newnode->_next = cur;
			newnode->_prev = cur->_prev;
			cur->_prev = newnode;
		}
		void erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			cur = nullptr;
		}
	private:
		Node* _head;
	};

	void test1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	struct Date
	{
		int _year = 0;
		int _month = 1;
		int _day = 1;
	};

	void test2()
	{
		list<Date> l;
		l.push_back(Date());
		l.push_back(Date());
		l.push_back(Date());
		list<Date>::iterator it = l.begin();
		while (it != l.end())
		{
			
			//cout << *it << " ";//没有重载<<Date--->opeator->
			cout << it->_year <<"-"<< it->_month <<"-"<< it->_day;
			//这里原本是it->->但是为了提高代码可读性，处理成了it->
			cout << (*it)._year << "-" << (*it)._month << "-" << (*it)._day;

			++it;
		}
		cout << endl;

	}
	void print_list(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test3()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(5);
		l1.push_back(4);

		print_list(l1);
	}
	void test4()
	{
		list<int> l;
		l.push_front(1);
		l.push_front(2);
		l.push_front(3);
		l.push_front(4);
		l.push_front(5);

		l.pop_front();
		l.pop_back();
		l.insert(l.end(), 99);
		l.insert(l.begin(), 199);
		l.erase(l.begin());
		//l.erase(l.end());
		print_list(l);

		list<int> l2(l);
		print_list(l2);

		list<int> l3;
		l3.push_back(1);
		l3.push_back(3);
		l3.push_back(5);
		l3.push_back(7);
		l3 = l;
		print_list(l3);
	}
}