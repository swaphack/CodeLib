#pragma once

#include "Cache/import.h"
#include <functional>

namespace sys
{
	class IResource
	{
	public:
		typedef std::function<void(std::string&)> GetDataCallback;
	public:
		virtual ~IResource() {}
	public:
		// 加载文件数据
		virtual bool loadFileData(const char* filename, GetDataCallback handler) = 0;
	};
}