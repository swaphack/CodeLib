#pragma once

#include "Base/Types.h"

namespace sys
{
	// ��ǰ�߳�
	class Threading
	{
	public:
		// ˯һ��ʱ��
		static void sleep(int32 milliseconds);
		// ˯��ָ��ʱ��
		static void sleepUntil(int32 seconds);
	};
}