#define _CRT_SECURE_NO_WARNINGS 1
#include"CentralCache.h"
#include"Pagecache.h"

// 从中心缓存获取一定数量为num,大小为size的对象给threadcache
//这些内存对象是一整段，以start开始，以end结束
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size)
{
	Span* span = GetOneSpan(size); 
	FreeList& freelist = span->_freelist;
	size_t actuallNum = freelist.PopRange(start, end, num);
	span->_usecount += actuallNum;
	return actuallNum;
}

//当内存对象释放够一定数量时，就将其归还到span
void CentralCache::ReleaseListToSpans(void* start, size_t size)
{

}

//从pagecache中获取一个span
Span* CentralCache::GetOneSpan(size_t size)
{
	//获取一个有对象的span
	size_t index = Sizeclass::ListIndex(size);
	//遍历spanlist
	SpanList& spanlist = _spanlists[index];
	Span* it = spanlist.Begin();
	while (it != spanlist.End())
	{
		if (!it->_freelist.Empty())//span中存在等待使用的内存，就取出来用
		{
			return it;
		}
		else
		{
			it = it->_next;
		}
	}
	//此时，centralcache中没有我们需要的内存的对象，需要从pagecache中去取
	size_t numpage = Sizeclass::NumMovePage(size);
	Span* span = pagecaCheInst.NewSpan(numpage);
	return span;
}
