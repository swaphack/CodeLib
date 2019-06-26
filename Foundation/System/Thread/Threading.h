#pragma once

#include "Base/Types.h"

namespace sys
{
	// 当前线程
	class Threading
	{
	public:
		// 睡一段时间
		static void sleep(int32 milliseconds);
		// 睡到指定时间
		static void sleepUntil(int32 seconds);
	};
}