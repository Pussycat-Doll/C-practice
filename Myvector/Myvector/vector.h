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
			_finish(nullptr),
			_finishofstorage(nullptr)
		{}
		/*vector(const vector<T>& v)
		{
			//开空间
			_start = new T[v.capacity()];
			_finish = _start + v.size();
			_finishofstorage = _start + v.capacity();

			//拷贝数据
			for (size_t i = 0; i < size(); ++i)
			{
				*_finish = v[i];
				++_finish
			}
		}*/
		vector(const vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_finishofstorage(nullptr)
		{
			reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _finishofstorage = nullptr;
		}
		vector<T>& operator=(vector<T>& v)
		{
			if (this != &v)
			{
				delete[] _start;
				_start = new T[v.capacity()];
				_finish = _start + v.size();
				_finishofstorage = _start + v.capacity();
				/*for (auto e : v)
				{
					push_back(e);
				}*/
				//memcpy(_start, v._start, sizeof(T) * v.size());//按照字节拷贝，属于浅拷贝，应该用operator=调用深拷贝深拷贝
				for (size_t i = 0; i < v.size(); ++i)
				{
					_start[i] = v[i];
				}

			}
			return *this;
		}
		/*vector<T>& operator=(vector<T> v)
		{
			this->swap(v);
			return *this;
		}*/
		void swap(vector<T>& v)
		{
			::swap(_start, v._start);//调用全局的swap函数
			::swap(_finish, v._finish);
			::swap(_finishofstorage, v._finishofstorage);
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _finishofstorage - _start;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		/*int i = int()C++新支持的自定义类型
		double a = double()*/
		void resize(size_t n, const T& x = T())
		{
			if (n < size())
			{
				_finish -= n;
				//_finish = _start+n;
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
					memcpy(tmp, _start, sizeof(T)*sz);//按字节处理
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_finishofstorage = _start + n;
			}
		}
		void push_back(const T& x)
		{
			if (size() == capacity())
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return *(_start + i);
		}
		T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		void insert(iterator pos, const T& x)
		{
			assert(pos <= end());
			if (size() == capacity())
			{
				size_t ps = pos-_start;
				size_t newcapacity = (capacity() == 0 ? 2 : capacity() * 2);
				reserve(newcapacity);
				pos = _start + ps;//如果扩容pos需重置
			}

			vector<T>::iterator it = end()-1;
			for (; it >= pos; --it)
			{
				*(it+1) = *it;
			}
			*pos = x;
			++_finish;
		}
		void vector_print()
		{
			for (auto e: *this)
			{
				cout << e << " ";
			}
			cout << endl;
		}
		iterator erase(iterator pos)
		{
			assert(pos<_finish && pos>=_start);
			vector<T>::iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;
			return pos;
		}


	private:
		T* _start;
		T* _finish;
		T* _finishofstorage;
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
	void test_vector2()
	{
		vector<int> v;
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.vector_print();

		v.pop_back();
		v.vector_print();

		v.insert(v.begin(), 99);
		v.vector_print();
		v.insert(v.begin()+1, 100);
		v.vector_print();
		v.insert(v.end(), 88);
		v.vector_print();

		v.erase(v.begin());
		v.vector_print();
		v.erase(v.end()-1);
		v.vector_print();
	}
	void test_vector3()
	{
		vector<int> v;
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		vector<int> v1;
		v1 = v;
		v1.vector_print();
	}
}