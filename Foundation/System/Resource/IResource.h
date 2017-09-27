#pragma once

#include "Cache/import.h"

namespace sys
{
	class IResource
	{
	public:
		virtual ~IResource() {}
	public:
		// 加载文件数据
		virtual bool loadFileData(const char* filename, std::string& data) = 0;
	};
}