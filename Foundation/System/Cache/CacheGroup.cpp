#include "CacheGroup.h"

#include "../Stream/import.h"

using namespace sys;


CacheGroup::CacheGroup()
{

}

CacheGroup::~CacheGroup()
{

}

CacheGroup* CacheGroup::create(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	CacheGroup* pCacheGroup = new CacheGroup();
	pCacheGroup->setName(name);
	pCacheGroup->setInControl(true);
	return pCacheGroup;
}

void CacheGroup::set(const std::string& name, const std::string& value)
{
	if (name.empty())
	{
		return;
	}

	_values[name].setData(value.c_str(), value.size());
}

bool CacheGroup::get(const std::string& name, std::string& value)
{
	if (name.empty())
	{
		return false;
	}

	std::map<std::string, StreamBase>::const_iterator iter = _values.find(name);
	if (iter != _values.end())
	{
		value.clear();
		value.append(iter->second.getData(), iter->second.getLength());
		return true;
	}

	return false;
}

void CacheGroup::clear()
{
	_values.clear();
}
