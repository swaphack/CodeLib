#pragma once

#include "../Cache/import.h"

namespace web
{
	class IResource
	{
	public:
		virtual ~IResource() {}
	public:
		// 初始化
		virtual void init() = 0;
		// 保存
		virtual void save() = 0;
		// 销毁
		virtual void dispose() = 0;
		// 名称
		virtual const char* getName() = 0;
		// 缓存
		virtual CacheGroup* getCache() = 0;
	};
}