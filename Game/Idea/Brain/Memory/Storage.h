#pragma once

namespace idea
{
	// 存储单元
	class Storage
	{
	public:
		Storage(int capacity);
		virtual ~Storage();
	public:
		// 获取分配长度
		int getCapacity();
		// 设置数据
		void setMemory(void* memory, int capacity);
		// 获取数据
		void* getMemory();
		// 读取信息
		bool read(void* data, int& length);
		// 写入信息
		bool write(void* data, int length);
	protected:
		// 内存分配长度
		int _capacity;
		// 内存数据
		void* _memory;
	};
}