#pragma once

#include "system.h"
#include "Resource/import.h"
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

	// web 应用
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

		// 添加接受数据处理
		void addRecvHandler(sys::Object* target, WEB_RECV_HANDLER handler);
		// 移除接受数据处理
		void removeRecvHandler(sys::Object* target, WEB_RECV_HANDLER handler);
		// 反馈给客户端
		void postResponse(int id, HttpResponse* response);
		// 广播
		void postBroadcast(HttpResponse* response);
	protected:
		// 初始化网络
		void initNet();
		// 销毁网络
		void disposeNet();
	private:
		// 解析数据
		void parseData(int id, sys::DataQueue& dataQueue);
		// 接受请求处理
		void onRecvHander(int id, HttpRequest* data);

		// 从接收的数据中创建http请求，并且删除已完成的数据
		HttpRequest* createHttpRequest(sys::DataQueue& dataQueue);
		// 将http反馈转成网络数据
		sys::NetData* createResponseData(HttpResponse* response);
	protected:
		// 端口
		int _port;
		// ip
		std::string _ip;
		// 最大等待数
		int _maxWaitCount;
		// 服务器
		sys::Server* _server;
		// 接受处理
		std::vector<WebRecvHandler> _recvHandlers;
		// web服务器实例
		static WebApplication* s_pWebApplication;
	};
}