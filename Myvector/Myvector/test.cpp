//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//void test_vector1()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	vector<int> v2(v1);
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i];
//	}
//	cout << endl;
//	for (size_t i = 0; i < v2.size(); ++i)
//	{
//		cout << v2[i];
//	}
//	cout << endl;
//}
//
//void test_vector2()
//{
//	//遍历
//	vector<int> v;
//	v.push_back(0);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		cout << v[i]*2 << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator it1 = v.begin();
//	while (it1 != v.end())
//	{
//		cout << (*it1)++ << " ";
//		++it1;
//	}
//	cout << endl;
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int>::reverse_iterator it2 = v.rbegin();//反向迭代器
//	while (it2 != v.rend())
//	{
//		cout << *it2 << " ";
//		++it2;
//	}
//	cout << endl;
//	vector<int>::const_reverse_iterator it3 = v.crbegin();
//	//*it3 = 99;//const迭代器只读不可写
//}
//
//void test_vector3()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v1.insert(v1.begin(), 99);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v1.erase(v1.begin(),v1.begin()+2);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v1[0] = 100;
//	v1.at(3) = 111;
//
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v1.erase(find(v1.begin(), v1.end(), 3));
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//void test_vector4()
//{
//	vector<int> v1;
//	int sz = v1.capacity();
//	cout << "capacity chang:" << endl;
//	for (int i = 0; i < 1001; ++i)
//	{
//		v1.push_back(i);
//		if (sz != v1.capacity())
//		{
//			sz = v1.capacity();
//			cout << "capacity changed:" << sz << endl;
//		}
//	}
//}
//void test_vector5()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//
//	vector<int>::iterator it = v1.begin();
//	v1.push_back(6);
//	v1.push_back(7);
//	/*
//	push_back
//	insert
//	resize
//	reserve
//	等可能会扩容的接口都会导致迭代器失效
//	*/
//	it = v1.begin();
//	while (it != v1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//void test_vector6()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);
//
//	vector<int>::iterator it = v1.begin();
//	while (it != v1.end())
//	{
//		if (*it % 2 == 0)
//		{
//			it = v1.erase(it);//解决方案
//			//v1.erase(it);
//			//删除之后，it就失效了
//		//这里的失效是it的位置不对了
//		//VS下会报错，是编译检查出来的
//		//GCC下不一定会报错，但是结果不对
//
//		}
//		else
//			++it;
//	}
//	/*
//	总结，不管哪个平台下，erase(it)都会导致迭代器失效
//	*/
//}
//
//int main()
//{
//	//test_vector1();
//	//test_vector2();
//	//test_vector3();
//	//test_vector4();
//	//test_vector5();
//	test_vector6();
//	return 0;
//}