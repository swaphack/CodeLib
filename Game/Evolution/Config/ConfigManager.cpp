#include "ConfigManager.h"

using namespace nature;

ConfigManager* nature::ConfigManager::s_pConfigManager = nullptr;


nature::ConfigManager::ConfigManager()
{

}

nature::ConfigManager::~ConfigManager()
{

}

ConfigManager* nature::ConfigManager::getInstance()
{
	if (s_pConfigManager)
	{
		s_pConfigManager = new ConfigManager();
	}

	return s_pConfigManager;
}

void nature::ConfigManager::purgeInstance()
{
	delete s_pConfigManager;
	s_pConfigManager = nullptr;
}

void nature::ConfigManager::loadAllDatas()
{
	std::map<std::string, IConfigLoader*>::iterator iter = _configLoaders.begin();

	while (iter != _configLoaders.end())
	{
		if (!iter->second->isLoaded())
		{
			iter->second->load();
		}
		iter++;
	}
}

void nature::ConfigManager::addLoader(const char* name, IConfigLoader* loader)
{
	if (name == nullptr || loader == nullptr)
	{
		return;
	}

	removeLoader(name);

	_configLoaders[name] = loader;
}

void nature::ConfigManager::removeLoader(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	std::map<std::string, IConfigLoader*>::iterator iter = _configLoaders.find(name);
	if (iter == _configLoaders.end())
	{
		return;
	}

	delete iter->second;

	_configLoaders.erase(iter);
}

void nature::ConfigManager::removeAllLoaders()
{

}
