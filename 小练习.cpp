#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
//
//int main()
//{
//	char ch = 'w';
//	char *pc = &ch;
//	int a = 10;
//	int *p = &a;//ָ�����
//	//*p = 20;//�����ò�����
//	printf("a = %d\n", *p);
//	//printf("%p\n", &a);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	//int a = 10;
//	//int *pa = &a;
//	//printf("%d\n", sizeof(pa));
//	char ch = 'w';
//	char *pc = &ch;
//	printf("%d\n", sizeof(pc));//
//
//	system("pause");
//	return 0;
//}
//
//struct Stu
//{
//	char name[30];
//	int age;
//	float score;
//};
//
////& *
////. ->
//
//int main()
//{
//	struct Stu s = {"����", 20, 55.5};
//	struct Stu* ps = &s;
//	printf("%s\n", ps->name);
//	printf("%s\n", (*ps).name);
//	//printf("%s\n", s.name);
//	//printf("%d\n", s.age);
//	//printf("%f\n", s.score);
//
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int age = 10;
//	if(age>=18)
//		printf("����ȥ����\n");
//	else
//		printf("�ú�ѧϰ\n");
//	system("pause");
//	return 0;
//}

//
//int main()
//{
//	int age = 80;
//	if(age<18)
//		printf("����\n");
//	else if(age>=18 && age<30)
//	{
//		printf("����\n");
//		printf("���\n");
//	}
//	else if(age>=30 && age<50)
//		printf("����\n");
//	else
//		printf("����\n");
//	system("pause");
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if(a == 1)
//	{
//		if(b == 2)
//			printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int num = 1;
//	//
//	//��C�����ȱ�ݡ�
//	//��C��ָ�롷
//	//��Cר�ұ�̡�
//	//
//	if(5 == num)
//		printf("hehe\n");
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	//1-100
//	int i = 0;
//
//	for(i=1; i<=100; i+=2)
//	{
//		printf("%d ", i);
//	}
//
//	/*for(i=1; i<=100; i++)
//	{
//		if(i%2 == 1)
//		{
//			printf("%d ", i);
//		}
//	}*/
//	system("pause");
//	return 0;
//}

//
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch(day)
//	{
//	case 1:
//		printf("����1\n");
//		break;
//	case 2:
//		printf("����2\n");
//		break;
//	case 3:
//		printf("����3\n");
//		break;
//	case 4:
//		printf("����4\n");
//		break;
//	case 5:
//		printf("����5\n");
//		break;
//	case 6:
//		printf("����6\n");
//		break;
//	case 7:
//		printf("����7\n");
//		break;
//	}
//	system("pause");
//	return 0;
//}

//
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch(day)
//	{
//	default:
//		printf("ѡ�����\n");
//		break;
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//	case 7:
//		printf("��Ϣ��\n");
//		break;
//	
//	}
//	system("pause");
//	return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:m++;
//	case 2:n++;
//	case 3:
//		switch (n)
//		{//switch����Ƕ��ʹ��
//		case 1:n++;
//		case 2:m++;n++;break;
//		}
//	case 4:m++;break;
//	default:
//		break;
//	}
//	//5 3-7
//	//3 1
//	//4 3
//	//
//	printf("m = %d, n = %d\n", m, n);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	//while(1)
//	//	printf("hehe\n");
//	int i = 1;
//	while(i<=10)
//	{
//		i++;
//		if(i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int ch = 0;
//	//EOF-end of file
//	while((ch=getchar()) != EOF)
//	{
//		if(ch<'0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//// 	int ret = getchar();
//// 	putchar(ret);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 1;//��ʼ��
//
//	while(i<=10)//�жϲ���
//	{
//		printf("%d\n", i);
//		i++;//��������
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//
//	for(i=1; i<=10; i++)
//	{
//		if(i==5)
//			continue;
//		printf("%d ", i);
//	}
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//
//	for(i=0; i<=12; i++)
//	{
//		printf("hehe\n");
//		arr[i] = 0;
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = {0};
//	int i = 0;
//	for(i=0; i<10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//int main()
//{
//	/*int i = 0;
//	int j = 0;
//	for(i=0; i<10; i++)
//	{
//	for(j=0; j<10; j++)
//	{
//	printf("hehe\n");
//	}
//	}*/
//	int x, y;
//	for (x = 0, y = 0;y<5,x<2; ++x, y++)
//	{
//		printf("hehe\n");
//	}
//
//	system("pause");
//	return 0;
//}

int main()
{
	/*int a = 10;
	int b = 20;
	int c = b=a+2;*/

	int i = 1;
	do
	{
		i++;
		if(i == 5)
			continue;
		printf("%d ", i);
	}
	while(i<=10);
	system("pause");
	return 0;
}
