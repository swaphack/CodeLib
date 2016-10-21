#pragma once

#include "macros.h"
#include "Session.h"
#include "system.h"

#include "../Http/import.h"
#include "../Packet/import.h"

namespace web
{
	// WebӦ�÷�����
	class WebServer
	{
	public:
		WebServer(sys::Server* server);
		virtual ~WebServer();
	public:
		// �������ͻ���
		void postResponse(const char* sessionID, sys::NetData* data);
		// �㲥
		void postBroadcast(sys::NetData* data);
		// ����
		void update();
		// ��������
		void onParseData(int id, sys::DataQueue& dataQueue);
		// http ����
		HttpActivityListener* getHttpListener();
		// ���ļ���
		PacketActivityListener* getPacketListener();
	protected:
		// �ͻ�����Ϣ
		Sessions* getSession();
	private:
		// ������
		sys::Server* _server;
		// �ͻ�����Ϣ
		Sessions* _session;
		// Http����
		HttpActivityListener* _httpListener;
		// ���ļ���
		PacketActivityListener* _packetListener;
	};
}