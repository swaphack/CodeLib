#include "ResourceMgr.h"

#include "LocalResource.h"
#include "RemoteResource.h"

using namespace sys;

ResourceMgr::ResourceMgr()
{
	this->init();
}

ResourceMgr::~ResourceMgr()
{
	this->disponse();
}
Resource* ResourceMgr::getResource(int type)
{
	std::map<int, IResource*>::iterator iter = _getResMethods.find(type);
	if (iter != _getResMethods.end())
	{
		return dynamic_cast<Resource*>(iter->second);
	}

	return nullptr;
}

void ResourceMgr::addMethod(int type, IResource* res)
{
	if (res == nullptr)
	{
		return;
	}

	removeMethod(type);

	_getResMethods[type] = res;
}

void ResourceMgr::removeMethod(int type)
{
	std::map<int, IResource*>::iterator iter = _getResMethods.find(type);
	if (iter == _getResMethods.end())
	{
		return;
	}

	SAFE_DELETE(iter->second);
	_getResMethods.erase(iter);
}

void ResourceMgr::init()
{
	this->disponse();
	_getResMethods[ERT_LOCAL] = new	LocalResource();
	_getResMethods[ERT_REMOTE] = new RemoteResource();
}

void ResourceMgr::disponse()
{
	std::map<int, IResource*>::iterator iter = _getResMethods.begin();
	while (iter != _getResMethods.end())
	{
		SAFE_DELETE(iter->second);
		iter++;
	}

	_getResMethods.clear();
}