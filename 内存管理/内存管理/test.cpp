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
//	//s1.Sum(99);//正常对象的生命周期在这个mian函数中
//
//	////Solution();//匿名对象,调用一次构造函数,没有名字
//	//Solution().Sum(100);//只有我这一行会使用这个创建对象，别人不需要使用，匿名对象的生命周期只在这一行
//	
//	A a;
//	B b;
//	static D d;
//	//构造顺序 C A B D
//	//析构顺序 B A D C
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
	struct ListNode_cpp* _next;//兼容C中struct的用法
	ListNode_cpp* _prev;//在cpp中，struct已经可以认为是类

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
//	////为什么C语言中已经有malloc/free, C++也可以用，但是还是需要new/delete
//	////1、针对内置类型用new和malloc都是一样的
//	////2、针对自定义类型，new 会在申请空间之后，调用构造函数，delete会先调用
//	////析构函数进行清理，之后再释放内存
//	////C++中建议使用new/delete
//
//	//ListNode_c* node1 = BuyListNode(1);
//
//	//ListNode_cpp* node2 = (ListNode_cpp*)new ListNode_cpp;
//	//ListNode_cpp* node3 = (ListNode_cpp*)new ListNode_cpp(5);
//
//	//operator new和malloc的区别是什么？
//	//结论：使用方式都一样，处理错误的方式不一样
//	size_t sz = 2;
//	void* p4 = malloc(sz * 1024 * 1024 * 1024);
//	cout << p4 << endl;
//
//	try
//	{
//		void* p5 = operator new(sz * 1024 * 1024 * 1024);
//		cout << p5 << endl;//失败抛异常(面向对象处理错误的方式)
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
	//operator new ==> malloc+失败抛异常实现
	//new ==> operator new +构造函数
	//new 比起malloc不一样的地方：1、调用构造函数初始化
	//2、失败了抛异常
	//delete 比free不同的地方：1、调用析构函数清理
	//

//	A* p1 = new A;
//	delete p1;
//	//模拟上面的行为
//	//对已经存在的一块空间调用构造函数初始化，定位new/replacement new
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete (p2);
//	return 0;
//}
//int main()
//{
//	char* p = new char[1024 * 1024 * 1024];
//	//内存泄漏：忘记或其它原因释放p指向的空间
//	//危害：长期运行的程序(游戏服务)，出现内存泄漏危害很大，或者设备的内存本身很小，也有危害
//	
//	
//	return 0;
//}
//如何在堆上申请4G的空间
int main()
{
	/*size_t n = 2;
	void* p = new char[n * 1024 * 1024 * 1024];//抛异常*/
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;

	return 0;
}