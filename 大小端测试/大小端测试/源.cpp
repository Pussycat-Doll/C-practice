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
//		cout << "小端模式" << endl;
//	else
//		cout << " 大端模式" << endl;
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
		cout << "大端" << endl;
	else if (ch == 0x04)
		cout << "小端" << endl;
	else
		cout << "无法识别" << endl;
	return 0;
}