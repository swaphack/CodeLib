#include "StringPool.h"

using namespace search;


std::string* StringPool::getString( const char* str )
{
	if (str == nullptr)
	{
		return nullptr;
	} 

	uint32_t key = getHash((char*)str);
	if (_strings.find(key) == _strings.end())
	{
		_strings[key] = std::string(str);
	}
	
	return &_strings[key];
}

uint32_t StringPool::getHash(const char* str)
{
	return sys::Hash::getBKDRHash((char*)str);
}
