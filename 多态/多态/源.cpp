#include<iostream>
using namespace std;

//class Car//�������麯�������ǳ����࣬�������ǲ��ܱ�ʵ�������������
//{
//public:
//	virtual void fun() = 0;//���麯��,����Ҫʵ��
//};
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}	
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Drive:public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Drive::Func1()" << endl;
//	}
//	virtual void Func3()
//	{
//		cout << "Drive::Func3()" << endl;
//	}
//	virtual void Func4()
//	{
//		cout << "Drive::Func4()" << endl;
//	}
//private:
//	int _c = 10;
//};

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
typedef void(*VF_PTR)();//����ָ��������
void PrintVFTable(VF_PTR* pTable)
{
	for (size_t i = 0; pTable[i] != 0; ++i)
	{
		printf("pfTable[%d]:%p->", i, pTable[i]);
		VF_PTR f = pTable[i];
		f();
	}
	cout << endl;
}
//void func()
//{
//	Base b1;
//	printf("vftptr:%p\n", *(int*)&b1);
//
//	int i = 0;
//	int* p1 = &i;
//	int* p2 = new int;
//	const char* p3 = "hello";
//
//	printf("ջ����:%p\n", p1);
//	printf("�ѱ���:%p\n", p2);
//	printf("����γ���:%p\n", p3);
//	printf("������麯����ַ:%p\n", &Base::Func2);
//	printf("������麯����ַ:%p\n", func);
//}
int main()
{
	/*Base* p = new Base;
	p->Func1();
	p->Func2();
	Drive* d = new Drive;
	d->Func1();
	d->Func2();*/
	//func();

	/*Base b;
	Drive d;
	PrintVFTable((VF_PTR*)(*(int*)&b));
	PrintVFTable((VF_PTR*)(*(int*)&d));*/

	Derive d;
	VF_PTR* vTableb1 = (VF_PTR*)(*(int*)&d);
	PrintVFTable(vTableb1);
	VF_PTR* vTableb2 = (VF_PTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVFTable(vTableb2);
	return 0;
}