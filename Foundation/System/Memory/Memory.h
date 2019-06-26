#pragma once

#include "Base/import.h"
#include "PtrCache.h"

namespace sys
{
	// 内存分配
	class Memory
	{
	private:
		Memory();
		~Memory();
	public:
		static Memory* getInstance();
		// 分配一个缓存
		PtrCache* alloct(const char* name, uint32 size);
		// 销毁一个缓存
		void destory(const char* name);
		// 清空
		void clear();
	private:
		// 已分配的缓存
		std::map<std::string, PtrCache*> _caches;
		// 唯一实例
		static Memory* s_pMemory;
	};
}