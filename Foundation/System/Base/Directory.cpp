#include "Directory.h"
#include <cstdio>
#include <direct.h>

using namespace sys;

void Directory::getDirectory(const char* fullpath, std::string& dir)
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


int Directory::createFile(const char* filename)
{
	FILE* fptr;
	fptr = fopen(filename, "wb");
	if (fptr)
	{
		fclose(fptr);
		return 0;
	}

	return -1;
}

int Directory::deleteFile(const char* filename)
{
	if (filename == nullptr)
	{
		return -1;
	}

	return unlink(filename);
}

int Directory::renameFile(const char* oldFilename, const char* newFilename)
{
	if (oldFilename == nullptr || newFilename == nullptr)
	{
		return -1;
	}

	return rename(oldFilename, newFilename);
}

int Directory::createDirectory(const char* dirname)
{
	if (dirname == nullptr)
	{
		return -1;
	}

	return mkdir(dirname);
}

int Directory::deleteDirectory(const char* dirname)
{
	if (dirname == nullptr)
	{
		return -1;
	}

	return rmdir(dirname);
}

int Directory::renameDirectory(const char* oldDirname, const char* newDirname)
{
	if (oldDirname == nullptr || newDirname == nullptr)
	{
		return -1;
	}

	return rename(oldDirname, newDirname);
}

void Directory::getCurrentDirectory(std::string& dir)
{
	char dirname[FILENAME_MAX];
	getcwd(dirname, FILENAME_MAX);

	dir = dirname;
}

int Directory::setCurrentDirectory(const char* name)
{
	if (name == nullptr)
	{
		return -1;
	}

	return chdir(name);
}
