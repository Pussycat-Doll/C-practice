#define _CRT_SECURE_NO_WARNINGS 1
#include"ThreadCache.h"

#include<vector>
void UnitThreadCache()
{
	ThreadCache tc;
	vector<void* > v;
	for (size_t i = 0; i < 21; ++i)
	//为什么要申请21次内存？
		//(num==20)让程序运行的时候既走if语句，也走一else语句，都试试(白盒测试)
	{
		v.push_back(tc.Allocte(7));//申请7个字节
	}
	for (size_t i = 0; i < 21; ++i)
	{
		printf("[%d]->%p\n", i, v[i]);
	}
	for (auto ptr : v)
	{
		tc.Deallocte(ptr, 7);
	}
}
void UnitTestSizeClass()
{
	/*
	[1,128] 8byte对齐 freelist[0,16) <--- 128/8 = 16
	[129,1024] 16byte对齐 freelist[16,72) <--- (1024-128)/16 + 16= 72
	[1025,8*1024] 128byte对齐 freelist[72,128) <--- (8*1024-1024)/128 + 72 = 128
	[8*1024 + 1,64*1024] 1024byte对齐 freelist[128,184)<---(64*1024 - 8*1024)/1024 + 128 = 184
	根据条件来测试每一种情况
	*/
	cout << Sizeclass::RoundUp(1) << endl;
	cout << Sizeclass::RoundUp(127) << endl<<endl;

	cout << Sizeclass::RoundUp(129) << endl;
	cout << Sizeclass::RoundUp(1023) << endl<<endl;

	cout << Sizeclass::RoundUp(1025) << endl;
	cout << Sizeclass::RoundUp(8*1024) << endl << endl;

	cout << Sizeclass::RoundUp(8 * 1024 + 1) << endl;
	cout << Sizeclass::RoundUp(64 * 1024) << endl << endl;

	cout << Sizeclass::ListIndex(1) << endl;
	cout << Sizeclass::ListIndex(127) << endl << endl;

	cout << Sizeclass::ListIndex(129) << endl;
	cout << Sizeclass::ListIndex(1023) << endl << endl;

	cout << Sizeclass::ListIndex(1025) << endl;
	cout << Sizeclass::ListIndex(8 * 1024) << endl << endl;

	cout << Sizeclass::ListIndex(8 * 1024 + 1) << endl;
	cout << Sizeclass::ListIndex(64 * 1024) << endl << endl;
}
int main()
{
	UnitTestSizeClass();
	//UnitThreadCache();
	system("pause");
	return 0;
}