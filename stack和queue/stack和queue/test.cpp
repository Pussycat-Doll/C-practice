#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<time.h>
#include<functional>//�º���ͷ�ļ�
#include"stack.h"
#include"queue.h"
#include"priority_queue.h"
using namespace std;

void test_stack()
{//����ȳ�
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	//û�е�����
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
void test_queue()
{//�Ƚ��ȳ�
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
void test_deque()
{
	deque<int> d;
	vector<int> v;
	const int n = 100000;
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		int x  = rand();
		d.push_back(x);
		v.push_back(x);
	}
	size_t begin1 = clock();
	sort(v.begin(), v.end());
	size_t end1 = clock();

	size_t begin2 = clock();
	sort(d.begin(), d.end());
	size_t end2 = clock();

	cout << "vector�����ѵ�ʱ��Ϊ��" << end1 - begin1 << endl;
	cout << "deque�����ѵ�ʱ��Ϊ��" << end2 - begin2 << endl;
}
void test_priority_queue()
{
	//��������������֧�ֵ�������������Ϊ���Ƕ�����һЩ���������
	//������������
	//priority_queue<int> pq;//Ĭ���Ǵ�����ȼ���
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(3);
	pq.push(1);
	pq.push(2);
	pq.push(6);
	pq.push(5);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}
void test_sort()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	//sort(v.begin(), v.end());//Ĭ��������
	greater<int> com;
	//sort(v.begin(), v.end(), com);//����
	sort(v.begin(), v.end(),greater<int>());//����
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test_stack();
	//test_queue();
	//mystl::test_stack();
	//mystl::test_queue();
	//test_deque();
	//test_priority_queue();
	//mystl::test_priority_queue();

	//mystl::less<int> lessfunc;
	//cout << lessfunc(1, 2) << endl;
	test_sort();
	return 0;
}
