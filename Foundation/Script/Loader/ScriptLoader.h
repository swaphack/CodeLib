#pragma once

#include "system.h"

namespace math
{
	class ScriptLoader
	{
	public:
		ScriptLoader();
		virtual ~ScriptLoader();
	public:
		// 加载文件
		bool loadFile(const char* filepath);
		// 加载字符串
		bool loadString(const char* value);
	};
}