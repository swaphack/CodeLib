#include "PtrCache.h"
#include "Memory.h"

using namespace sys;


PtrCache::PtrCache(char* ptr, uint32 size)
{
	_cacheInfo.t1 = ptr;
	_cacheInfo.t2 = size;
}

PtrCache::~PtrCache()
{

}

void PtrCache::reset()
{
	_cursor = 0;
}

char* PtrCache::alloctPtr(uint32 size)
{
	if (size + _cursor >= _cacheInfo.t2)
	{
		return nullptr;
	}
	char* ptr = _cacheInfo.t1 + _cursor;

	PtrInfo info;
	info.ptr = ptr;
	info.begin = _cursor;
	info.size = size;

	_alloctedPtrs[_cursor] = info;

	memset(ptr, 0, size);
	_cursor += size;

	return ptr;
}
