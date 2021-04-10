#pragma once
#include"Common.h"
class Pagecache
{
public:
	Span* NewSpan(size_t num);//num页的span
	Span* GetIdToSpan(PAGE_ID id);
	void ReleaseSpanToPageCache(Span* span);
	
private:
	SpanList _spanlists[MAX_PAGES];
	std::map<PAGE_ID, Span*> _idSpanMap;//建立span与其所在页号的映射
};
static Pagecache pagecaCheInst;