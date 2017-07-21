#pragma once

#include "macros.h"

namespace script
{
	// 空
	class None : public Variable
	{
	public:
		None();
		virtual ~None();
	public:
		// 获取变量值
		void* getValue();
	public: // 覆盖
		// 克隆
		None* clone();
		// 分配新的内存，为变量赋值
		None* alloct(const char* name);
	};
}