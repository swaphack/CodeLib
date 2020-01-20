#include "Directory.h"
#include <cstdio>
#include <direct.h>

using namespace sys;

void Directory::getDirectory(const std::string& fullpath, std::string& dir)
{
	std::string strFullpath = fullpath;

	std::string::size_type pos1 = strFullpath.find_last_of("\\");
	std::string::size_type pos2 = strFullpath.find_last_of("/");

	if (pos1 == std::string::npos && pos2 == std::string::npos)
	{
		strFullpath = "";
		dir = strFullpath;
	}
	else if (pos1 == std::string::npos)
	{
		dir = strFullpath.substr(0, pos2);
	}
	else if (pos2 == std::string::npos)
	{
		dir = strFullpath.substr(0, pos1 + 1);
	}
}


int32_t Directory::createFile(const std::string& filename)
{
	if (filename.empty())
	{
		return -1;
	}

	FILE* fptr = nullptr;
	fptr = fopen(filename.c_str(), "wb");
	if (fptr != nullptr)
	{
		fclose(fptr);
		return 0;
	}
	return -1;
}

int32_t Directory::deleteFile(const std::string& filename)
{
	if (filename.empty())
	{
		return -1;
	}

	return unlink(filename.c_str());
}

int32_t Directory::renameFile(const std::string& oldFilename, const std::string& newFilename)
{
	if (oldFilename.empty() || newFilename.empty())
	{
		return -1;
	}

	return rename(oldFilename.c_str(), newFilename.c_str());
}

int32_t Directory::createDirectory(const std::string& dirname)
{
	if (dirname.empty())
	{
		return -1;
	}

	return mkdir(dirname.c_str());
}

int32_t Directory::deleteDirectory(const std::string& dirname)
{
	if (dirname.empty())
	{
		return -1;
	}

	return rmdir(dirname.c_str());
}

int32_t Directory::renameDirectory(const std::string& oldDirname, const std::string& newDirname)
{
	if (oldDirname.empty() || newDirname.empty())
	{
		return -1;
	}

	return rename(oldDirname.c_str(), newDirname.c_str());
}

void Directory::getCurrentDirectory(std::string& dir)
{
	char dirname[FILENAME_MAX];
	getcwd(dirname, FILENAME_MAX);

	dir = dirname;
}

int32_t Directory::setCurrentDirectory(const std::string& name)
{
	if (name.empty())
	{
		return -1;
	}

	return chdir(name.c_str());
}
