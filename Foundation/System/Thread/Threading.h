#pragma once

namespace sys
{
	// ��ǰ�߳�
	class Threading
	{
	public:
		// ˯һ��ʱ��
		static void sleep(int milliseconds);
		// ˯��ָ��ʱ��
		static void sleepUntil(int seconds);
	};
}