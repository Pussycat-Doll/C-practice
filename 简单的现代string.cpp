#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//ʵ��һ���򵥵�string(��������Դ��������ɾ�鿴)
//��ͳд��
//class my_string
//{
//private:
//	char* _str;
//public:
//	my_string(const char* str = "")
//		:_str(new char[1])
//	{
//		strcpy(_str, str);
//	}
//	my_string(const my_string& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//	my_string operator=(const my_string& s)
//	{
//		if (this != &s)
//		{
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}	
//		return *this;
//	}
//	~my_string()
//	{
//		delete[] _str;
//	}
//};
//�ִ�д��->�򵥣�����ɬ
class my_string
{
private:
	char* _str;
public:
	my_string(const char* str = "")
		:_str(new char[1])
	{
		strcpy(_str, str);
	}
	my_string(const my_string& s)
		:_str(nullptr)
	{
		my_string tmp(s._str);
		swap(tmp._str, _str);
	}
	my_string operator=(const my_string& s)
	{
		if (this != &s)
		{
			my_string tmp(s);
			swap(tmp._str, _str);
		}
		return *this;
	}
	~my_string()
	{
		delete[] _str;
	}
};


int main()
{
	my_string s1("hello.");
	my_string s2(s1);
	my_string s3("world");
	my_string s1 = s3;
	system("pause");
	return 0;
}
