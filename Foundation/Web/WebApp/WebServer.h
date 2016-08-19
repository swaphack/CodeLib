#pragma once

#include "macros.h"
#include "Session.h"
#include "system.h"

namespace web
{
	// Web应用服务器
	class WebServer
	{
	public:
		WebServer(sys::Server* server);
		virtual ~WebServer();
	public:
		// 添加接受数据处理
		void addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// 移除接受数据处理
		void removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// 反馈给客户端
		void postResponse(sys::HttpResponse* response);
		// 广播
		void postBroadcast(sys::HttpResponse* response);
		// 更新
		void update();
		// 解析数据
		void onParseData(int id, sys::DataQueue& dataQueue);
	protected:
		// 客户端信息
		Session* getSession();
		// 接受请求处理
		void onRecvHander(sys::HttpRequest* data);
	private:
		// 从接收的数据中创建http请求，并且删除已完成的数据
		sys::HttpRequest* createHttpRequest(int id, sys::DataQueue& dataQueue);
		// 将http反馈转成网络数据
		sys::NetData* createResponseData(sys::HttpResponse* response);
	private:
		// 服务器
		sys::Server* _server;
		// 客户端信息
		Session* _session;
		// http接受处理
		std::vector<HttpRecvHandler> _recvHandlers;
	};
}