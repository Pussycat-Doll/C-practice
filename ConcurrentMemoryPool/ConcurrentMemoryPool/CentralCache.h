#pragma once
#include"Common.h"
class CentralCache
{
public:
	// �����Ļ����ȡһ������Ϊnum,��СΪsize�Ķ����threadcache
	//��Щ�ڴ������һ���Σ���start��ʼ����end����
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);

	//���ڴ�����ͷŹ�һ������ʱ���ͽ���黹��span
	void ReleaseListToSpans(void* start, size_t size);

	//��sapnlist ���� pagecache�л�ȡһ��span
	Span* GetOneSpan(size_t size);
private:
	SpanList _spanlists[NFREELIST];
};
static CentralCache centralcacheInst;//����̹߳���һ��CentralCache