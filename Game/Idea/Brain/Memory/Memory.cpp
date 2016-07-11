#include "Memory.h"
#include "system.h"

using namespace idea;

static Memory* s_pMemory = nullptr;
//////////////////////////////////////////////////////////////////////////
Memory::Memory()
{
	ASSERT(s_pMemory == nullptr);
	s_pMemory = this;
}

Memory::~Memory()
{
	SAFE_DELETE(s_pMemory);
}

Memory* Memory::getInstance()
{
	return s_pMemory;
}

Storage* Memory::pick(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, Storage*>::iterator iter = _storages.find(name);
	if (iter != _storages.end())
	{
		return iter->second;
	}

	return nullptr;
}

Storage* Memory::alloc(const char* name, int capacity)
{
	if (name == nullptr || capacity < 0)
	{
		return nullptr;
	}

	std::map<std::string, Storage*>::iterator iter = _storages.find(name);
	if (iter != _storages.end())
	{
		return iter->second;
	}

	_storages[name] = new Storage(capacity);

	return _storages[name];
}

Storage* Memory::alloc(const char* name, Result* cls)
{
	int size = strlen(cls->getStringValue());
	Storage* storage = this->alloc(name, size);
	storage->write((char*)cls->getStringValue(), size);
	return storage;
}

Result* Memory::run(Event* e)
{
	if (e == nullptr || e->getMessage() == nullptr)
	{
		return nullptr;
	}

	Result* message = e->getMessage();
	if (message == nullptr)
	{
		return nullptr;
	}

	// ÄÚ´æ¿éÖµ
	Storage* storage = pick(message->getStringValue());
	if (storage == nullptr)
	{
		return nullptr;
	}

	return static_cast<Result*>(storage->getMemory());
}
