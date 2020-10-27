#include<iostream>
using namespace std;

//template<typename T>
template<class T>//定义模板类型参数
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


//int main()
//{
//	int a = 1, b = 9;
//	Swap(a, b);
//	//函数模板实例化，生成对应类型参数的函数，发生在预处理阶段
//	//模板的原理：人写的模板，编译器通过模板实例化出对应的函数或类
//	char c = '&', d = '%';
//	Swap(c, d);
//	return 0;
//}
//C语言如何实现一个栈-->C++的改进
//1、忘记初始化和销毁  -->构造函数和析构函数
//2、没有封装，谁都可以修改结构体的数据-->封装，使用访问限定符
//3、如果想定义两个不同类型的栈，要写两次-->类模板
//C++如何实现一个栈
typedef int STDteType;
typedef struct Stack
{
	int* _a;
	int _capacity;
	int _size;
};
void StackInit(Stack* ps);
void StackDestory(Stack* ps);
//...

template<class T>
class Stack_cpp
{
public:
	Stack_cpp(const T& a)
		:_a(a)
	{}
	~Stack_cpp(){}
private:
	T* _a;
	int _capacity;
	int _size;
};
int main()
{
	Stack_cpp<int> a(10);
	return 0;
}