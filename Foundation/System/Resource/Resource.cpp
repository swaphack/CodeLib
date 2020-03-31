#include "Resource.h"
#include "Cache/CacheGroup.h"

using namespace sys;

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

bool Resource::loadFileData(const std::string& filename, GetDataCallback handler)
{
	return false;
}

void Resource::setUrl(const std::string& url)
{
	_url = url;
}

std::string Resource::getUrl()
{
	return	_url;
}

void Resource::setCacheEnable(bool status)
{
	if (_bCacheEnabled == status)
	{
		return;
	}

	_bCacheEnabled = status;

	if (getName().empty())
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