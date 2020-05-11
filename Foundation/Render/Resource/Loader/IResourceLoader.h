#pragma once

#include <string>

namespace render
{
	// 资源加载接口
	class IResourceLoader
	{
	public:
		virtual ~IResourceLoader(){}
	public:
		virtual bool load(const std::string& filename) = 0;
	};
}