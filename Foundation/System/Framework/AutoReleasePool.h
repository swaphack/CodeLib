#pragma once

#include "../Base/Instance.h"

#include "Object.h"
#include <set>

namespace sys
{
	class Object;
	class AutoReleasePool;

#define G_AUTORELEASEPOOL sys::Instance<sys::AutoReleasePool>::getInstance()

	// 对象自动释放管理池
	// 引用计数的值为1时，会被释放
	class AutoReleasePool
	{
	public:
		AutoReleasePool();
		~AutoReleasePool();
	public:
		// 添加要自动释放的对象
		void addObject(Object* object);
		// 移除自动释放的对象
		void removeObject(Object* object);
		// 清除
		void clear();
		// 检查自动释放池
		void checkAutoRelease();
	protected:
		std::set<Object*> _objects;
	};

}