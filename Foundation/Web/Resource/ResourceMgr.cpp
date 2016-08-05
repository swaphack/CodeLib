#include "ResourceMgr.h"

#include "system.h"
#include "LocalResource.h"
#include "RemoteResource.h"

using namespace web;

ResourceMgr::ResourceMgr()
{
	_resType = ERT_LOCAL;

	this->init();
}

ResourceMgr::~ResourceMgr()
{
	this->disponse();
}

void ResourceMgr::setResourceType(ResourceType type)
{
	_resType = type;
}

ResourceType ResourceMgr::getResourceType()
{
	return _resType;
}

void ResourceMgr::setUrl(const char* url)
{
	if (url == nullptr)
	{
		return;
	}
	Resource* resource = getResource();
	if (resource == nullptr)
	{
		return;
	}

	resource->setUrl(url);
}

Resource* ResourceMgr::getResource()
{
	std::map<ResourceType, IResource*>::iterator iter = _resources.find(_resType);
	if (iter != _resources.end())
	{
		return dynamic_cast<Resource*>(iter->second);
	}

	return nullptr;
}

void ResourceMgr::init()
{
	this->disponse();
	_resources[ERT_LOCAL] = new	LocalResource();
	_resources[ERT_REMOTE] = new RemoteResource();
}

void ResourceMgr::disponse()
{
	std::map<ResourceType, IResource*>::iterator iter = _resources.begin();
	while (iter != _resources.end())
	{
		SAFE_DELETE(iter->second);
		iter++;
	}

	_resources.clear();
}
