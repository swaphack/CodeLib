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
		virtual std::string getName() { return "LOCAL"; }
		// 加载文件
		virtual bool loadFileData(const std::string& filename, GetDataCallback handler);
	protected:
		// 获取完整路径
		std::string getFullPath(const std::string& filename);
		// 获取数据
		bool getCacheData(const std::string& fullpath, std::string& data);
	};
}