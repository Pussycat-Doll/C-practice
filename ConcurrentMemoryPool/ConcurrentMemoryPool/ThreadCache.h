#pragma once
#include"Common.h"

class ThreadCache
{
public:
	//�����ڴ���ͷ��ڴ�
	void* Allocte(size_t size);
	void Deallocte(void* ptr, size_t size);
	//�����Ļ����ȡ�ڴ�
	void* FetchFromCentralCache(size_t index);
private:
	FreeList _freelist[NFREELIST];//���ָ�������(ӳ���) 
};