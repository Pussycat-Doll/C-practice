#pragma once
#include"Common.h"
class Pagecache
{
public:
	Span* NewSpan(size_t num);

	//��ϵͳ����numpageҳ�ڴ�ҵ���������
	void SystemAllocPage(size_t numpage);
private:
	SpanList _spanlists[MAX_PAGES];
};
static Pagecache pagecaCheInst;