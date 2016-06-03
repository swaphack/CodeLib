#include "Memory.h"
#include "system.h"

using namespace idea;

Storage::Storage(int capacity)
:_capacity(0)
, _memory(nullptr)
, _length(0)
{
	this->setCapacity(capacity);
}

Storage::~Storage()
{
	sys::StreamHelper::freeStream(_memory);
}

void Storage::setCapacity(int capacity)
{
	if (_capacity >= capacity)
	{
		return;
	}
	_memory = sys::StreamHelper::mallocStream(capacity, _memory, _length);
	_capacity = capacity;
}

int Storage::getCapacity()
{
	return _capacity;
}

int Storage::getLength()
{
	return _length;
}

bool Storage::read(void* data, int& length)
{
	if (data == nullptr)
	{
		return false;
	}

	memcpy(data, _memory, _length);
	length = length;

	return true;
}

bool Storage::write(void* data, int length)
{
	if (length > _capacity)
	{
		return false;
	}

	memcpy(_memory, data, length);

	return true;
}