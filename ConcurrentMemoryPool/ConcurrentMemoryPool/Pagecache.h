#pragma once
#include"Common.h"
class Pagecache
{
public:
	Span* NewSpan(size_t num);

private:
	SpanList _spanlists[MAX_PAGES];
};
static Pagecache pagecaCheInst;