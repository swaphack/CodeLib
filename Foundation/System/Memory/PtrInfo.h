#pragma once

#include "Base/import.h"

namespace sys
{
	struct PtrInfo
	{
		// 指针
		char* ptr;
		// 在Cache位置
		uint32 begin;
		// 分配大小
		uint32 size;

		PtrInfo()
		{
			ptr = nullptr;
			begin = 0;
			size = 0;
		}
	};
}