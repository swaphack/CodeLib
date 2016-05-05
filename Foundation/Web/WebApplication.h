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

	class WebApplication : public sys::Object, public sys::IApplication
	{
	public:
		WebApplication(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		~WebApplication();
	public:
		static WebApplication* getInstance();

		virtual void init();
		virtual void update();
		virtual void dispose(); 

		void addRecvHandler(sys::Object* target, WEB_RECV_HANDLER handler);
		void removeRecvHandler(sys::Object* target, WEB_RECV_HANDLER handler);

		void postResponse(int id, HttpResponse* response);
	protected:
		void initNet();
		void disposeNet();
	private:
		void parserData(int id, sys::DataQueue& dataQueue);
		void onRecvHander(int id, HttpRequest* data);

		// 从接收的数据中创建http请求，并且删除已完成的数据
		HttpRequest* createHttpRequest(sys::DataQueue& dataQueue);
		// 将http反馈转成网络数据
		sys::NetData* createResponseData(HttpResponse* response);
	protected:
		int _port;
		std::string _ip;
		int _maxWaitCount;

		sys::Server* _server;

		std::vector<WebRecvHandler> _recvHandlers;

		static WebApplication* s_pWebApplication;
	};
}