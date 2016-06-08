#include "Memory.h"
#include "system.h"

using namespace idea;

Memory::Memory()
{

}

Memory::~Memory()
{

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

Result* Memory::run(Event* e)
{
	if (e == nullptr || e->getMessage() == nullptr)
	{
		return nullptr;
	}

	Message* message = e->getMessage();

	ResultString* result = dynamic_cast<ResultString*>(message->getResult());
	if (result == nullptr)
	{
		return nullptr;
	}

	Storage* storage = pick(result->getValue());
	if (storage == nullptr)
	{
		return nullptr;
	}

	int length = storage->getLength();
	void* data = sys::StreamHelper::mallocStream(length);
	storage->read(data, length);

	return static_cast<Result*>(data);
}
