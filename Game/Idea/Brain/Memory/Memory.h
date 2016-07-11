#pragma once
#include "../macros.h"
#include "Storage.h"
#include <map>
#include <string>

namespace idea
{
	// 记忆
	class Memory : public IWorker
	{
	public:
		Memory();
		virtual ~Memory();
	public:
		static Memory* getInstance();

		// 获取一个已存在的内存
		Storage* pick(const char* name);

		// 分配一个新的内存
		Storage* alloc(const char* name, int capacity);
		// T 是 Result
		Storage* alloc(const char* name, Result* cls);

		// 记忆查找
		virtual Result* run(Event* e);
	protected:
		std::map<std::string, Storage*> _storages;
	};
}