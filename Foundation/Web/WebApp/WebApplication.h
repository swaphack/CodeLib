#pragma once

#include "system.h"
#include "macros.h"
#include "WebServer.h"
#include <map>

namespace web
{
	#define WAIT_LISTEN_COUNT 1024

	// web Ӧ��
	class WebApplication : public sys::Application
	{
	public:
		WebApplication(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~WebApplication();
	public:
		// ��ȡӦ��ʵ��
		static WebApplication* getInstance();
		// ��ȡ������
		WebServer* getServer();
		// ��ȡ��Դ
		sys::ResourceMgr* getResourceMgr();
	public:
		virtual void init();
		virtual void update();
		virtual void dispose(); 
	protected:
		// ��������
		void parseData(int id, sys::DataQueue& dataQueue);
	protected:
		// �˿�
		int _port;
		// ip
		std::string _ip;
		// ���ȴ���
		int _maxWaitCount;
		// ������
		WebServer* _server;
		// ��Դ����
		sys::ResourceMgr* _resource;
	};
}