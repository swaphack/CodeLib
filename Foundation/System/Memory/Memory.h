#pragma once

#include "../Base/import.h"
#include "PtrCache.h"

#include <string>
#include <map>

namespace sys
{
	// 内存分配
	class Memory
	{
	private:
		Memory();
	public:
		~Memory();
	public:
		static Memory* getInstance();
		// 分配一个缓存
		PtrCache* alloct(const char* name, uint size);
		// 销毁一个缓存
		void destory(const char* name);
	protected:
		void dispose();
	private:
		// 已分配的缓存
		std::map<std::string, PtrCache*> _caches;
		// 唯一实例
		static Memory* s_pMemory;
	};
}