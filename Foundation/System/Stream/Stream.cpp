#pragma once

#include "Stream.h"

using namespace sys;

Stream::Stream(IStreamBase* baseStream)
:_cursor(0)
,_capacity(0)
, _baseStream(baseStream)
{

}

Stream::~Stream()
{

}

void Stream::setData(const char* data, ss_t size)
{
	ASSERT(data != nullptr && getStream() != nullptr && size > 0);

	getStream()->setData(data, size);
	
	_capacity = size;
}

ss_t Stream::getCapacity() const
{
	return _capacity;
}

ss_t Stream::getLength() const
{
	if (_baseStream == nullptr)
	{
		return 0;
	}

	return _baseStream->getLength();
}

ss_t Stream::getCursor() const
{
	return _cursor;
}

const char* Stream::getData() const
{
	if (_baseStream == nullptr)
	{
		return nullptr;
	}

	return _baseStream->getData();
}

void Stream::setStream(IStreamBase* baseStream, bool disponable)
{
	if (disponable == true)
	{
		SAFE_DELETE(_baseStream);
	}

	_baseStream = baseStream;
}

void Stream::setCursor( ss_t pos )
{
	_cursor = pos;
}

IStreamBase* Stream::getStream() const
{
	return _baseStream;
}

bool Stream::isOutOfLength()
{
	return _cursor > getLength() || _cursor < 0;
}

bool Stream::isOutOfCapacity()
{
	return _cursor > _capacity;
}

char* Stream::getPtr()
{
	if (getStream() == nullptr)
	{
		return nullptr;
	}

	return (char*)getStream()->getData() + _cursor;
}

void Stream::setCapacity( ss_t capacity )
{
	_capacity = capacity;
}

void Stream::setLength(ss_t length)
{
	if (getStream() == nullptr)
	{
		return;
	}

	getStream()->setLength(length);
}