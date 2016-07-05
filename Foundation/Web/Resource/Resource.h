#pragma once

#include "system.h"
#include "text.h"

namespace web
{
	class Resource
	{
	public:
		// 加载文件
		const char* loadFile(const char* filename, ulong& size);
		// 加载xml文件
		tinyxml2::XMLDocument* loadXMLFile(const char* filename);
		// 加载json文件
		Json::Reader* loadJsonFile(const char* filename);
	protected:
	private:
	};
}