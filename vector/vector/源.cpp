#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//expicit ��ֹ�������Ĺ��캯��������ת��
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
	while (it != v1.end())//end�����һ��Ԫ�ص���һ��λ��
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
	vector<int> v(a, a + sizeof(a) / sizeof(int));//�������湹��
	//typedef int* iterator;
	//iterator it = a;
	//while (it != a + sizeof(a) / sizeof(int))
	//{
	//	cout << *it << endl;
	//	++it;
	//}
	//v.push_back(99);
	//find�㷨���֣����ʹ��븴��
	/*template <class InputIterator, class T>
   InputIterator find (InputIterator first, InputIterator last, const T& val);*/
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 99);//�Ͽ��ܻ�ʧЧ���������pos�ͻ�ʧЧ
	/*��������ˣ������µĿռ䣬�����ݿ�����ȥ��ԭ���Ŀռ�ᱻ�ͷţ����ǵ�����pos
	������ָ��ԭ���Ŀռ䣬���൱��Ұָ�룩�Ӷ���ɵ�����ʧЧ*///vs�ᱨ��(PJ�����Լ��ӵļ��)��linux���ᱨ��
	pos = find(v.begin(), v.end(), 4);//��Ҫ���¸���һ��
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