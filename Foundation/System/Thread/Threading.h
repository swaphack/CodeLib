#pragma once

namespace sys
{
	// 当前线程
	class Threading
	{
	public:
		// 睡一段时间
		static void sleep(int milliseconds);
		// 睡到指定时间
		static void sleepUntil(int seconds);
	};
}