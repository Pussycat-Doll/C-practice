#pragma once
#include<iostream>
#include<cassert>
using namespace std;

namespace my_vector
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()
			:_start(nullptr),
			_end(nullptr),
			_endofstorage(nullptr)
		{}
		~vector()
		{
			delete[] _start;
			_start = _end = _endofstorage = nullptr;
		}
		size_t size()
		{
			return _end - _start;
		}
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _end;
		}
		void resize(size_t n, const T& x = T())
		{
			if (n < size())
			{
				_end -= n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				for (size_t i = size(); i < n; ++i)
				{
					*(_start + i) = x;
				}
			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (sz != 0)
				{
					memcpy(tmp, _start, sizeof(T)*sz);
					delete[] _start;
				}
				_start = tmp;
				_end = _start + sz;
				_endofstorage = _start + n;
			}
		}
		void push_back(const T& x)
		{
			if (size() == capacity())
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_end = x;
			++_end;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return *(_start + i);
		}
		void pop_back();
		void insert(iterator pos, const T& x);
		iterator erase(iterator pos);


	private:
		T* _start;
		T* _end;
		T* _endofstorage;
	};

	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}