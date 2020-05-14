#include "MemoryPointer.h"
#include "Memory.h"

using namespace sys;

MemoryPointer::MemoryPointer(char* ptr, size_t size)
{
	_value = ptr;
	_size = size;
}

MemoryPointer::~MemoryPointer()
{
	this->clear();
}

void MemoryPointer::resetCursor()
{
	_cursor = 0;
	this->clear();
}

MemoryPointer* MemoryPointer::alloctPtr(size_t size)
{
	if (size + _cursor >= _size)
	{
		return nullptr;
	}
	char* ptr = _value + _cursor;
	memset(ptr, 0, size);
	_cursor += size;

	MemoryPointer* mp = new MemoryPointer(ptr, size);

	_alloctedPtrs[_cursor] = mp;
	return mp;
}

MemoryPointer::MemoryPointer(const MemoryData& data)
{
	_value = data.getPtr(0);
	_size = data.getLength() * data.getTypeSize();
}

char* MemoryPointer::getPtr()
{
	return _value;
}

size_t MemoryPointer::getSize()
{
	return _size;
}

void MemoryPointer::clear()
{
	for (auto item : _alloctedPtrs)
	{
		SAFE_DELETE(item.second);
	}

	_alloctedPtrs.clear();
}
