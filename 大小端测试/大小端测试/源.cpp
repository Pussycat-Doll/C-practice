#include<iostream>
using namespace std;

int test()
{
	int i = 1;
	return (*(char*)&i);
}
//int main()
//{
//	if (test() == 1)
//		cout << "С��ģʽ" << endl;
//	else
//		cout << " ���ģʽ" << endl;
//	return 0;
//
//}

int main()
{
    union
	{
		char ch;
		int i;
	}; 
	i = 0x01020304;
	if (ch == 0x01)
		cout << "���" << endl;
	else if (ch == 0x04)
		cout << "С��" << endl;
	else
		cout << "�޷�ʶ��" << endl;
	return 0;
}