#include "ResourceMgr.h"
#include "LocalResource.h"
#include "RemoteResource.h"
#include "Base/macros.h"

using namespace sys;

ResourceMgr::ResourceMgr()
{
	this->init();
}

ResourceMgr::~ResourceMgr()
{
	this->dispose();
}
Resource* ResourceMgr::getResource(ResourceType type)
{
	std::map<ResourceType, IResource*>::iterator iter = _getResMethods.find(type);
	if (iter != _getResMethods.end())
	{
		return dynamic_cast<Resource*>(iter->second);
	}

	return nullptr;
}

void ResourceMgr::addMethod(ResourceType type, IResource* res)
{
	if (res == nullptr)
	{
		return;
	}

	removeMethod(type);

	_getResMethods[type] = res;
}

void ResourceMgr::removeMethod(ResourceType type)
{
	std::map<ResourceType, IResource*>::iterator iter = _getResMethods.find(type);
	if (iter == _getResMethods.end())
	{
		return;
	}

	SAFE_DELETE(iter->second);
	_getResMethods.erase(iter);
}

void ResourceMgr::init()
{
	this->dispose();

	_getResMethods[ResourceType::LOCAL] = new	LocalResource();
	_getResMethods[ResourceType::REMOTE] = new RemoteResource();
}

void ResourceMgr::dispose()
{
	std::map<ResourceType, IResource*>::iterator iter = _getResMethods.begin();
	while (iter != _getResMethods.end())
	{
		SAFE_DELETE(iter->second);
		iter++;
	}

	_getResMethods.clear();
}