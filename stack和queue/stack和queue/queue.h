#pragma once
#include<iostream>
#include<vector>
#include<deque>
#include<list>
using namespace std;
namespace mystl
{	//容器进行适配转换
	template<class T, class Container>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		T& front()
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
	private:
		Container _con;
	};
	void test_queue()
	{
		//不能用vector来实现queue，因为vector没有提供pop_front的接口，如果要pop_front的话
		//时间复杂度是O(N),因为需要挪动数据,效率低
		//queue<int, vector<int>> q;
		//queue<int, list<int>> q;
		queue<int, deque<int>> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}