#pragma once

#include <string>

namespace web
{
	// 站点资源管理
	class Resource
	{
	public:
		Resource();
		~Resource();
	public:
		// 设置资源路径
		void setResourcePath(const char* resPath);
		// 获取资源路径
		const char* getResourcePath();
		// 加载文件
		std::string loadFile(const char* filename);
	private:
		// 资源位置
		std::string _resPath;
	};
}