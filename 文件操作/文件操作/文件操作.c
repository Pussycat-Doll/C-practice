#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//int a = 10000;
	//FILE* pf = fopen("test.txt", "wb");
	//fwrite(&a, 4, 1, pf);//�Զ����Ƶ���ʽд���ļ���
	//char buff[10];
	//itoa(a, buff, 10);
	//fputs(buff, pf);

	//fclose(pf);
	//pf = NULL;

	FILE* fp1 = fopen("�ļ�����.txt", "w");//ֻд��ʽ��
	if (fp1 == NULL)
	{
		printf("���ļ���ʽʧ��\n");
	}
	FILE* fp2 = fopen("�ļ�����.c", "r");//ֻ����ʽ��
	if (fp2 == NULL)
	{
		printf("���ļ���ʽʧ��\n");
	}
	fputs("����д", fp1);
	//char ch = fgetc(fp2);
	//while (ch != EOF)
	//{
	//	fputc(ch, fp1);
	//	ch = fgetc(fp2);
	//}
	//FILE* fp1 = fopen("�ļ�����.txt", "w");//"w"Ϊ����д������"a"Ϊ׷��д
	//if (fp1 == NULL)
	//{
	//	printf("���ļ���ʽʧ��\n");
	//}
	fclose(fp1);
	fclose(fp2);
	system("pause");
	return 0;
}


//int main()
//{
//	FILE *fp;
//	char str[] = "This is runoob.com";
//
//	fp = fopen("file.txt", "w");
//	fwrite(str, sizeof(str), 1, fp);
//
//	fclose(fp);
//	system("pause");
//	return(0);
//}