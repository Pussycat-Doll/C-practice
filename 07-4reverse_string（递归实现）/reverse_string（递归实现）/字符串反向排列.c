#define _CRT_SECURE_NO_WARNINGS 1
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
#include<stdio.h>
#include<stdlib.h>
void reverse_string(char *string)
{
	if (*string != '\0')
	{
		string++;
		reverse_string(string);
		printf("%c", *(string - 1));
	}
}
int main()
{
	char str[100] = "0";
	scanf("%s", str);
	reverse_string(str);
	system("pause");
	return 0;
}