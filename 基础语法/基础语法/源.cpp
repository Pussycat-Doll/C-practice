//#include<iostream>
//using namespace std;//C++�������ж������Ƿŵ�std�����ռ������
//
//int main()
//{
//	std::cout << "Hello world" << std::endl;
//	int i = 99;
//	std::cout << i;
//}
//using std::cout;
//using std::endl;
////���õĿ������һЩ����������Ϳ���չ����
////������Ŀ���Ƽ�����ȥ��
//int main()
//{
//	int i, d;
//	cout << "hello world" << endl;
//	std::cin >> i >> d;
//	cout << i << " " << d<<endl;
//}
//#include<iostream>
//using namespace std;
//
//void Func(int c = 10)//ȱʡ��������ڱ�̥����������˾��ô��Ĳ���
//{
//	cout << c << endl;
//}
//
////ȫȱʡ
//void Func1(int a = 10, int b = 80, int c = 999)
//{
//	cout << "a = "<<a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
////��ȱʡ(ȱʡ���ֲ���)���������������ȱʡ
//void Func2(int a, int b = 880, int c = 9999)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	Func();
//	Func(999);
//	Func1();
//	Func1(1,2);
//	//���ε�ʱ�򣬱���������Ҵ���
//	Func2(2);
//	return 0;
//}
//#include<iostream>
//using namespace std;
////��������Ҫ�󣺺�������ͬ������������/����/���͵�˳��ͬ
//int Add(int a, int b)
//{
//	return a + b;
//}
//int Add(int a, int b, int c)
//{
//	return a + b + c;
//} 
//double Add(double a, double b)
//{
//	return a + b;
//}
//long Add(long a, long b)
//{
//	return a + b;
//}
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1, 2, 3) << endl;
//	cout << Add(1.1, 2.2) << endl;
//	cout << Add(10L, 20L) << endl;
//
//	return 0;
//}
//�������⣺
//1��ʲô�Ǻ�������
//2��C++�����֧�ֺ������صģ�ΪʲôC���Բ�֧��

//Ԥ����->չ��ͷ�ļ������滻���������롢ȥ��ע��
//test.i
//����->����﷨�����ɻ�����
//test.s
//���->������ת�ɶ����ƵĻ�����
//test.o
//����->������Ŀ���ļ����ӵ�һ��
//���ɿ�ִ�г���.exe�ļ�

//extern�ؼ���
//��C������ʹ��
//C++ʵ�ִ�����ұ���ɶ�̬����߾�̬��ʱ
//Ҫ��extern "C"
//��C++��ʹ��ʱ���������ڵ�ͷ�ļ��Ϳ�
//Ϊʲô�أ���ΪC�в�����C++����������

//�����������ι���

//����
#include<iostream>
using namespace std;
int main()
{
	//int a = 99;
	//int& ra = a;//��ʾra��a�ı���,����һ��ռ�
	//cout << "a = " << a << &a << endl;
	//cout << "ra = " << ra << &ra << endl;
	/*1�����ñ����ڶ����ʱ���ʼ��
	  2��һ�����������ж������
	  3������һ������һ��ʵ�壬�Ͳ�����������ʵ��*/

	//������
	const int a = 99;
	//int& b = a;//���벻ͨ����ԭ��a��ֻ����b�ǿɶ���д��
	const int& b = a;

	int c = 100;
	int& d = c;
	const int& e = c;//c �ǿɶ���д��e��ֻ��
	//�ܽ᣺������Ȩ��ֻ������С����������

	int i = 0;
	double db = i;//��ʽ����ת��
	const double& rd = i;
	// ��ʽ����ת��������һ��double����ʱ����
	//rd ���õľ�����ʱ��������ʱ�������г���
	return 0;
}

