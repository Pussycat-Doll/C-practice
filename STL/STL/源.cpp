#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

void TestPushBack()
{
	string s;
	s.reserve(3);
	size_t sz = s.capacity();
	cout << "making a grow:" << endl;
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('@');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}


void func(const string& s1)
{
	//顺序遍历，只能读不能写
	string::const_iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << endl;
		++it;
	}

	////迭代器:可读可写
	//cout << endl;
	////[begin,end)
	//string::iterator it2 = s1.begin();
	//while (it2 != s1.end())
	//{
	//	cout << *it2 << endl;
	//	++it2;
	//}
//	cout << endl;
//	//逆向迭代器：可读可写
//	string::reverse_iterator rit1 = s1.rbegin();
//	while (rit1 != s1.rend())
//	{
//		//*rit += 1;
//		cout << *rit1 << endl;
//		++rit1;
//	}
//	cout << endl;
//	//只可读，不可写。
//	string::const_reverse_iterator rit2 = s1.rbegin();
//	while (rit2 != s1.rend())
//	{
//		//*rit += 1;
//		cout << *rit2 << endl;
//		++rit2;
//	}
//	cout << endl;
}
int main()
{
	/*string s1;
	string s2("Hello");
	string s3(s2);
	cout << s1 << endl;
	cout << s2<< endl;
	cout << s3 << endl;
	cout << s2.size() << endl;
	cout << s2.length() << endl;
	cout << s1.capacity() << endl;
	cout << s3.capacity() << endl;

	s2.clear();
	cout << s2 << s2.capacity() << endl;

	s1.resize(99);
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << "\n" << endl;
	TestPushBack();*/

	//string s("123");//atoi
	//int value = 0;
	//for (size_t i = 0; i < s.size(); ++i)
	//{
	//	value *= 10;
	//	value += s[i] - '0';
	//}
	//cout << value << endl;

	//string 的遍历方式
	//下标+operate[]
	//string s1("hello");
	//for (size_t i = 0; i < s1.size(); ++i)//size与length比较，优先用size
	//{
	//	cout << s1[i] << endl;
	//}
	//auto it = s1.begin();
	////string::iterator it = s1.begin();
	//while (it != s1.end())
	//{
	//	cout << *it << endl;
	//	++it;
	//}
	////范围for
	//for (auto e : s1)
	//{
	//	cout << e << endl;
	//}

	//string s1("Hello");
	//s1.push_back('-');
	//s1.push_back('b');
	//s1.push_back('i');
	//s1.push_back('t');
	//s1.push_back('!');

	//cout << s1 << endl;
	//string s2("Hello");
	//s2.append("-world!");
	//cout << s2 << endl;

	//string s3("Hello");
	//s3 += '-'; //s3.operator+='-'//O(N)的接口
	//s3 += "bit!";
	//cout << s3 << endl;
	//s3.insert(0, "**");
	//cout << s3 << endl;
	//s3[0] = '&';
	//cout << s3 << endl;
	//s3.erase(0, 1);
	//s3.erase(0, 1);
	//cout << s3 << endl;

	//string file1("string.cpp");
	//size_t pos = file1.find('.');
	////string suffix(file1, pos, file1.size()-pos);//调用构造函数

	//string suffix = file1.substr(pos, file1.size() - pos);
	//cout << suffix << endl;
	//找出每一个后缀
	string file2("string.cpp.zip.gz");
	size_t first = file2.find('.');
	while (first != string::npos)//string::npos即为-1
	{
		size_t second = file2.find('.', first + 1);
		if (second != string::npos)
		{
			cout << file2.substr(first, second - first) << endl;
		}
		else//当已经找到最后一个.时
		{
			cout << file2.substr(first, file2.size() - first) << endl;
			break;
		}	
		first = second;
	}
	system("pause");
	return 0;
}