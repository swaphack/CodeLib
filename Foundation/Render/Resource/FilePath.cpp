#include "FilePath.h"

using namespace render;

FilePath::FilePath()
{

}

FilePath::~FilePath()
{
	_searchPaths.clear();
	_filePathCache.clear();
}


const char* FilePath::getFilePath(const char* filename)
{
	if (filename == nullptr)
	{
		return nullptr;
	}

	
	std::map<std::string, std::string>::iterator it = _filePathCache.find(filename);

	if (it != _filePathCache.end())
	{
		return it->second.c_str();
	}

	std::string fullpath;
	std::vector<std::string>::iterator it2 = _searchPaths.begin();
	while (it2 != _searchPaths.end())
	{
		fullpath = (*it2);
		fullpath += "/";
		fullpath += filename;
		if (sys::File::isFileExists(fullpath.c_str()))
		{
			_filePathCache[filename] = fullpath;
			return _filePathCache[filename].c_str();
		}
		it2++;
	}

	return nullptr;
}

bool FilePath::getFileData(const char* filename, std::string& data)
{
	data = "";
	if (filename == nullptr)
	{
		return false;
	}

	const char* fullpath = getFilePath(filename);
	if (fullpath == nullptr)
	{
		return false;
	}

	return sys::File::read(fullpath, data);
}

void FilePath::setSearchPath(std::vector<std::string> paths)
{
	_searchPaths.clear();

	std::vector<std::string>::iterator it = paths.begin();

	while (it != paths.end())
	{
		_searchPaths.push_back((*it));
		it++;
	}
}

const std::vector<std::string>& FilePath::getSearchPath()
{
	return _searchPaths;
}

void FilePath::clearAllFilepaths()
{
	_filePathCache.clear();
}

