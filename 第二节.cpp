#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
//
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", strlen(arr));//string length
//	//"abcdef";
//	//char arr[] = "abcdef";//'\0'���ַ�����һ��������־
//	//char arr2[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
//	//printf("%s\n", "abcdef");
//	//printf("%s\n", arr);
//	//printf("%s\n", arr2);
//
//	system("pause");
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	printf("c:\code\test.c\n");
//	system("pause");
//	return 0;
//}
//
//
//int main()
//{
//	//printf("%c", '\'');
//	//printf("%s\n", "abc");
//	//printf("%s\n", "a");
//	//printf("%s\n", "\"");
//	//printf("c:\\code\\test.c\n");
//	//printf("\a\a\a\a\a\a\a");
//
//	system("pause");
//	return 0;
//}
// 
// int main()
// {
// 	//printf("%d\n", strlen("c:test\130\test.c"));
// 	//aA@#$%
// 	//ASCII����
// 	//A-65
// 	//a-97
// 	//1234
// 	//
// 	//printf("%s\n", "c:test\138\test.c");
// 	//printf("%c\n", '\x030');
// 	//printf("%d\n", 'a');
// 	system("pause");
// 	return 0;
// }
//
//int main()
//{
//	int a = 10;
//	//printf("a = %d\n", a);//C++ע�ͷ��
//	/*printf("a = %d\n", a);*///C����ע�ͷ��
//	/*
//	printf("a = %d\n", a);
//	printf("a = %d\n", a);
//	printf("a = %d\n", a);
//	printf("a = %d\n", a);
//	*/
//	return 0;
//}
//

//if
//switch
//
//int main()
//{
//	int input = 0;
//	printf("������أ���Ҫ�ú�ѧϰ��\n");
//	scanf("%d", &input);
//	if(1 == input)
//	{
//		printf("��offer\n");
//	}
//	else
//	{
//		printf("������\n");
//	}
//	system("pause");
//	return 0;
//}
//


//for  while  do while
//int main()
//{
//	int line = 0;
//
//	while(line<=20000)
//	{
//		printf("�ú�ѧϰ\n");
//		line++;
//	}
//
//	printf("��ţ:%d\n", line);
//	system("pause");
//	return 0;
//}
//
//int Add(int x, int y)
//{
//	return x+y;
//}
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int sum = 0;
//
//	scanf("%d%d", &num1, &num2);
//	//sum = num1+num2;
//	sum = Add(num1, num2);
//	printf("sum = %d\n", sum);
//	system("pause");
//	return 0;
//}

//
//f(x, y) = x+y;
//

//
//int main()
//{
//	//int a = 10;
//	//����
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	//�±�
//	//printf("%d\n", arr[5]);
//	int i = 0;
//	for(i=0; i<10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	//char arr2[20] = {0};
//	return 0;
//}
//
//int main()
//{
//	//float a = 3/2.0;
//	//printf("%f\n", a);
//	//int a = 5%2;
//	//printf("a = %d\n", a);
//	//����
//	//����
//	//����
//	//ԭ��
//	//����
//	//����
//
//	int a = -1;
//	//f
//	//1111
//	//8421
//	//10000000000000000000000000000001
//	//11111111111111111111111111111110
//	//11111111111111111111111111111111
//	//
//	//11111111111111111111111111111110-����
//	//11111111111111111111111111111101
//	//10000000000000000000000000000010
//	//-2
//	int b = a<<1;
//	//���Ʋ�����-������λ
//	//
//	//1111
//	//8421
//	//00000000000000000000000000001010
//	//
//	//4�ֽ�
//	//32bit
//	//
//	printf("%d\n", b);
//	printf("%d\n", a);
//	system("pause");
//	return 0;
//}

//
//jie jian
//ing in
//
//int main()
//{
//	int a = 3;
//	int b = 5;
//	//int c = a&b;//��λ��
//	//int c = a|b;//��λ��
//	int c = a^b;//��λ���
//	c = 20;
//	c = c+1;
//	c += 1;
//	//011
//	//101
//	//110
//	//
//	printf("%d\n", c);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	//int a = 0;
//	//printf("%d\n", !a);
//	//int a = 0;//
//	//printf("%d\n", ~a);//
//	//int a = 10;
//	//int b = a++;//����++����ʹ�ã���++
//	//int b = ++a;//ǰ��++����++����ʹ��
//	//printf("a = %d\n", a);//11
//	//printf("b = %d\n", b);//11
//	int a = (int)3.14;
//	//int a = int(3.14);//err
//	printf("%d\n", a);
//	system("pause");
//	return 0;
//}
// 
// int main()
// {
// 	int a = 1;
// 	int b = 2;
// 	int c = 3;
// 	int d = (a=3, b=a+4, b, c/2);
// 	printf("%d\n", d);
// 	/*int a = 0;
// 	int b = 0;
// 	int max = 0;
// 	if(a>b)
// 	max = a;
// 	else
// 	max = b;
// 
// 	max = (a>b) ? (a) : (b);*/
// 
// // 	//int c = a && b;
// // 	int c = a || b;
// // 	printf("%d\n", c);
// 	system("pause");
// 	return 0;
// }
// 
//
//int main()
//{
//	//register int a = 10;//�����a���ڼĴ�����
//	unsigned int num1 = 10;
//	typedef unsigned int uint;
//	uint num2 = 10;
//	return 0;
//}
// 
// int main()
// {
// 	int a = 10;
// 	int age = 0;
// 	char first_name[10];
// 	char FirstName[10];
// 
// 	return 0;
// }


//int main()
//{
//	int a = 10;//1
//	int i = 0;
//	for(i=0; i<10; i++)
//	{
//
//	}
//	return 0;
//}

//void test()
//{
//	static int num = 0;
//	num++;
//	printf("%d ", num);
//}
//
//int main()
//{
//	int i = 0;
//	for(i=0; i<10; i++)
//	{
//		test();
//	}
//	system("pause");
//	return 0;
//}
//extern �����ⲿ����
//
//extern int g_val;
//extern void test();
//
//int main()
//{
//	//printf("%d\n", g_val);
//	test();//hehe
//	system("pause");
//	return 0;
//}

//�ܽ᣺
//static���ξֲ�����
//	�ı��������ڣ�����������
//static����ȫ�ֱ���
//	�ı��������򣬲�����������
//	�����ε�ȫ�ֱ���ֻ�����Լ����ڵ�Դ�ļ��ڲ�ʹ�ã����ܱ��ⲿʹ��
//static���κ���
//	�ı��������򣬲�����������
//	�����εĺ���ֻ�����Լ����ڵ�Դ�ļ��ڲ�ʹ�ã����ܱ��ⲿʹ��


//#define 
//define�����ʶ������
#define MAX 100
//define�����
//#define ADD(x, y) x+y

// 
// int main()
// {
// 	//int a = MAX;
// 	int sum = ADD(2, 3);
// 	printf("sum = %d\n", sum);
// 	system("pause");
// 	return 0;
// }
// 
// #define SQUARE(x) ((x)*(x))
// 
// int main()
// {
// 	printf("%d\n", SQUARE(2+1));
// 	//printf("%d\n", 2+1*2+1);
// 	system("pause");
// 	return 0;
// }
