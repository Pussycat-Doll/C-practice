#include<iostream>
using namespace std;

//template<typename T>
template<class T>//����ģ�����Ͳ���
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
//	//����ģ��ʵ���������ɶ�Ӧ���Ͳ����ĺ�����������Ԥ����׶�
//	//ģ���ԭ����д��ģ�壬������ͨ��ģ��ʵ��������Ӧ�ĺ�������
//	char c = '&', d = '%';
//	Swap(c, d);
//	return 0;
//}
//C�������ʵ��һ��ջ-->C++�ĸĽ�
//1�����ǳ�ʼ��������  -->���캯������������
//2��û�з�װ��˭�������޸Ľṹ�������-->��װ��ʹ�÷����޶���
//3������붨��������ͬ���͵�ջ��Ҫд����-->��ģ��
//C++���ʵ��һ��ջ
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