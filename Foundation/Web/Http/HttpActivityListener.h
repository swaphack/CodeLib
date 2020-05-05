#pragma once

#include "system.h"

#include "HttpRecvHandler.h"

#include "Listener/IActivityListener.h"

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
		void addRecvHandler(sys::Object* target, HTTP_RECV_REQUEST_HANDLER handler);
		// 移除接受数据处理
		void removeRecvHandler(sys::Object* target, HTTP_RECV_REQUEST_HANDLER handler);

		// 添加接受数据处理
		void addRecvHandler(sys::Object* target, HTTP_RECV_RESPONE_HANDLER handler);
		// 移除接受数据处理
		void removeRecvHandler(sys::Object* target, HTTP_RECV_RESPONE_HANDLER handler);

		virtual bool onDispatch(const std::string& sessionID, sys::DataQueue& dataQueue, int& packetSize);
	protected:
		// 接受请求处理
		void onRecvHander(sys::HttpRequest* data);
		// 接受请求处理
		void onRecvHander(sys::HttpResponse* data);
		// 从接收的数据中创建http请求，并且删除已完成的数据
		sys::HttpRequest* createRequest(const std::string& sessionID, sys::DataQueue& dataQueue, int& packetSize);
		// 从接收的数据中创建http请求，并且删除已完成的数据
		sys::HttpResponse* createResponse(const std::string& sessionID, sys::DataQueue& dataQueue, int& packetSize);
	private:
		// 接受http请求处理
		std::vector<HttpRecvRequestHandler> _recvRequestHandlers;
		// 接受http反馈处理
		std::vector<HttpRecvResponseHandler> _recvResponseHandlers;
		// http请求解析文档
		sys::HttpReqDocument* _httpReqDoc;
		// http反馈解析文档
		sys::HttpRespDocument* _httpRespDoc;
	};
}