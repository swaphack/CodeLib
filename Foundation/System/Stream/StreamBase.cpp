#include "StreamBase.h"
#include "../Base/import.h"

using namespace sys;

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
	_data = nullptr;
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
	_data = nullptr;
	_length = 0;
}

void StreamBaseRef::setLength(int length)
{
	_length = length;
}