#pragma once

#include <string>
#include <functional>

namespace sys
{
	class IResource
	{
	public:
		typedef std::function<void(const std::string&)> GetDataCallback;
	public:
		virtual ~IResource() {}
	public:
		// 加载文件数据
		virtual bool loadFileData(const std::string& filename, GetDataCallback handler) = 0;
	};
}