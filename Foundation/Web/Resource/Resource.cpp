#include "Resource.h"

#include "system.h"
#include "text.h"
#include <string>
using namespace web;


Resource::Resource()
{
	_resPath;
	sys::Directory::getCurrentDirectory(_resPath);
}

Resource::~Resource()
{

}

void Resource::setResourcePath(const char* resPath)
{
	_resPath = resPath;
}

const char* Resource::getResourcePath()
{
	return	_resPath.c_str();
}

std::string Resource::loadFile(const char* filename)
{
	if (filename == nullptr)
	{
		return "";
	}

	std::string fullpath;
	if (sys::File::isFileExists(filename))
	{
		fullpath = filename;
	}

	if (fullpath.empty())
	{
		fullpath = _resPath + filename;
	}
	
	if (!sys::File::isFileExists(fullpath.c_str()))
	{
		fullpath = "";
	}

	if (fullpath.empty())
	{
		return "";
	}

	long size = 0;
	char* data = sys::File::read(fullpath.c_str(), size);
	if (data == nullptr)
	{
		return nullptr;
	}

	std::string fileData = std::string(data, size);

	sys::StreamHelper::freeStream(data);

	return fileData;
}
