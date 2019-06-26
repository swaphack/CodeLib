#include "LocalResource.h"

#include "Base/import.h"

using namespace sys;

LocalResource::LocalResource()
{
	this->setCacheEnable(true);
}

LocalResource::~LocalResource()
{

}

bool LocalResource::loadFileData(const char* filename, GetDataCallback handler)
{
	if (filename == nullptr)
	{
		return false;
	}

	std::string fullpath = getFullPath(filename);
	if (fullpath.empty())
	{
		return false;
	}

	std::string data;
	if (getCacheData(fullpath.c_str(), data))
	{
		if (handler)
		{
			handler(data);
		}
		return true;
	}

	if (!File::read(fullpath.c_str(), data))
	{
		return false;
	}

	getCache()->set(fullpath, data);
	if (handler)
	{
		handler(data);
	}

	return true;
}

std::string LocalResource::getFullPath(const char* filename)
{
	std::string fullpath;
	if (File::exists(filename))
	{
		fullpath = filename;
	}

	if (fullpath.empty())
	{
		fullpath = _url + filename;

		if (!File::exists(fullpath.c_str()))
		{
			fullpath = "";
		}
	}

	return fullpath;
}

bool LocalResource::getCacheData(const char* fullpath, std::string& data)
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