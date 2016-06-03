#pragma once
#include "../AI/ai.h"
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
		// 设置分配长度
		void setCapacity(int capacity);
		// 获取分配长度
		int getCapacity();
		// 获取使用的长度
		int getLength();
		// 读取信息
		bool read(void* data, int& length);
		// 写入信息
		bool write(void* data, int length);
	protected:
		// 内存分配长度
		int _capacity;
		// 内存数据
		void* _memory;
		// 已使用内存长度
		int _length;
	};

	// 记忆
	class Memory : public IWorker
	{
	public:
		Memory();
		virtual ~Memory();
	public:
		// 获取一个已存在的内存
		Storage* pick(const char* name);
		// 分配一个新的内存
		Storage* alloc(const char* name, int capacity);

		virtual Result* run(Event* e);
	protected:
		std::map<std::string, Storage*> _storages;
	};
}