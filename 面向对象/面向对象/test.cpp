//#include<iostream>
//using namespace std;
//
//
//class Student
//{
//	//��Ա��������������Ա������������ж��壬
//	//���������ܻὫ�䵱������������
//public:
//	void ShowInfor()
//	{
//		cout << _age << endl;
//		cout << _name << endl;
//		cout << _stuid << endl;
//	}
//	int GetAGe()
//	{
//		return _age;
//	}
//private:
//	char _name[10];//��Ա����һ��������ǱȽ���˽��,�������˽�л��߱���
//	int _age;
//	int _stuid;
//	 	 
//};
////struct��Ĭ���޶�����Public
////classĬ���ǹ��е�
////int main()
////{
////	Student s1;
////	Student s2;
////	//s1._age = 19;
////	cout << s1.GetAGe() << endl;
////	return 0;
////}
////1��C������struct����������ṹ���
////2��C++�У�����C��struct����ṹ����÷�������ͬʱstructҲ������������
//
////����һ�����ݽṹջ����
//class Stack
//{
//public:
//	void Init(size_t n);
//	void Destory();
//	void Push(int x)//�����涨��
//	{
//
//	}
//	void Pop();//���ڶ��壬��������
//	bool empty();
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//void Stack::Pop()//���ⶨ��
//{
//
//}
////��ζ����һ����
////��װ��1�������ݺͷ������嵽һ��
////		2��������㿴�ĸ��㿴��������㿴�ķ�װ����(�����޶���public private protected)
///*
//1.�����Ͷ��������
//������һ�ֳ�ŵ������ʵ���ϻ�û��
//������ǰ���������Ѿ������
//*/
//int main()
//{
//
//	//��ʵ����������,�൱�ڶ��������ĳ�Ա����
//	Stack s1;
//	Stack s2;
//	Stack s3;
//	//s1._a = nullptr;���ܷ���
//	s1.Push(1);
//
//	cout << sizeof(s1) << endl;//������ֻ�洢��ĳ�Ա����,���洢��ĳ�Ա����
//	//��Ϊÿ�������һ�������ʵ�������������ÿ������ĳ�Ա�������Դ洢��ͬ��
//	//��ֵ�����ǵ��õĺ���ȷʵ��ͬһ��
//	//���ÿ�����󶼷ų�Ա����������Щ��Ա����ȴ��һ���ģ����Ǻ��˷ѿռ��
//	//��μ���һ����ʵ�������Ķ���Ĵ�С---�����Ա����֮�ͣ����ҿ����ڴ�������
//
//	//��ϰ�ڴ����
//	//û�г�Ա��������Ĵ�С��1��Ϊʲô����0
//	//��һ���ֽڲ���Ϊ�˴����ݣ�����Ϊ�˱�ʾ�������
//	return 0;
//}

/*
ʵ�����������Լ���������Ͷ��������
1����������
2���Զ�������
*/
#include<iostream>
using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;//cout<<this->_a<<endl;
//	}
//	void Show()
//	{
//		cout << "show()" <<endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;
//	p->Print();//�������
//	p->Show();//��������
//	/*
//	����show������ʱ�򣬴���thisָ����һ����ָ�룬�����ں����в�û�з���thisָ��
//	����Print�����У�ʵ���Ϸ�����thisָ�룬����ָ��Ϊ�գ����Է����˳������
//	*/
//	return 0;
//}
class Time
{
private:
	int _hour;
	int _minute;
	int _second;

};
class Date
{
public:
//	void Init(int year, int month, int day)//void Init(Date* this,int year,int month,int day)
//	{
///*this->*/_year = year;
//		_month = month;
//		_day = day;
//	}
	//Date(int year, int month, int day)//���캯������������ͬ���������أ���ɳ�ʼ�����޷���ֵ
	//	//ʵ����ʱ�Զ�����
	//	//�������û����ʾ���幹�캯������C++������������Ĭ�ϵĹ��캯��
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	/*˫�꣺
	1������������͵ĳ�Ա����û��������
	2������Զ������͵ĳ�Ա�������������Ĺ��캯����ʼ��
	*/
	/*Date()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}*/
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//�޲εĺ�ȫȱʡ�Ĺ��캯��ֻ����һ��
	/*
	Ĭ�ϵĹ��캯��--��1���Լ�ʵ�ֵ��޲εĹ��캯��
					  2���Լ�ʵ�ֵ�ȫȱʡ�Ĺ��캯��
					  3���������Զ����ɵ�
	*/
	void Print()//void Print(Date* this)
		//˭������������������thisָ��s
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	/*
	this�����ĸ��ط�����
	����ջ�ϵģ���Ϊ����һ���β�(vs������ecx����Ĵ����ϵ�)
	*/
private:
	int _year;
	int _month;
	int _day;

	//Time t;

};
int main()
{
	Date d2;

	d2.Print();
	return 0;
}