#pragma once

#include "text.h"

namespace nature
{
	/**
	*	配置加载
	*/
	class IConfigLoader
	{
	public:
		virtual ~IConfigLoader() {}
	public:
		// 加载
		virtual bool load() = 0;
		// 是否加载
		virtual bool isLoaded() = 0;
		// 获取配置路径
		virtual const char* getConfigPath() = 0;
	};
}