#include<stdio.h>
int main()
{
   int a,b,c,y,n=0;int x;
   for (x=0;x<=999;x++)
   {a=x%1000/100;  //���һλ�� 
    b=x%100/10;    //��ڶ�λ��
    c=x%10/1;      //�����λ�� 
    y=a*a*a+b*b*b+c*c*c;
    if(y==x)
   {printf("%d  ",x);
    n++;}
    }
printf("ˮ�ɻ�����Ϊ:%d",n);
}

