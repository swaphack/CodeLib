#pragma once

#include "macros.h"

namespace sys
{
	// 辅助工具
	class StreamHelper
	{
	public:
		// 创建一个大小等于制定分配空间的内存
		static char* mallocStream(size_t size);
		// 创建一个大小等于目标流的内存，并赋值
		static char* mallocStream(void* data, size_t size);
		// 创建一个大小等于指定分配空间的内存，并复制数据
		static char* mallocStream(size_t capacity, void* data, size_t size);
		// 释放流
		static void freeStream(void* data);
	};
}