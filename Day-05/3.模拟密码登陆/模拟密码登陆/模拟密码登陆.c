#define _CRT_SECURE_NO_WARNINGS 1
/*编写代码模拟三次密码输入的场景。 
 最多能输入三次密码，密码正确，提示“登录成功”,密码错误， 
 可以重新输入，最多输入三次。三次均错，则提示退出程序。 */
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
			printf("请输入您的11位密码 ：>\n");
			gets(get_password);
		}
		n--;
		if (strcmp(get_password,password) == 0)
		{
			printf("正在登录中...\n");
			printf("------------------------------------\n");
			printf("登录成功！\n");
			break;
		}
		else
		{
			printf("正在登录中...\n");
			printf("------------------------------------\n");
			printf("登录失败！\n请您重新输入密码：>\n");
			printf("温馨提示：您输入密码的机会还有%d次 \n", n);
			gets(get_password);
		}
	}
	system("pause");
	return 0;
}
