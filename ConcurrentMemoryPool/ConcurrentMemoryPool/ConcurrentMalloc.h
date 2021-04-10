#pragma once

void* ConcurrentMalloc(size_t size)
{
	if (pThreadCache == nullptr)
		pThreadCache = new ThreadCache();
	return pThreadCache->Allocte(size);
}
void ConcurrentFree(void* ptr)
{
	pThreadCache->Deallocte(ptr,8);
}