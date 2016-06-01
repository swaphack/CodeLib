#pragma once

#include <map>
#include <string>

namespace idea
{
	// 存储单元
	class Storage
	{
	public:
		Storage(int capacity);
		virtual ~Storage();
	public:
		int getCapacity();
	protected:
	private:
		// 内存分配长度
		int _capacity;
		// 内存数据
		void* _memory;
	};

	// 记忆
	class Memory
	{
	public:
		Memory();
		~Memory();
	public:
		// 获取一个已存在的内存
		Storage* pick(const char* name);
		// 分配一个新的内存
		Storage* alloc(const char* name, int capacity);
	protected:
	private:
		std::map<std::string, Storage*> _storages;
	};
}