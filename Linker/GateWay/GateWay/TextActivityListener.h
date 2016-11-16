#pragma once

#include "web.h"

namespace gw
{
	class TextActivityListener : public web::IActivityListener
	{
	public:
		TextActivityListener();
		virtual ~TextActivityListener();
	public:
		virtual bool onDispatch(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize);
	};
}