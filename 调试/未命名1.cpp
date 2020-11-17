#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;


namespace MyString
{
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//+1是留给/0的空间的，它不算有效字符

			strcpy(_str, str);
		}
		void swap(string& s)
		{
			::swap(_str, s._str);//调用全局的swap函数
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		~string()
		{
			delete[] _str;
			_str = NULL;
			_size = _capacity = 0;
		}
		string(const string& s)
		{
			/*_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			_size = _capacity = strlen(s._str);*/
			string tmp(s._str);
			this->swap(tmp);
		}
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_size = _capacity = strlen(s._str);
				_str = new char[_capacity + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}*/
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}

		char* c_str()const
		{
			return _str;
		}
		size_t size()const
		{
			return _size;
		}
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		char& operator[](size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		void reserve(size_t n)//把容量扩展到n
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//n个有效字符+标识字符‘\0’
				strcpy(tmp, _str);
				_capacity = n;
				delete[] _str;//释放旧空间
				_str = tmp;
			}
		}
		/*_size = 8,_capacity = 14，resize(2),resize(10),resize(18)
		*/
		void resize(size_t n, char ch = '\0')//把size扩展到N
		{
			if (n <= _size)
			{
				_str[n] = '\0';
			}
			else
			{
				if (n > _capacity)
					this->reserve(n);
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
			}
			_size = n;
		}
		void erase(size_t pos, size_t len = -1)
		{
			if (_size - pos <= len)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos+len;
				while (i <= _size)
				{
					_str[pos++] = _str[i++];
				}
				_size -= len;
			}
		}
		void push_back(char c)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = (_capacity == 0 ? 2 : _capacity * 2);
				reserve(newcapacity);
			}
			_str[_size] = c;
			++_size;
			_str[_size] = '\0';
		}
		void append(const char c)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = (_capacity == 0 ? 2 : _capacity * 2);
				reserve(newcapacity);
			}
			_str[_size] = c;
			++_size;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			if (_capacity < _size + strlen(str))
			{
				reserve(_size + strlen(str));
			}
			strcpy(_str + _size, str);
			_size += strlen(str);
		}
		string& operator+= (const char ch)
		{
			this->push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				this->reserve(newcapacity);
			}
			size_t end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_capacity < _size + len)//空间不够先进行增容
			{
				this->reserve(_size + len);
			}
			size_t end = _size;
			while (end >= (int)pos)//挪动数据
			{
				_str[end + len] = _str[end];
				--end;
			}
			//for (size_t i = 0; i < len; ++i)//拷贝数据
			//{
			//	_str[pos+i] = str[i];
			//}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		size_t find(const char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		size_t find(const char* ch, size_t pos = 0)
		{
			char* ptr = strstr(_str, ch);
			if (ptr == NULL)
				return npos;
			return ptr - _str;

		}
		size_t capacity()
		{
			return _capacity;
		}
		bool operator> (const string& s1)
		{
			int ret = strcmp(_str, s1._str);
			return ret > 0;
		}
		bool operator== (const string& s1)
		{
			int ret = strcmp(_str, s1._str);
			return ret == 0;
		}
		bool operator< (const string& s1)
		{
			return !(*this > s1 || *this == s1);
		}
		bool operator>= (const string& s1)
		{
			return !(*this < s1);
		}
		bool operator<= (const string& s1)
		{
			return !(*this > s1);
		}
		bool operator!= (const string& s1)
		{
			return !(*this == s1);
		}
	private:
		char* _str;
		size_t _size;//已经存储的有效字符的个数
		size_t _capacity;//表示能存多少个有效字符，不包括‘\0’，'\0'是标识字符
		
		static size_t npos;
};
    size_t string::npos = -1;
	ostream& operator<<(ostream& out, string str)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			cout << str[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& str)
	{
		while (1)
		{
			char ch;
			//in >> ch;
			ch = in.get();
			if(ch == '\n')//可以获取空格
			//if (ch == ' ' || ch == '\n')
				break;
			else
				str += ch;
		}
		return in;
	}

	void test1()
	{
		string s1("hello");
		string s2(s1);
		string s3;
		s3 = s1;
		cout << s3.c_str() << endl;

		//三种遍历方式
		for (size_t i = 0; i < s3.size(); ++i)
		{
			cout << s3[i];
		}
		cout << endl;

		string::iterator it = s3.begin();
		while (it != s3.end())
		{
			*it += 1;
			cout << *it;
			++it;
		}
		cout << endl;

		for (size_t i = 0; i < s3.size(); ++i)
		{
			cout << --s3[i];
		}
		cout << endl;
	}
	void test2()
	{
		string s1("hello");
		string s2(s1);
		s1.push_back('!');
		cout << s1.c_str() << endl;

		cout << s2.size() << endl;
		s2.append(' ');
		cout << s2.c_str() << endl;
		cout << s2.size() << endl;
		s2.append("world!");
		cout << s2.c_str() << endl;
		cout << s2.size() << endl;

		s1 += " World!";
		cout << s1 << endl;
	}
	void test3()
	{
		string s1("hello");
		s1.reserve(10);
		cout << s1 << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl << endl;

		s1.resize(8,'a');
		cout << s1 << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl << endl;

		s1.resize(18, 'm');
		cout << s1 << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl << endl;

		s1.resize(2, 'q');
		cout << s1 << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl << endl;
	}
	void test4()
	{
		string s1("hello world");
		cout << s1 << endl;

		s1.erase(0, 1);
		cout << s1 << endl;

		s1.erase(2, 2);
		cout << s1 << endl;

		s1.erase(0, 3);
		cout << s1 << endl;
	}
	void test5()
	{
		string s1("helglo");
		cout << s1.find('g') << endl;
		cout << s1.find('a') << endl;

		string s2("ilikecat");
		cout << s2.find("like") << endl;
		cout << s2.find("il") << endl;
	}
	void test6()
	{
		string s1;
		cin >> s1;
		cout << s1 << endl;
	}
	void test7()
	{
		string s1("hello");
		s1.insert(0, ' ');
		s1.insert(1, "Hey");
		cout<<s1<<endl;
	}
}

int main()
{
	MyString::test7();
	return 0;
}
