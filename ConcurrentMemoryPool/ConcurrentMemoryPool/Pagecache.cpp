#define _CRT_SECURE_NO_WARNINGS 1
#include"Pagecache.h"
Span* Pagecache::NewSpan(size_t numpage)
{
	if (!_spanlists[numpage].Empty())
	{
		Span* span = _spanlists[numpage].Begin();
		_spanlists[numpage].PopFront;
		return span;
	}
	for (size_t i = numpage + 1; i < MAX_PAGES; ++i)
	{
		if (!_spanlists[i].Empty())
		{
			Span* span = _spanlists[i].Begin();
			_spanlists[i].PopFront();

			Span* splitspan = new Span;//·ÖÁÑspan
			splitspan->_pageid = span->_pageid + numpage;
			splitspan->_pagesize = span->_pagesize - numpage;

			span->_pagesize = numpage;
			return span;
		}
	}
}
