#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdlib>
//using namespace std;//�����ռ�
//int main()
//{
//	//int printf = 10;
//	//printf("hello world\n");������ͻ���ȿ�������һ��ľֲ�������
//	//����ý�����ֳ�ͻ�ķ����أ�
//	system("pause");
//	return 0;
//}
/*�����ռ�����ʹ�÷�ʽ��
  1.using nemaspace bit--���ʱ�ݣ���������������Ⱦ������Ķ����ų����ˣ�
  2.using bit::printf--ָ���ų�ĳһ��
  3.bit::printf--ָ�����ʣ����鷳
  */
//�����ռ����Ƕ��
#include<iostream>
#include<cstdlib>
using namespace std;//C++��׼�ⶼ����std�������ռ���
namespace bit//->����
{
	int printf = 10;
	void strcpy()
	{
		cout << "hahahaha" << endl;
	}
}
//int main()
//{
//	printf("Hello :%d\n", bit::printf);
//	bit::strcpy();
//	system("pause");
//	return 0;
//}
using std::cin;
using std::cout;
using std::endl;
//int main()
//{	
//	//std::cout << "Hello World" << std::endl;
//	int i = 20;
//	float j = 3.14159;
//	int *p = &i;
//	cout << "Hello World" << endl;//IO��
//	cout << i << endl;
//	cout << j << endl;
//	cout << *p << endl;
//	cout << i << endl << j << endl;
//	system("pause");
//	return 0;
//}
void testfunc(int a = 100)
{
	cout << a << endl;
}
//ȫȱʡ
void testFunc1(int a = 100, int b = 20, int c = 5)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
//��ȱʡ��ֻ�ܴ�������
void testFunc2(int a, int b = 20, int c = 5)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
//int main()
//{
//	testfunc();//û�в���ʱ��ʹ��Ĭ�ϲ�����
//	testfunc(10);
//	testFunc1(1);
//	testFunc1(1,2);
//	testFunc1(1,2,3);
//	testFunc2(1);
//	system("pause");
//	return 0;
//}

//��������
/*ΪʲôC���Բ�֧�����أ�C++֧�����أ���
 *���������ι���*/
void f(int i)
{

	printf("%d\n", i);
}
void f(double i)
{

	printf("%f\n", i);
}
int main()
{
	int i = 10;
	double d = 1.01;

	//cout << i;
	//cout.operator<<(i);

	//cout << d;
	//cout.operator<<(d);
	f(i);
	f(d);
	system("pause");
	return 0;
}
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{

	return 0;
}

