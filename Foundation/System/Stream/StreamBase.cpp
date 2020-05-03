#include "StreamBase.h"
#include "Base/import.h"
#include "StreamHelper.h"

using namespace sys;

StreamBase::StreamBase()
{

}

StreamBase::~StreamBase()
{
	this->freeStream();
}

void StreamBase::setData(const char* data, size_t size)
{
	_memoryData.init(size, data);
}

const char* StreamBase::getData() const
{
	return (const char*)_memoryData.getValue();
}

size_t StreamBase::getLength() const
{
	return _memoryData.getLength();
}

void StreamBase::freeStream()
{
	_memoryData.clear();
}

void StreamBase::setLength(size_t length)
{
	_memoryData.resize(length);
}

//////////////////////////////////////////////////////////////////////////
StreamBaseRef::StreamBaseRef()
{

}

StreamBaseRef::~StreamBaseRef()
{
	this->freeStream();
}

void StreamBaseRef::setData(const char* data, size_t size)
{
	ASSERT(data != nullptr && size > 0);

	this->freeStream();

	this->_data = (char*)data;
	this->_length = size;
}

const char* StreamBaseRef::getData() const
{
	return (const char*)_data;
}

size_t StreamBaseRef::getLength() const
{
	return _length;
}

void StreamBaseRef::freeStream()
{
	StreamHelper::freeStream(_data);
	_data = nullptr;
	_length = 0;
}

void StreamBaseRef::setLength(size_t length)
{
	_length = length;
}