#pragma once
#include"Common.h"
class Pagecache
{
public:
	Span* NewSpan(size_t num);//numҳ��span
	Span* GetIdToSpan(PAGE_ID id);
	void ReleaseSpanToPageCache(Span* span);
	
private:
	SpanList _spanlists[MAX_PAGES];
	std::map<PAGE_ID, Span*> _idSpanMap;//����span��������ҳ�ŵ�ӳ��
};
static Pagecache pagecaCheInst;