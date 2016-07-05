#pragma once

#include "macros.h"
#include "Session.h"
#include "WebApplication.h"

namespace web
{
	// http应用服务器
	class HttpApplication : public WebApplication
	{
	public:
		HttpApplication(const char* ip, int port, int maxWaitCount = WAIT_LISTEN_COUNT);
		virtual ~HttpApplication();
	public:
		// 获取http实例
		static HttpApplication* getInstance();
		// 添加接受数据处理
		void addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// 移除接受数据处理
		void removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// 反馈给客户端
		void postResponse(HttpResponse* response);
		// 广播
		void postBroadcast(HttpResponse* response);
	protected:
		// 客户端信息
		Session* getSession();
		// 接受请求处理
		void onRecvHander(HttpRequest* data);
	private:
		// 从接收的数据中创建http请求，并且删除已完成的数据
		HttpRequest* createHttpRequest(int id, sys::DataQueue& dataQueue);
		// 将http反馈转成网络数据
		sys::NetData* createResponseData(HttpResponse* response);
		// 解析数据
		virtual void onParseData(int id, sys::DataQueue& dataQueue);
	private:
		// 客户端信息
		Session* _session;
		// http接受处理
		std::vector<HttpRecvHandler> _recvHandlers;
	};

	#define G_HTTPAPPLICATION HttpApplication::getInstance()
}