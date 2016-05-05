#include "StringPool.h"

using namespace search;


std::string* StringPool::getString( const char* str )
{
	if (str == nullptr)
	{
		return nullptr;
	} 

	uint key = sys::Hash::getBKDRHash((char*)str);
	if (_strings.find(key) == _strings.end())
	{
		_strings[key] = std::string(str);
	}
	
	return &_strings[key];
}
