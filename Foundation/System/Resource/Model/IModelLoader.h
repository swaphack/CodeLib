#pragma once

#include <string>

namespace sys
{
	// 资源加载接口
	class IModelLoader
	{
	public:
		virtual ~IModelLoader(){}
	public:
		virtual bool load(const std::string& filename) = 0;
	};
}