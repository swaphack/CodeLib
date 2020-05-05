#pragma once

#include "system.h"

namespace web
{
	class IActivityListener
	{
	public:
		virtual ~IActivityListener() {}
	public:
		// �ɷ�
		// ����true,�ɷ��ɹ�
		virtual bool onDispatch(const std::string& sessionID, sys::DataQueue& dataQueue, int& packetSize) = 0;
	};
}