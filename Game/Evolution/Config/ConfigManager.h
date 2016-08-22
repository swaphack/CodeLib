#pragma once

#include "IConfigLoader.h"

#include <map>
#include <string>

namespace nature
{
	// 配置管理
	class ConfigManager
	{
	private:
		ConfigManager();
		~ConfigManager();
	public:
		static ConfigManager* getInstance();
		static void purgeInstance();
	public:
		// 加载所有配置数据
		void loadAllDatas();
		// 添加加载接口
		void addLoader(const char* name, IConfigLoader* loader);
		// 移除加载接口
		void removeLoader(const char* name);
		// 移除所有加载接口
		void removeAllLoaders();
	private:
		static ConfigManager* s_pConfigManager;

		std::map<std::string, IConfigLoader*> _configLoaders;
	};
}