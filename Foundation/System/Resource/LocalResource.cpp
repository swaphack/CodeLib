#include "LocalResource.h"

#include "../Base/import.h"

using namespace sys;

LocalResource::LocalResource()
{
	this->setCacheEnable(true);
}

LocalResource::~LocalResource()
{

}

bool LocalResource::loadFileData(const char* filename, std::string& data)
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

	if (!File::read(fullpath.c_str(), data))
	{
		return false;
	}

	getCache()->set(fullpath, data);

	return true;
}

std::string LocalResource::getFullPath(const char* filename)
{
	std::string fullpath;
	if (File::isFileExists(filename))
	{
		fullpath = filename;
	}

	if (fullpath.empty())
	{
		fullpath = _url + filename;

		if (!File::isFileExists(fullpath.c_str()))
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