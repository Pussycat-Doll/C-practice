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
//#include<iostream>
//using namespace std;
//int main()
//{
//	//int a = 99;
//	//int& ra = a;//��ʾra��a�ı���,����һ��ռ�
//	//cout << "a = " << a << &a << endl;
//	//cout << "ra = " << ra << &ra << endl;
//	/*1�����ñ����ڶ����ʱ���ʼ��
//	  2��һ�����������ж������
//	  3������һ������һ��ʵ�壬�Ͳ�����������ʵ��*/
//
//	//������
//	const int a = 99;
//	//int& b = a;//���벻ͨ����ԭ��a��ֻ����b�ǿɶ���д��
//	const int& b = a;
//
//	int c = 100;
//	int& d = c;
//	const int& e = c;//c �ǿɶ���д��e��ֻ��
//	//�ܽ᣺������Ȩ��ֻ������С����������
//
//	int i = 0;
//	double db = i;//��ʽ����ת��
//	const double& rd = i;
//	// ��ʽ����ת��������һ��double����ʱ����
//	//rd ���õľ�����ʱ��������ʱ�������г���
//
//	const int x = 99;
//	int y = x;//y���޸Ĳ�Ӱ��x,����һ����ͨ�ĸ�ֵ�Ĺ���
//
//	int h = 89;
//	const int gg = h;//����ͬ��
//
//	//Ȩ�޵���Сֻ�������ú�ָ��
//
//	/*const int* cp1 = &a;
//	int* p1 = cp1;*///����ͨ�����룬����Ȩ�޵ķŴ�
//
//	int* p2 = &h;
//	const int* cp2 = p2;//����Ȩ�޵���С
//
//	return 0; 
//}

//���õ�ʹ�ó�����1��������
//				  2������������ֵ

//#include<iostream>
//using namespace std;
//
//void swap_c(int *p1, int *p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 1,b = 99;
//	swap_c(&a, &b);
//	swap(a,b);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int Count1()//��ֵ����
//{
//    static int n = 0;
//    n++;
//
//    return n;
//    //��ʱ������࿪һ��ռ�
//}
//
//int& Count2()//�����÷���
//{
//    static int m = 0;
//    m++;
//
//    return m;
//    //��ʱ������m�ı����������ٿ�һ��ռ�
//}
//
//int main()
//{
//    //int& r1 = Count1();���벻ͨ����Count1�ķ���ֵ�����һ����ʱ���������г��ԣ���ֻ����
//    const int& r1 = Count1();
//    int& r2 = Count2();//Count2�ķ���ֵ���ص���n�ı������ǿɶ���д�ģ�Ȩ��û�з����ı�
//    return 0;
// }

#include<iostream>
#include<map>
using namespace std;

//int main()
//{
//	//int a = 10;
//	//int& b = a;//���ñ����ʼ��,�÷����鿴�����Կ������õĵײ�ʵ��ʵ�ʸ�ָ����
//
//	//int* p = &a;//ָ��û��Ҫ��
//
//	char c1 = 0;
//	char& c2 = c1;
//	char* p3 = &c1;
//	cout << sizeof(c2) << endl;//���Ϊ1
//	cout << sizeof(p3) << endl;//���Ϊ4
//	return 0;
//}

//int ADD(int left, int right)
//{
//	return left + right;
//}
//
//inline void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
////Ƶ������SWAP�����������ĵ�
////���������1��C����ʹ�ú꺯��
////2��C++ʹ�������������(�ÿռ任ʱ�䣬���õ���ջ֡�ˣ�һ��������С����
////����20�����£��ݹ麯��ʲô��)
//int main()
//{
//	int ret = ADD(1, 2);
//	int a = 99, b = 90;
//	swap(a, b);
//}

//void TestFor(int arr[])
//	{
//		for (auto& arr)//���벻ͨ������Ϊ�����ڴ��ι����л�ת����ָ��
//		{
//			cout << e << endl;
//		}
//	}

void fun(int n)
{
	cout << "����" << endl;
}
void fun(int* p)
{
	cout << "����ָ��" << endl;
}
int main()
{
	////auto ����������������Ҳ����
	//int a = 0;
	//auto b = a;//b�������Ǹ���a�������Զ��Ƶ���
	//int& c = a;
	//auto& d = a;
	//auto e = &a;

	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;
	//cout << typeid(c).name() << endl;
	//cout << typeid(d).name() << endl;
	//cout << typeid(e).name() << endl;

	//std::map<std::string, std::string> dict;
	//std::map<std::string, std::string>::iterator it1 = dict.begin();
	//auto it1 = dict.begin();
	//map<string, string> dict;

	//int array[] = { 1,2,3,4,5 };
	//for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	//{
	//	cout << array[i] << " ";
	//}
	//cout << endl;
	////C++11->��Χfor(�﷨��)---���ص㣺д�����Ƚϼ��
	//for (auto& e : array)//ֻ�ǰ������е�ÿһ��Ԫ�ظ�ֵ��E��E�ĸı䲢��Ӱ��������Ԫ�صĸı�
	//	//����Ҫ�ı������е�ֵ��Ӧ�ü�������
	//{
	//	e *= 2;
	//	cout << e << " ";
	//}
	//cout << endl;
	//for (auto& e : array)
	//{
	//	cout << e << " ";
	//}

	int* p1 = NULL;
	int* p2 = nullptr;//C++�Ƽ������
	fun(0);
	fun(NULL);//ƥ�䵽int�Ĳ�������Ϊ�ڵײ�NULLʵ����һ����
	//#define NULL 0
	//#define NULL (void*)
	//Ԥ����� fun(0)
	fun(nullptr);//fun((void*)0)
	return 0;
}
