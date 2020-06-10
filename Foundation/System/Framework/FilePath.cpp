#include "FilePath.h"

#include "IO/File.h"
#include "Base/macros.h"

using namespace sys;

FilePath::FilePath()
{

}

FilePath::~FilePath()
{
	_searchPaths.clear();
	_filePathCache.clear();
}


std::string FilePath::getFilePath(const std::string& filename, bool bIngoreEmpty)
{
	if (filename.empty())
	{
		return "";
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
		if (fullpath.empty() && !bIngoreEmpty)
		{
			it2++;
			continue;
		}
		if (!fullpath.empty())
		{
			fullpath += "/";
		}
		fullpath += filename;
		if (File::exists(fullpath))
		{
			_filePathCache[filename] = fullpath;
			return _filePathCache[filename];
		}
		it2++;
	}

	return "";
}

bool FilePath::getFileData(const std::string& filename, std::string& data)
{
	data = "";
	if (filename.empty())
	{
		return false;
	}

	const std::string& fullpath = getFilePath(filename);
	if (fullpath.empty())
	{
		PRINT("Error : Load Data From File [%s]\n", filename.c_str());
		return false;
	}

	return File::read(fullpath, data);
}

void FilePath::setSearchPath(const std::vector<std::string>& paths)
{
	_searchPaths.clear();

	auto it = paths.begin();

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

