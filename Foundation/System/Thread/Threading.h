#pragma once

#include <cstdint>

namespace sys
{
	// ��ǰ�߳�
	class Threading
	{
	public:
		// ˯һ��ʱ��
		static void sleep(int32_t milliseconds);
		// ˯��ָ��ʱ��
		static void sleepUntil(int32_t seconds);
	};
}