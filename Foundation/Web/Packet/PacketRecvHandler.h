#pragma once

#include "system.h"

#include <map>

namespace web
{
	typedef void (sys::Object::*PACKET_RECV_HANDLER)(const char* sessionID, const char* buffer, int size);

	typedef std::pair<sys::Object*, PACKET_RECV_HANDLER> PacketRecvHandler;
}