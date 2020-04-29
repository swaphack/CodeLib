#include "Memory.h"
#include "MemoryData.h"
#include "Base/macros.h"
#include <cstdlib>

using namespace sys;

Memory* Memory::s_pMemory = nullptr;


Memory::Memory()
{

}

Memory::~Memory()
{
	this->clear();

	SAFE_DELETE(s_pMemory);
}

Memory* Memory::getInstance()
{
	if (s_pMemory == nullptr)
	{
		s_pMemory = new Memory();
	}

	return s_pMemory;
}

MemoryData* Memory::alloct(const std::string& name, uint32_t size)
{
	ASSERT(name.empty() && size > 0);
	ASSERT(_caches.find(name) != _caches.end());

	MemoryData* ptrCache = new MemoryData(size);
	_caches[name] = ptrCache;

	return ptrCache;
}

void Memory::destory(const std::string& name)
{
	if (name.empty()) return;

	auto iter = _caches.find(name);
	if (iter == _caches.end())
	{
		return;
	}
	MemoryData* pCache = iter->second;
	_caches.erase(iter);
	SAFE_DELETE(pCache);
}

void Memory::clear()
{
	for (auto item : _caches)
	{
		SAFE_DELETE(item.second);
	}
	_caches.clear();
}