#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//expicit 防止单参数的构造函数的类型转换
void test1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())//end是最后一个元素的下一个位置
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int> v2(10, 5);
}

template<class T>
void func()
{
	cout << T() << endl;
}
void test3()
{
	size_t sz;
	std::vector<int> v;
	sz = v.capacity();
	v.reserve(100);
	//v.resize(100);
	cout << "make v grow:\n" << endl;
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed : " << sz << endl;
		}
	}
}
void test4()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));//迭代器版构造
	//typedef int* iterator;
	//iterator it = a;
	//while (it != a + sizeof(a) / sizeof(int))
	//{
	//	cout << *it << endl;
	//	++it;
	//}
	//v.push_back(99);
	//find算法体现，泛型代码复用
	/*template <class InputIterator, class T>
   InputIterator find (InputIterator first, InputIterator last, const T& val);*/
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 99);//肯可能会失效，如果增容pos就会失效
	/*如果增容了，开辟新的空间，将数据拷贝过去，原来的空间会被释放，但是迭代器pos
	还依旧指向原来的空间，（相当于野指针）从而造成迭代器失效*///vs会报错(PJ版下自己加的检查)，linux不会报错
	pos = find(v.begin(), v.end(), 4);//需要重新更正一下
	v.erase(pos);
}
void test5()
{
	vector<int> v1(5, 10);
	vector<int> v2(10, 5);
	swap(v1, v2);
	//v1.swap(v2);

}
int main()
{
	//test1();
	//func<string>();
	//func<int>();
	//func<int*>(); 
	test5();
	system("pause");
	return 0;
}