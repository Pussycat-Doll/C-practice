#include<iostream>
using namespace std;


class Student
{
	//成员函数（方法）成员函数如果在类中定义，
	//编译器可能会将其当成内联函数处
public:
	void ShowInfor()
	{
		cout << _age << endl;
		cout << _name << endl;
		cout << _stuid << endl;
	}
	int GetAGe()
	{
		return _age;
	}
private:
	char _name[10];//成员变量一般情况都是比较隐私的,被定义成私有或者保护
	int _age;
	int _stuid;
	 	 
};
//struct的默认限定符是Public
//class默认是公有的
//int main()
//{
//	Student s1;
//	Student s2;
//	//s1._age = 19;
//	cout << s1.GetAGe() << endl;
//	return 0;
//}

//定义一个数据结构栈的类
class Stack
{
public:
	void Init(size_t n)
	{}
	void Destory()
	{}
	void Push(int x)
	{}
private:
	int* _a;
	size_t _top;
	size_t _capacity;
};
int main()
{

	return 0;
}