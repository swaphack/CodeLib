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
		// ����һ�����ӵ�Զ�˵Ŀͻ���
		bool createGameServerListener(const char* ip, int port);
		// ��ȡ����Զ�̵Ŀͻ���id
		int getGameServerListenerID();
	private:
		int _gameServerListenerID;
	};

#define sGateWay static_cast<GateWay*>(web::WebApplication::getInstance())
}