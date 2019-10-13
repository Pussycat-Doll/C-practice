#include<stdio.h>
int main()
{
   int a,b,c,y,n=0;int x;
   for (x=0;x<=999;x++)
   {a=x%1000/100;  //求第一位数 
    b=x%100/10;    //求第二位数
    c=x%10/1;      //求第三位数 
    y=a*a*a+b*b*b+c*c*c;
    if(y==x)
   {printf("%d  ",x);
    n++;}
    }
printf("水仙花数量为:%d",n);
}

