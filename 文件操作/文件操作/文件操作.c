#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//int a = 10000;
	//FILE* pf = fopen("test.txt", "wb");
	//fwrite(&a, 4, 1, pf);//以二进制的形式写到文件中
	//char buff[10];
	//itoa(a, buff, 10);
	//fputs(buff, pf);

	//fclose(pf);
	//pf = NULL;

	FILE* fp1 = fopen("文件操作.txt", "w");//只写方式打开
	if (fp1 == NULL)
	{
		printf("打开文件方式失败\n");
	}
	FILE* fp2 = fopen("文件操作.c", "r");//只读方式打开
	if (fp2 == NULL)
	{
		printf("打开文件方式失败\n");
	}
	fputs("覆盖写", fp1);
	//char ch = fgetc(fp2);
	//while (ch != EOF)
	//{
	//	fputc(ch, fp1);
	//	ch = fgetc(fp2);
	//}
	//FILE* fp1 = fopen("文件操作.txt", "w");//"w"为覆盖写区别与"a"为追加写
	//if (fp1 == NULL)
	//{
	//	printf("打开文件方式失败\n");
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