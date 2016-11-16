#pragma once

#include "system.h"

#include "HttpRecvHandler.h"

#include "../Listener/IActivityListener.h"

namespace web
{
	// http监听
	class HttpActivityListener : public IActivityListener
	{
	public:
		HttpActivityListener();
		virtual ~HttpActivityListener();
	public:
		// 添加接受数据处理
		void addRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);
		// 移除接受数据处理
		void removeRecvHandler(sys::Object* target, HTTP_RECV_HANDLER handler);

		virtual bool onDispatch(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize);
	protected:
		// 接受请求处理
		void onRecvHander(sys::HttpRequest* data);
		// 从接收的数据中创建http请求，并且删除已完成的数据
		sys::HttpRequest* createRequest(const char* sessionID, sys::DataQueue& dataQueue, int& packetSize);
		// 将http反馈转成网络数据
		sys::NetData* createResponseData(sys::HttpResponse* response);
	private:
		// http接受处理
		std::vector<HttpRecvHandler> _recvHandlers;
		sys::HttpReqDocument* _httpReqDoc;
	};
}