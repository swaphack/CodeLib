#include "ConfigLoader.h"

using namespace nature;


ConfigLoader::ConfigLoader()
:_bLoaded(false)
,_configPath("")
{

}

ConfigLoader::~ConfigLoader()
{

}

bool ConfigLoader::load()
{
	return false;
}

bool ConfigLoader::isLoaded()
{
	return _bLoaded;
}

const char* ConfigLoader::getConfigPath()
{
	return _configPath.c_str();
}

void ConfigLoader::setLoadStatus(bool status)
{
	_bLoaded = status;
}

void ConfigLoader::setConfigPath(const char* path)
{
	if (path)
	{
		_configPath = path;
	}
}