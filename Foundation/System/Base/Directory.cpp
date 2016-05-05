#include "Directory.h"

using namespace sys;


void Directory::getDir(const char* filepath, std::string& dir)
{
	std::string fullpath = filepath;

	std::string::size_type pos1 = fullpath.find_last_of("\\");
	std::string::size_type pos2 = fullpath.find_last_of("/");

	if (pos1 == std::string::npos && pos2 == std::string::npos)
	{
		fullpath = "";
		dir = fullpath;
	}
	else if (pos1 == std::string::npos)
	{
		dir = fullpath.substr(0, pos2);
	}
	else if (pos2 == std::string::npos)
	{
		dir = fullpath.substr(0, pos1 + 1);
	}
}
