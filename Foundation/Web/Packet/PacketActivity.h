#pragma once

#include "system.h"

namespace web
{
	struct PacketHeader;

	class PacketActivity : public sys::Object
	{
	public:
		PacketActivity();
		virtual ~PacketActivity();
	public:
		void onReceiveRequest(const char* sessionID, const char* buffer, int size);
	protected:
		// 收到报文请求
		virtual void doGet(const char* buffer, int size);
		// 发送反馈
		virtual void doPost(const PacketHeader& packet);
		// 发送给指定目标
		virtual void doPost(int destID, const PacketHeader& packet);
		// 广播
		virtual void doBroadCast(const PacketHeader& packet);
	protected:
		std::string _sessionID;
	};
}