#pragma once

#include "Resource.h"

namespace sys
{
	// 本地数据
	class LocalResource : public Resource
	{
	public:
		LocalResource();
		virtual ~LocalResource();
	public:
		// 名称
		virtual const char* getName() { return "LOCAL"; }
		// 加载文件
		virtual bool loadFileData(const char* filename, GetDataCallback handler);
	protected:
		// 获取完整路径
		std::string getFullPath(const char* filename);
		// 获取数据
		bool getCacheData(const char* fullpath, std::string& data);
	};
}