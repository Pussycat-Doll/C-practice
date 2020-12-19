#pragma once
#include"Common.h"
class Pagecache
{
public:
	Span* NewSpan(size_t num);

	//向系统申请numpage页内存挂到自由链表
	void SystemAllocPage(size_t numpage);
private:
	SpanList _spanlists[MAX_PAGES];
};
static Pagecache pagecaCheInst;