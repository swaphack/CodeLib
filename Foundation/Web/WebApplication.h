#pragma once

#include "system.h"
#include "Command/import.h"

#include <map>

namespace web
{
	#define WAIT_LISTEN_COUNT 1024

	typedef void (sys::Object::*WEB_RECV_HANDLER)(int id, HttpRequest* data);

	struct WebRecvHandler
	{
		sys::Object* target;
		WEB_RECV_HANDLER hander;

		WebRecvHandler():target(nullptr), hander(nullptr){}

		void hand(int id, HttpRequest* data)
		{
			if (!empty())
				(target->*hander)(id, data);
		}

		bool equals(sys::Object* target, WEB_RECV_HANDLER handler)
		{
			return this->target == target && this->hander == handler;
		}

		bool empty() 
		{ 
			return target == nullptr || hander == nullptr;
		}

		void clean() 
		{ 
			target = nullptr; 
			hander = nullptr; 
		}
	};

	class WebApplication : public sys::Application
	{
	public:
		WebApplication(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~WebApplication();
	public:
		static WebApplication* getInstance();

		virtual void init();
		virtual void update();
		virtual void dispose(); 

		void addRecvHandler(sys::Object* target, WEB_RECV_HANDLER handler);
		void removeRecvHandler(sys::Object* target, WEB_RECV_HANDLER handler);

		void postResponse(int id, HttpResponse* response);
		void postBroadcast(HttpResponse* response);
	protected:
		void initNet();
		void disposeNet();
	private:
		void parserData(int id, sys::DataQueue& dataQueue);
		void onRecvHander(int id, HttpRequest* data);

		// �ӽ��յ������д���http���󣬲���ɾ������ɵ�����
		HttpRequest* createHttpRequest(sys::DataQueue& dataQueue);
		// ��http����ת����������
		sys::NetData* createResponseData(HttpResponse* response);
	protected:
		// �˿�
		int _port;
		// ip
		std::string _ip;
		// ���ȴ���
		int _maxWaitCount;
		// ������
		sys::Server* _server;
		// ���ܴ���
		std::vector<WebRecvHandler> _recvHandlers;
		// web������ʵ��
		static WebApplication* s_pWebApplication;
	};
}