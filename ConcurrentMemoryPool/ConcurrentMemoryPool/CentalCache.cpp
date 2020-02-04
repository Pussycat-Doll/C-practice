#define _CRT_SECURE_NO_WARNINGS 1
#include"CentralCache.h"
#include"Pagecache.h"

// �����Ļ����ȡһ������Ϊnum,��СΪsize�Ķ����threadcache
//��Щ�ڴ������һ���Σ���start��ʼ����end����
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size)
{
	Span* span = GetOneSpan(size); 
	FreeList& freelist = span->_freelist;
	size_t actuallNum = freelist.PopRange(start, end, num);
	span->_usecount += actuallNum;
	return actuallNum;
}

//���ڴ�����ͷŹ�һ������ʱ���ͽ���黹��span
void CentralCache::ReleaseListToSpans(void* start, size_t size)
{

}

//��pagecache�л�ȡһ��span
Span* CentralCache::GetOneSpan(size_t size)
{
	//��ȡһ���ж����span
	size_t index = Sizeclass::ListIndex(size);
	//����spanlist
	SpanList& spanlist = _spanlists[index];
	Span* it = spanlist.Begin();
	while (it != spanlist.End())
	{
		if (!it->_freelist.Empty())//span�д��ڵȴ�ʹ�õ��ڴ棬��ȡ������
		{
			return it;
		}
		else
		{
			it = it->_next;
		}
	}
	//��ʱ��centralcache��û��������Ҫ���ڴ�Ķ�����Ҫ��pagecache��ȥȡ
	size_t numpage = Sizeclass::NumMovePage(size);
	Span* span = pagecaCheInst.NewSpan(numpage);
	return span;
}
