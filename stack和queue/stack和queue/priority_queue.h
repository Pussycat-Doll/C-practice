#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace mystl
{
	template<class T,class Container = vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size()-1);//Ĭ�Ͻ������
		}
		void pop()
		{
			swap(_con[0], _con[_con.size()-1]);
			_con.pop_back();
			adjust_down(0);
		}
		T& top()
		{
			return _con[0];
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		void adjust_up(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child])
				if (com(_con[parent] , _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}
		void adjust_down(int parent)
		{
			Compare com;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				//�Һ��Ӵ���ʱ��ѡ�������д���Ǹ�
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child+1 < _con.size() && com(_con[child] , _con[child + 1]))
					++child;
				//if (_con[parent] < _con[child])
				if (com(_con[parent] , _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}
	private:
		Container _con;
	};
	
	//�º����������������Ķ����������һ��ʹ��
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};
	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
	void test_priority_queue()
	{
		//priority_queue<int> pq;//Ĭ�ϴ��
		priority_queue<int,vector<int>,greater<int>> pq;//С��
		pq.push(3);
		pq.push(2);
		pq.push(4);
		pq.push(1);
		pq.push(5);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}