#define _CRT_SECURE_NO_WARNINGS 1
/*��д����ģ��������������ĳ����� 
 ����������������룬������ȷ����ʾ����¼�ɹ���,������� 
 �����������룬����������Ρ����ξ�������ʾ�˳����� */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char password[12] = { "bitekeji666" };
	char get_password[12] = { "0" };
	int j = 0;
	int i = 0;
	int n = 3;
	for (i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			printf("����������11λ���� ��>\n");
			gets(get_password);
		}
		n--;
		if (strcmp(get_password,password) == 0)
		{
			printf("���ڵ�¼��...\n");
			printf("------------------------------------\n");
			printf("��¼�ɹ���\n");
			break;
		}
		else
		{
			printf("���ڵ�¼��...\n");
			printf("------------------------------------\n");
			printf("��¼ʧ�ܣ�\n���������������룺>\n");
			printf("��ܰ��ʾ������������Ļ��ỹ��%d�� \n", n);
			gets(get_password);
		}
	}
	system("pause");
	return 0;
}
