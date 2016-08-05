#pragma once

#include "macros.h"
#include "Session.h"

namespace web
{
	// http应用服务器
	class HttpServer
	{
	public:
		HttpServer(sys::Server* server);
		virtual ~HttpServer();
	public:
		// 添加接受数据处理
		void addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// 移除接受数据处理
		void removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// 反馈给客户端
		void postResponse(HttpResponse* response);
		// 广播
		void postBroadcast(HttpResponse* response);
		// 更新
		void update();
		// 解析数据
		void onParseData(int id, sys::DataQueue& dataQueue);
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
	private:
		// 服务器
		sys::Server* _server;
		// 客户端信息
		Session* _session;
		// http接受处理
		std::vector<HttpRecvHandler> _recvHandlers;
	};
}