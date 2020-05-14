#pragma once

#include <string>
namespace sys
{
	// 加载多媒体接口
	class IMediaLoader
	{
	public:
		virtual ~IMediaLoader() {}
	public:
		virtual bool load(const std::string& filepath) = 0;
	};
}