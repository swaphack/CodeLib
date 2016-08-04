#include "ResourceMgr.h"
#include "system.h"

using namespace web;

ResourceMgr::ResourceMgr()
{
	_localRes = new LocalResource();
	//_remoteRes = new RemoteResource();
}

ResourceMgr::~ResourceMgr()
{
	SAFE_DELETE(_localRes);
	SAFE_DELETE(_remoteRes);
}

LocalResource* ResourceMgr::getLocal()
{
	return _localRes;
}

void ResourceMgr::setLocalUrl(const char* url)
{
	if (url == nullptr)
	{
		return;
	}

	getLocal()->setUrl(url);
}

RemoteResource* ResourceMgr::getRemote()
{
	return _remoteRes;
}