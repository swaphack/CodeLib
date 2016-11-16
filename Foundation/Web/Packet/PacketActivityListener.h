#pragma once

#include "system.h"

#include "PacketRecvHandler.h"

#include "../Listener/IActivityListener.h"

namespace web
{
	// ���ļ���
	class PacketActivityListener : public IActivityListener
	{
	public:
		PacketActivityListener();
		virtual ~PacketActivityListener();
	public:
		// ��ӽ������ݴ���
		void addRecvHandler(sys::Object* target, PACKET_RECV_HANDLER handler);
		// �Ƴ��������ݴ���
		void removeRecvHandler(sys::Object* target, PACKET_RECV_HANDLER handler);

		virtual bool onDispatch(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize);
	protected:
		// ����������
		void onRecvHander(const char* sessionID, const char* buffer, int size);
		// �ӽ��յ������д����������󣬲���ɾ������ɵ�����
		const char* createRequest(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize);
	private:
		// http���ܴ���
		std::vector<PacketRecvHandler> _recvHandlers;
	};
}