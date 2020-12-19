#pragma once
#include"Common.h"

class ThreadCache
{
public:
	//申请内存和释放内存
	void* Allocte(size_t size);
	void Deallocte(void* ptr, size_t size);
	//从中心缓存获取内存
	void* FetchFromCentralCache(size_t index);
private:
	FreeList _freelist[NFREELIST];//存放指针的链表(映射表) 
};