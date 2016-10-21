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
		// �յ�http����
		virtual void doGet(const char* buffer, int size);
		// ����http����
		virtual void doPost(const PacketHeader& packet);
		// �㲥
		virtual void doBroadCast(const PacketHeader& packet);
	private:
		void sendResponse(const char* sessionID, const char* bytes, int size);
		void sendBroadcast(const char* sessionID, const char* bytes, int size);
	private:
		std::string _sessionID;
	};
}