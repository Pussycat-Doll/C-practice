#define _CRT_SECURE_NO_WARNINGS 1
//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n)
{
	if (n < 9)
		return n;
	else
		return n % 10 + DigitSum(n / 10);
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", DigitSum(num));
	system("pause");
	return 0;
}