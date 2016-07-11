#include "Storage.h"
#include "system.h"

using namespace idea;

Storage::Storage(int capacity)
{
	ASSERT(capacity > 0);
	_memory = sys::StreamHelper::mallocStream(capacity);
	_capacity = capacity;
}

Storage::~Storage()
{
	sys::StreamHelper::freeStream(_memory);
}

int Storage::getCapacity()
{
	return _capacity;
}

void Storage::setMemory(void* memory, int capacity)
{
	sys::StreamHelper::freeStream(_memory);

	sys::StreamHelper::mallocStream(memory, capacity);
}

void* Storage::getMemory()
{
	return _memory;
}

bool Storage::read(void* data, int& length)
{
	if (data == nullptr)
	{
		return false;
	}

	length = _capacity;

	memcpy(data, _memory, length);

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