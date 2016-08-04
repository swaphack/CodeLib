#include "Resource.h"

#include "system.h"
#include "text.h"
#include <string>

using namespace web;


Resource::Resource()
{
	this->init();
}

Resource::~Resource()
{
	this->dispose();
}

void Resource::init()
{
	_url = "";
	_bCacheEnabled = false;
	_cache = nullptr;
}

void Resource::save()
{

}

void Resource::dispose()
{
	SAFE_DELETE(_cache);
}

CacheGroup* Resource::getCache()
{
	return _cache;
}

void Resource::setUrl(const char* url)
{
	_url = url;
}

const char* Resource::getUrl()
{
	return	_url.c_str();
}

void Resource::setCacheEnable(bool status)
{
	if (_bCacheEnabled == status)
	{
		return;
	}

	_bCacheEnabled = status;

	if (strcmp(getName(), "") == 0)
	{
		return;
	}

	if (_bCacheEnabled && _cache == nullptr)
	{
		_cache = CacheGroup::create(getName());
	}
	else
	{
		SAFE_DELETE(_cache);
	}
}

bool Resource::isCacheEnable()
{
	return _bCacheEnabled;
}

void Resource::clearCache()
{
	if (_cache)
	{
		_cache->clear();
	}
}
