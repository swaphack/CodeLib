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
		// �յ���������
		virtual void doGet(const char* buffer, int size);
		// ���ͷ���
		virtual void doPost(const PacketHeader& packet);
		// ���͸�ָ��Ŀ��
		virtual void doPost(int destID, const PacketHeader& packet);
		// �㲥
		virtual void doBroadCast(const PacketHeader& packet);
	protected:
		std::string _sessionID;
	};
}