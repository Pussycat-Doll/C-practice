#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
namespace qwq
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{}
		vector(const vector<T> &v)
		{
			_start = new T[v.capacity];
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _strat + v.size();
			_end_of_storage = _start + v.capacity();
		}
		//在这里的形参不需要用引用，因为在进行赋值过程中，v作为形参，会成为临时对象，出了作用域
		//也会被销毁，所以只需要将临时对象的和this指针的发生交换即可完成拷贝工作
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
		void resize(size_t newsize, const T&val = T())
		{
			size_t sz = size();
			if (newsize < size())
			{
				_finish = _start + newsize;
			}
			else 
			{
				if (newsize > capacity())
					reserve(newsize);
				iterator it = _finish;
				_finish = _start + newsize;
				while (it != _finish)
				{
					*it = val;
					++it;
				}
			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* temp = new T[n];
				if (_start)
				{
					memcpy(temp, _start, sizeof(T)*sz);
					delete[] _start;
				}
				_start = temp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}

		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t newcpapacity = (capacity() == 0) ? 2 : capacity() * 2;
				reserve(newcpapacity);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}//如何让解决迭代器失效问题？？？用引用，因为在Insert的内部中，已经更正了pos在增容之后失效的位置
		//若要让此更正也发生到实参身上，最好的解决办法就是引用传值。函数内部引用改变，实参也会同时发上改变，
		//那么失效的pos就会被更正，以后再访问pos的位置就不会再发生任何问题了。
		void insert(iterator &pos, const T& x)
		{
			assert(pos <= _finish && pos >= _start);
			size_t ps = pos - _start + 1;
			if (_finish == _end_of_storage)
			{
				size_t newcpapacity = (capacity() == 0) ? 2 : capacity() * 2;
				reserve(newcpapacity);
				pos = _start + ps;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1 )= *end;
				--end;
			}
			*pos = x;
			++_finish;
		}
		void erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			while (pos < _finish)
			{
				*pos = *(pos + 1);
				++pos;
			}
			--_finish;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		const T& operator[](size_t pos)
		{
			return _start[pos];
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		void print()
		{
			//iterator it = begin();
			//while (it != end())
			//{
			//	cout << *it << " ";
			//	++it;
			//}
			//cout << endl;
			for (auto e : *this)
			{
				cout << e << " ";
			}
			cout << endl;
		}
	private:
		//T* _a;
		//size_t _size;
		//size_t _capapcity;

		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}

void print(qwq::vector<int>* v)
{
	size_t size = v->size();
	for (int i = 0; i < size;++i)
	{
		cout << (*v)[i]<<" ";
	}
	cout << endl;
}
void test1()
{
	qwq::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	cout << "size is :" << v1.size() << endl;
	cout << "cpapcity is :" << v1.capacity() << endl;
	/*print(&v1);*/
	//v1.resize(1);
	v1.resize(7);
	v1.resize(12);
	cout << "size is :" << v1.size()<<endl;
	cout << "cpapcity is :" << v1.capacity() << endl;
	v1.print();
}
void test2()
{
	qwq::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	auto it1 = v1.begin();
	auto it2 = v1.end();
	v1.insert(it1, 99);
	v1.insert(it2, 99);

	it1 = v1.begin();
	v1.erase(it1);
	v1.print();

}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
