#define _CRT_SECURE_NO_WARNINGS 1
//2.
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int muder = 0;;
	for (muder = 'A'; muder < 'D'; muder++)
	{
		if ((muder != 'A') + (muder == 'C') + (muder == 'D') + (muder != 'D')==1)
			printf("���־���--%c\n", muder);
	}
	system("pause");
	return 0;
}
