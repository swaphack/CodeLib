#pragma once

#include "IConfigLoader.h"

#include <map>
#include <string>

namespace nature
{
	class ConfigManager
	{
	private:
		ConfigManager();
		~ConfigManager();
	public:
		static ConfigManager* getInstance();
		static void purgeInstance();
	public:
		void loadAllDatas();

		void addLoader(const char* name, IConfigLoader* loader);
		void removeLoader(const char* name. bool bClean);
		IConfigLoader* getLoader(const char* name);
		void removeAllLoaders();
	private:
		std::map<std::string, IConfigLoader*> _configLoaders;
	};
}