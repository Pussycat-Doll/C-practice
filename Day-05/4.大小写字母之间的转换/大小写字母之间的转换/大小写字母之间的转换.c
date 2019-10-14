#define _CRT_SECURE_NO_WARNINGS 1
/*编写一个程序，可以一直接收键盘字符， 
如果是小写字符就输出对应的大写字符， 
如果接收的是大写字符，就输出对应的小写字符， 
如果是数字不输出。 
*/
#include<stdio.h>
int main()
{
	char input;
	while (scanf("%c",&input) != EOF)
	{
		if (input >= 'a'&&input <= 'z')
		{
			input = input - 32;
			printf("%c\n", input);
		}
		else if (input >= 'A'&&input <= 'Z')
		{
			input = input + 32;
			printf("%c\n", input);
		}
		else if (input >= '0'&&input <= '9')
		{
			continue;
		}

	}
	return 0;
}