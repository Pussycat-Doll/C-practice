#define _CRT_SECURE_NO_WARNINGS 1
/*��дһ�����򣬿���һֱ���ռ����ַ��� 
�����Сд�ַ��������Ӧ�Ĵ�д�ַ��� 
������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ��� 
��������ֲ������ 
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