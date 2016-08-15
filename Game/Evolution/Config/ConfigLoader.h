#pragma once

#include "IConfigLoader.h"

#include <string>

namespace nature
{
	class ConfigLoader : public IConfigLoader
	{
	public:
		ConfigLoader();
		virtual ~ConfigLoader();
	public:
		// 加载
		virtual bool load();
		// 是否加载
		virtual bool isLoaded();
		// 获取配置路径
		virtual const char* getConfigPath();
	protected:
		void setLoadStatus(bool status);
		void setConfigPath(const char* path);
	private:
		// 是否加载完毕
		bool _bLoaded;
		// 配置路径
		std::string _configPath;
	};

	/**
	* 元素配置表
	*/
	class ElementConfig : public ConfigLoader
	{
	public:
		ElementConfig();
		virtual ~ElementConfig();
	public:
		virtual bool load();
	};
}