#pragma once

#include <cstdint>

namespace sys
{
	// 当前线程
	class Threading
	{
	public:
		// 睡一段时间
		static void sleep(int32_t milliseconds);
		// 睡到指定时间
		static void sleepUntil(int32_t seconds);
	};
}