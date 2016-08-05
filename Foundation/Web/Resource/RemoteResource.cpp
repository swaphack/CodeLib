#include "RemoteResource.h"

#include "system.h"

using namespace web;

RemoteResource::RemoteResource()
{
	this->setCacheEnable(true);
}

RemoteResource::~RemoteResource()
{

}

bool RemoteResource::loadFileData(const char* filename, std::string& data)
{
	data = "";

	if (filename == nullptr)
	{
		return false;
	}

	std::string fullpath = getFullPath(filename);
	if (fullpath.empty())
	{
		return false;
	}

	if (getCacheData(fullpath.c_str(), data))
	{
		return true;
	}

	

	getCache()->set(fullpath.c_str(), data.c_str());

	return true;
}

std::string RemoteResource::getFullPath(const char* filename)
{
	std::string fullpath = _url + filename;

	return fullpath;
}

bool RemoteResource::getCacheData(const char* fullpath, std::string& data)
{
	data = "";
	if (getCache() == nullptr)
	{
		return false;
	}

	if (!getCache()->get(fullpath, data))
	{
		return false;
	}

	return true;
}