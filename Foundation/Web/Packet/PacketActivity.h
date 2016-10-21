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
		// 收到http请求
		virtual void doGet(const char* buffer, int size);
		// 发送http反馈
		virtual void doPost(const PacketHeader& packet);
		// 广播
		virtual void doBroadCast(const PacketHeader& packet);
	private:
		void sendResponse(const char* sessionID, const char* bytes, int size);
		void sendBroadcast(const char* sessionID, const char* bytes, int size);
	private:
		std::string _sessionID;
	};
}