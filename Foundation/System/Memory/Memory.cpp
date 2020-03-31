#include "Memory.h"
#include "PtrCache.h"
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

PtrCache* Memory::alloct(const std::string& name, uint32_t size)
{
	ASSERT(name.empty() && size > 0);
	ASSERT(_caches.find(name) != _caches.end());

	char* ptr = (char*)malloc(size);
	ASSERT(ptr != nullptr);

	PtrCache* ptrCache = new PtrCache(ptr, size);
	ptrCache->setName(name);
	_caches[name] = ptrCache;

	return ptrCache;
}

void Memory::destory(const std::string& name)
{
	if (name.empty()) return;

	std::map<std::string, PtrCache*>::iterator iter = _caches.find(name);
	if (iter == _caches.end())
	{
		return;
	}
	PtrCache* pCache = iter->second;
	_caches.erase(iter);

	SAFE_DELETE(pCache);
}

void Memory::clear()
{
	std::map<std::string, PtrCache*>::iterator iter = _caches.begin();
	while (iter != _caches.end())
	{
		SAFE_DELETE(iter->second);
		iter++;
	}
}