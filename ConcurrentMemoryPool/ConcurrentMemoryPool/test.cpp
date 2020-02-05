#define _CRT_SECURE_NO_WARNINGS 1
#include"ThreadCache.h"

#include<vector>
void UnitThreadCache()
{
	ThreadCache tc;
	vector<void* > v;
	for (size_t i = 0; i < 21; ++i)
	//ΪʲôҪ����21���ڴ棿
		//(num==20)�ó������е�ʱ�����if��䣬Ҳ��һelse��䣬������(�׺в���)
	{
		v.push_back(tc.Allocte(7));//����7���ֽ�
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
	[1,128] 8byte���� freelist[0,16) <--- 128/8 = 16
	[129,1024] 16byte���� freelist[16,72) <--- (1024-128)/16 + 16= 72
	[1025,8*1024] 128byte���� freelist[72,128) <--- (8*1024-1024)/128 + 72 = 128
	[8*1024 + 1,64*1024] 1024byte���� freelist[128,184)<---(64*1024 - 8*1024)/1024 + 128 = 184
	��������������ÿһ�����
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