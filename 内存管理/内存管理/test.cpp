#include<iostream>
using namespace std;

class Solution
{
public:
	Solution()
	{
		cout << "Solution()" << endl;
	}
	int Sum(int n)
	{
		cout << "Sum" << endl;
		return n;
	}
	~Solution()
	{
		cout << "~Solution()" << endl;
	}
};
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()"<<endl;
	}
private:
	int _a;
};
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
};
class C
{
public:
	C()
	{
		cout << "C()" << endl;
	}
	~C()
	{
		cout << "~C()" << endl;
	}
};
class D
{
public:
	D()
	{
		cout << "D()" << endl;
	}
	~D()
	{
		cout << "~D()" << endl;
	}
};

//C c;
//int main()
//{
//	//Solution s1;
//	//s1.Sum(99);//����������������������mian������
//
//	////Solution();//��������,����һ�ι��캯��,û������
//	//Solution().Sum(100);//ֻ������һ�л�ʹ������������󣬱��˲���Ҫʹ�ã������������������ֻ����һ��
//	
//	A a;
//	B b;
//	static D d;
//	//����˳�� C A B D
//	//����˳�� B A D C
//	return 0;
//}

struct ListNode_c
{
	int _val;
	struct ListNode_c* _next;
	struct ListNode_c* _prev;
};
typedef struct ListNode_c ListNode_c;
ListNode_c* BuyListNode(int val)
{
	ListNode_c* node1 = (ListNode_c*)malloc(sizeof(ListNode_c));
	node1->_val = 1;
	node1->_prev = NULL;
	node1->_next = NULL;
	return node1;
}

struct ListNode_cpp
{
	int _val;
	struct ListNode_cpp* _next;//����C��struct���÷�
	ListNode_cpp* _prev;//��cpp�У�struct�Ѿ�������Ϊ����

	ListNode_cpp(int val = 0)
		:_val(val),
		_prev(nullptr),
		_next(nullptr)
	{}
};



//int main()
//{
//	//A* a1 = new A;
//	//delete a1;
//	//A* a2 = (A*)malloc(sizeof(A));
//	//free(a2);
//	////ΪʲôC�������Ѿ���malloc/free, C++Ҳ�����ã����ǻ�����Ҫnew/delete
//	////1���������������new��malloc����һ����
//	////2������Զ������ͣ�new ��������ռ�֮�󣬵��ù��캯����delete���ȵ���
//	////����������������֮�����ͷ��ڴ�
//	////C++�н���ʹ��new/delete
//
//	//ListNode_c* node1 = BuyListNode(1);
//
//	//ListNode_cpp* node2 = (ListNode_cpp*)new ListNode_cpp;
//	//ListNode_cpp* node3 = (ListNode_cpp*)new ListNode_cpp(5);
//
//	//operator new��malloc��������ʲô��
//	//���ۣ�ʹ�÷�ʽ��һ�����������ķ�ʽ��һ��
//	size_t sz = 2;
//	void* p4 = malloc(sz * 1024 * 1024 * 1024);
//	cout << p4 << endl;
//
//	try
//	{
//		void* p5 = operator new(sz * 1024 * 1024 * 1024);
//		cout << p5 << endl;//ʧ�����쳣(������������ķ�ʽ)
//		//operator delete(p5);
//	}
//	catch (exception & e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}
//int main()
//{
	//malloc
	//operator new ==> malloc+ʧ�����쳣ʵ��
	//new ==> operator new +���캯��
	//new ����malloc��һ���ĵط���1�����ù��캯����ʼ��
	//2��ʧ�������쳣
	//delete ��free��ͬ�ĵط���1������������������
	//

//	A* p1 = new A;
//	delete p1;
//	//ģ���������Ϊ
//	//���Ѿ����ڵ�һ��ռ���ù��캯����ʼ������λnew/replacement new
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete (p2);
//	return 0;
//}
//int main()
//{
//	char* p = new char[1024 * 1024 * 1024];
//	//�ڴ�й©�����ǻ�����ԭ���ͷ�pָ��Ŀռ�
//	//Σ�����������еĳ���(��Ϸ����)�������ڴ�й©Σ���ܴ󣬻����豸���ڴ汾���С��Ҳ��Σ��
//	
//	
//	return 0;
//}
//����ڶ�������4G�Ŀռ�
int main()
{
	/*size_t n = 2;
	void* p = new char[n * 1024 * 1024 * 1024];//���쳣*/
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;

	return 0;
}