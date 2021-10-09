#include "Directory.h"
#include <cstdio>
#include <direct.h>
#include <cstdlib>
#include <io.h>
#include "Type/String.h"

#include <sys/types.h>
#include <stdio.h>

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

void sys::Directory::getAllFiles(const std::string& dir, std::vector<std::string>& files, const std::string& filter)
{
	if (access(dir.c_str(), 0) == -1)
	{
		return;
	}
	std::string dirNew = dir;
	dirNew += "/" + filter;

	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(dirNew.c_str(), &findData);
	if (handle == -1)        // 检查是否成功
		return;

	do
	{
		if (findData.attrib & _A_SUBDIR)
		{
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;

			// 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
			dirNew = dir;
			dirNew += "/";
			dirNew += findData.name;

			getAllFiles(dirNew, files);
		}
		else
		{
			files.push_back(dir + "/" + findData.name);
		}
	} while (_findnext(handle, &findData) == 0);

	_findclose(handle);    // 关闭搜索句柄

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

	String fullpath = dirname;
	fullpath = fullpath.replace("\\", "/");

	std::vector<std::string> eachDir;
	fullpath.split("/", eachDir);

	std::string fullDir;
	for (size_t i = 0; i < eachDir.size(); i++)
	{
		fullDir += eachDir[i] + "/";
		mkdir(fullDir.c_str());
	}

	return 0;
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

std::string sys::Directory::getDirName(const std::string& fullpath, bool containsFormat)
{
	if (fullpath.empty()) return fullpath;

	sys::String path = fullpath;
	path = path.replace("\\", "/");

	if (path[path.getSize() - 1] == '/')
		path = path.subString(0, path.getSize() - 1);

	int index = path.findLastOf("/");
	if (index == -1) return fullpath;

	std::string name = path.subString(index + 1, fullpath.size() - index - 1).getString();

	if (!containsFormat)
	{
		index = name.find_last_of('.');
		if (index != -1) name = fullpath.substr(0, index);
	}
	return name;
}




sys::Directory::Directory()
{

}

sys::Directory::~Directory()
{

}

void sys::Directory::setRoot(const std::string root)
{
	_root = root;

	this->load();
}

const std::string& sys::Directory::getRoot() const
{
	return _root;
}

const std::vector<std::string>& sys::Directory::getFiles() const
{
	return _files;
}

const std::vector<std::string>& sys::Directory::getSubDirs() const
{
	return _sudDirs;
}

void sys::Directory::load()
{
	_files.clear();
	_sudDirs.clear();

	if (access(_root.c_str(), 0) == -1)
	{
		return;
	}
	std::string dirNew = _root;
	dirNew += "/*.*";

	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(dirNew.c_str(), &findData);
	if (handle == -1)        // 检查是否成功
		return;

	do
	{
		if (findData.attrib & _A_SUBDIR)
		{
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;

			_sudDirs.push_back(findData.name);
		}
		else
		{
			_files.push_back(findData.name);
		}
	} while (_findnext(handle, &findData) == 0);

	_findclose(handle);    // 关闭搜索句柄
}
