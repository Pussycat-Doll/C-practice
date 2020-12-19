#define _CRT_SECURE_NO_WARNINGS 1
#include"Pagecache.h"


Span* Pagecache::NewSpan(size_t numpage)
{
	if (!_spanlists[numpage].Empty())//ֱ��ȡ��
	{
		Span* span = _spanlists[numpage].Begin();
		_spanlists[numpage].PopFront();
		return span;
	}
	for (size_t i = numpage + 1; i < MAX_PAGES; ++i)
	{
		if (!_spanlists[i].Empty())
		{
			//���ѵĹ���
			Span* span = _spanlists[i].Begin();
			_spanlists[i].PopFront();

			Span* splitspan = new Span;//����span
			splitspan->_pageid = span->_pageid + numpage;//����β��
			splitspan->_pagesize = span->_pagesize - numpage;

			span->_pagesize = numpage;

			_spanlists[splitspan->_pagesize].PushFront(splitspan);
			return span;
		}
	}

	Span* bigspan = new Span;
	bigspan->_pageid;
	bigspan->_pagesize = MAX_PAGES - 1;

	_spanlists[bigspan->_pagesize].PushFront(bigspan);

	return NewSpan(numpage);
}
