#include "MemoryPointer.h"
#include "Memory.h"

using namespace sys;

MemoryPointer::MemoryPointer(int8_t* ptr, uint32_t size)
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

MemoryPointer* MemoryPointer::alloctPtr(uint32_t size)
{
	if (size + _cursor >= _size)
	{
		return nullptr;
	}
	int8_t* ptr = _value + _cursor;
	memset(ptr, 0, size);
	_cursor += size;

	MemoryPointer* mp = new MemoryPointer(ptr, size);

	_alloctedPtrs[_cursor] = mp;
	return mp;
}

sys::MemoryPointer::MemoryPointer(const MemoryData& data)
{
	_value = data.getPtr(0);
	_size = data.getLength() * data.getUnitSize();
}

int8_t* sys::MemoryPointer::getPtr()
{
	return _value;
}

uint32_t sys::MemoryPointer::getSize()
{
	return _size;
}

void sys::MemoryPointer::clear()
{
	for (auto item : _alloctedPtrs)
	{
		SAFE_DELETE(item.second);
	}

	_alloctedPtrs.clear();
}
