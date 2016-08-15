#include "StreamBase.h"
#include "../Base/import.h"

#include <cstdlib>
#include <cstring>

using namespace sys;

int allocCount = 0;

void addAlloc()
{
	allocCount++;
}

void subAlloc()
{
	allocCount--;
}

char* StreamHelper::mallocStream(void* data, ss_t size)
{
	ASSERT(data != nullptr && size > 0);

	char* newData = mallocStream(size);

	if (newData != nullptr)
	{
		memcpy(newData, data, size);
	}

	return newData;
}

char* StreamHelper::mallocStream(ss_t capacity, void* data, ss_t size)
{
	ASSERT(capacity > 0);

	char* newData = mallocStream(capacity);

	if (data != nullptr && size > 0)
	{
		memcpy(newData, data, size);
	}

	return newData;
}

char* StreamHelper::mallocStream(ss_t size)
{
	ASSERT(size > 0);

	char* newData = (char*)malloc(size);

	ASSERT(newData != nullptr);

	memset(newData, 0, size);

	addAlloc();

	return newData;
}

void StreamHelper::freeStream(void* data)
{
	SAFE_FREE(data);

	subAlloc();
}