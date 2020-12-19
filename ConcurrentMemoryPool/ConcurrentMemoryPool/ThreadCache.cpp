#define _CRT_SECURE_NO_WARNINGS 1

#include"ThreadCache.h"
#include"CentralCache.h"
void* ThreadCache::Allocte(size_t size)//申请内存
{
	size_t index = Sizeclass::ListIndex(size);//计算申请内存在freelist中的下标
	FreeList& freeList = _freelist[index];
	if (!freeList.Empty())//有内存
		return freeList.Pop();
	else//没有内存,要从CentralCache取内存
	{
		return FetchFromCentralCache(Sizeclass::RoundUp(size));//根据size的大小还要进行对齐
		//为什么要有CentralCache?为了均衡资源和为内存碎片做准备
	} 
}
 
//释放内存，不是真的释放内存，而是把不用的再重新再挂到freelist中
void ThreadCache::Deallocte(void* ptr,size_t size)
{
	size_t index = Sizeclass::ListIndex(size);
	FreeList& freeList = _freelist[index];
	freeList.Push(ptr);//挂上自由链表
	//if ()
	{//当释放的内存太多，就直接还回CentralCache
		//ReleaseToCentralCache();
	}
}
//独立测试threadcache
//从中心缓存获取Num个对象，返回其中一个的指针，剩下的num-1被挂到freelist中等待申请
//void* ThreadCache::FetchFromCentralCache(size_t index)
//{
//	//模拟取内存对象 的代码，测试ThreadCache的逻辑
//	size_t num = 20;//与单个对象的大小有关，还要进行调整，获取批量的内存
//	size_t size = (index + 1) * 8;//计算单个内存的大小
//	char* start = (char*)malloc(size*num);
//	char* cur = start; 
//	for (size_t i = 0; i < num - 1; ++i)//将其连起来//为什么是num-1
//	{
//		char* next = cur + size;
//		NextObj(cur) = next;
//		cur = next;
//	}
//	NextObj(cur) = nullptr;//最后一个要指向空
//	void* head = NextObj(start);
//	void* tail = cur;
//
//	_freelist[index].PushRange(head, tail);
//
//	return start;
//}

void* ThreadCache::FetchFromCentralCache(size_t size)
{
	size_t num = Sizeclass::NumMoveSize(size);
	//从centralcache中获取内存
	void* start = nullptr;
	void* end = nullptr;
	size_t ActuallNum = centralcacheInst.FetchRangeObj(start, end, num, size);
	if (ActuallNum == 1)//至少获取一个内存对象，失败会抛异常
		return start;
	else//多个内存对象被申请
	{
		size_t index = Sizeclass::ListIndex(size);
		FreeList& list = _freelist[index];
		list.PushRange(NextObj(start), end);//取走要用的一个，再把剩下的挂起来
		return start;
	}
}