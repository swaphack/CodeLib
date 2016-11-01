#pragma once

#include "system.h"

namespace web
{
	class IActivityListener
	{
	public:
		virtual ~IActivityListener() {}
	public:
		// 派发
		// 返回true,派发成功
		virtual bool onDispatch(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize) = 0;
	};
}