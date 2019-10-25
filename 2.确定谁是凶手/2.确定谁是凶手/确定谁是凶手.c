#define _CRT_SECURE_NO_WARNINGS 1
//2.
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int muder = 0;;
	for (muder = 'A'; muder < 'D'; muder++)
	{
		if ((muder != 'A') + (muder == 'C') + (muder == 'D') + (muder != 'D')==1)
			printf("凶手就是--%c\n", muder);
	}
	system("pause");
	return 0;
}
