#pragma once

#include <string>

namespace sys
{
	// 资源加载接口
	class IImageLoader
	{
	public:
		virtual ~IImageLoader(){}
	public:
		virtual bool load(const std::string& filename) = 0;
	};
}