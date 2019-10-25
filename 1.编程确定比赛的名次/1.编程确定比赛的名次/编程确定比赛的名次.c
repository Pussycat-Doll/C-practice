#define _CRT_SECURE_NO_WARNINGS 1
//1.
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a < 6; a++)                 /*  列出所有的可能性 */
	{
		for (b = 1; b < 6; b++)
		{
			for (c = 1; c < 6; c++)
			{
				for (d = 1; d < 6; d++)
				{
					for (e = 1; e < 6; e++)  
					{
						if ((b == 2 && a != 3) || (b != 2 && a == 3)) //根据每个人只说对一半，进行排除
							if ((b == 2 && e != 4) || (b != 2 && e == 4))
								if ((c == 1 && d != 2) || (c != 1 && d == 2))
									if ((c == 5 && d != 3) || (c != 5 && d == 3))
										if ((e == 4 && a != 1) || (e != 4 && a == 1))
										{
											if (120 == a*b*c*d*e)//排除每组中是名次有重复的可能性
												printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
										}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}