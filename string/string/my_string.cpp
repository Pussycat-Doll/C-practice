#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<cstdlib>
using namespace std;

namespace cat
{ 
	class string
	{
	public:
		typedef char* iterator;
		string()
			:_str(new char[1])
		{
			_str[0] = '\0';
		}
		//错误例子：string(const char* s1 = "\0")
		//			string(const char* s1 = nullptr)
	    string(const char* s1 = "")//即char* 指向一个空字串
			:_str(new char[strlen(s1)+1])
		{
			strcpy(_str, s1);//strcpy连\0一起拷贝过去
			_size = strlen(s1);
			_capacity = _size;
		}
		string(const string& s)
			:_str(new char[s._size + 1])
		{
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char* c_str()
		{
			return _str;
		}
		string& operator=(const string& s)//释放旧空间，拷贝新的值
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[s._size + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._capacity;
				return *this; 
			}
		}
		//模拟实现迭代器
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//增删查改
		void reserve(size_t new_capacity)//改变容量（只能增容，不能缩容）
		{
			if (_capacity < new_capacity)
			{
				char* str = new char[new_capacity + 1];
				strcpy(str, _str);
				delete[]_str;
				_str = str;
				_capacity = new_capacity;
			}
		}
		void resize(size_t newsize, char c = char())
		{
			if (newsize > _capacity)
			{
				size_t newcapacity = (_capacity == 0) ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			memset(_str + _size, c, newsize - _size);
			_size = newsize;
			_str[newsize] = '\0';

		}
		void PushBack(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);//一般是增容增2倍或者1.5倍
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void Append(size_t n, char c)
		{
			for (size_t i = 0; i < n;++i)
			{
				PushBack(c);
			}
		}
		void Append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len; 
		}
		const string& operator+=(char c)//接口尽量用加等。不要用加
		{
			PushBack(c);
			return *this;
		}
		string operator+(const char* str)
		{
			string temp = *this;
			temp.Append(str);
			return temp;
		}
		const string& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}
		void insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capacity)
			{
				reserve(_capacity*2);
			}
			for (int i = _size; i >= (int)pos; --i)
			{
				_str[i + 1] = _str[i];
			}
			_str[pos] = ch;
			++_size;
		}
		void insert(size_t pos, char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			for (int i = _size; i >= (int)pos; --i)
			{
				_str[i + len] = _str[i];
			}
			while (*str)//不能用strcpy,因为会将\0拷贝过去
			{
				_str[pos++] = *str++;
			}
			_size += len;
		}
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		const char* c_str()const
		{
			return _str;
		}
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return _size == 0;
		}
		//bool operator>( const string& str)
		//{
		//	if (strcmp(_str, str.c_str()))
		//		return true;
		//	return false;
		//}
		bool operator>(const string& str)const
		{
			const char* str1 = _str;
			const char* str2 = str._str;
			while (*str1 && *str2)
			{
				if (*str1 > *str2)
					return true;
				else if (*str1 < *str2)
					return false;
				else
				{
					++str1;
					++str2;
				}
			}
			if (*str1)//str1没有结束
				return true;
			else//str2没有结束或者二者相等
				return false;
		}
		bool operator<(string& str)const
		{
			return !(*this >= str);
		}
		bool operator==(string& str)const
		{
			/*if (strcmp(_str, str.c_str()) == 0)
				return true;
			else
				return false;*/
			char* str1 = _str;
			char* str2 = str._str;
			while (*str1 && *str2)
			{
				if (*str1 > *str2 || *str1 < *str2)
					return false;
				if (*str1 == *str2)
				{
					++str1;
					++str2;
				}
			}
			if (*str1 || *str2)//二者其中有一个没有结束
				return false;
			else
				return false;
		}
		bool operator>=(string& str)const
		{
			return *this > str || *this == str;
		}
		size_t find(char ch)
		{
			size_t begin = 0;
			while (begin < _size)
			{
				if (_str[begin] == ch)
					return begin;
				else
					++begin;
			}
			return 0;
		}
		size_t find(const char* str)//strstr
		{
			size_t first = 0;
			size_t second = 0;
			size_t third = 0;
			size_t len = strlen(str);
			while (first < _size && third < len)
			{
				if (_str[first] == str[third])
				{
					second = first;
					while (second < _size && third < len)
					{
						if (_str[second] == str[third])
						{
							++second;
							++third;
						}
						else
						{
							third = 0;
							break;
						}
					}
					if (second - first == len)
						return first;
				}
				++first;
			}
			return -1;
		}
		ostream& operator<<(ostream& out,const string& s)
		{

		}
		istream& operator>>(istream& in, const string& s)
		{

		}
		void print()
		{
			iterator it = begin();
			while (it != end())
			{
				cout << *it;
				++it;
			}
			cout << endl;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

}
void test1()
{
	cat::string s1("hello");
	cout << s1.c_str() << endl;
	s1[2] = 'q';

	cat::string copy(s1);
	cout << copy.c_str() << endl;

	cat::string s2 = "world";
	cout << s2.c_str() << endl; 
}
void test2()
{
	cat::string s1("xixi");
	s1.Append("hehe");
	s1 += "Hello";
	s1.print();
	s1.insert(0, '8');	
	s1.print();
	s1.insert(0, "haha");
	s1.print();
}
void test3()
{
	cat::string s1("World.");
	cat::string s2 = "World.";
	if (s2 > s1)
		cout << "s2 > s1" << endl;
	else
		cout << "s2 <= s1" << endl;
}
void test4()
{
	cat::string s1("Hello.");
	cout<<s1.find("H.")<<endl;
}
int main()
{
	test4();
	system("pause");
	return 0;
}