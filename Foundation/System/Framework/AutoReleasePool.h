#pragma once

#include "Base/Instance.h"
#include <set>
#include <functional>

namespace sys
{
	class Object;

	// 对象自动释放管理池
	// 引用计数的值为1时，会被释放
	class AutoReleasePool
	{
	public:
		AutoReleasePool();
		virtual ~AutoReleasePool();
	public:
		// 添加要自动释放的对象
		void addObject(Object* object);
		// 移除自动释放的对象
		void removeObject(Object* object);
		// 清除
		void clear();
		// 检查自动释放池
		void checkAutoRelease();
	public:
		void startThread(const std::function<void()>& func);
		void endThread();
	protected:
		std::set<Object*> _objects;
		// 线程数
		uint32_t _threadCount = 0;
	};

	#define G_AUTORELEASEPOOL Instance<AutoReleasePool>::getInstance()
}