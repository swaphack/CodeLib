#pragma once

#include "web.h" 
#include "system.h"

namespace gw
{

	class GateWay : public web::WebApplication
	{
	public:
		GateWay(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~GateWay();
	public:
		void initSelf();
		// ����һ�����ӵ���Ϸ�������Ŀͻ���
		bool createGameServerListener(const char* ip, int port);
		// ����һ�����ӵ� ��վ�������Ŀͻ���
		bool createHttpServerListener(const char* ip, int port);
		// ��ȡ������Ϸ�������Ŀͻ���id
		int getGameServerListenerID();
		// ��ȡ���� ��վ�������Ŀͻ���id
		int getHttpServerListenerID();
	private:
		// ��Ϸ������socket����id
		int _gameServerListenerID;
		// ��վ������socket����id;
		int _httpServerListenerID;

	};

#define sGateWay static_cast<GateWay*>(web::WebApplication::getInstance())
}