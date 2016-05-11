#include "StreamBase.h"
#include "../Base/import.h"

#include <cstdlib>
#include <cstring>

using namespace sys;

int allocCount = 0;

void addAlloc()
{
	allocCount++;
	LOG("add malloc count %d\n", allocCount);
}

void subAlloc()
{
	allocCount--;
	LOG("sub malloc count %d\n", allocCount);
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

	char* newData = mallocStream(size);

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


//////////////////////////////////////////////////////////////////////////

StreamBase::StreamBase()
:_data(nullptr)
,_length(0)
{

}

StreamBase::~StreamBase()
{
	this->freeStream();
}

void StreamBase::setData(const char* data, ss_t size)
{
	ASSERT(data != nullptr && size > 0);

	this->freeStream();

	_data = StreamHelper::mallocStream((void*)data, size);
	_length = size;
}

const char* StreamBase::getData() const
{
	return _data;
}

int StreamBase::getLength() const
{
	return _length;
}

void StreamBase::freeStream()
{
	StreamHelper::freeStream(_data);
	_length = 0;
}

void StreamBase::setLength( int length )
{
	_length = length;
}

//////////////////////////////////////////////////////////////////////////
StreamBaseRef::StreamBaseRef()
:_data(nullptr)
, _length(0)
{

}

StreamBaseRef::~StreamBaseRef()
{
	this->freeStream();
}

void StreamBaseRef::setData(const char* data, ss_t size)
{
	ASSERT(data != nullptr && size > 0);

	this->freeStream();

	this->_data = (char*)data;
	this->_length = size;

}

const char* StreamBaseRef::getData() const
{
	return _data;
}

int StreamBaseRef::getLength() const
{
	return _length;
}

void StreamBaseRef::freeStream()
{
	StreamHelper::freeStream(_data);
	_length = 0;
}

void StreamBaseRef::setLength(int length)
{
	_length = length;
}