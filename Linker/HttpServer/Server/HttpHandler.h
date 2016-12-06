#pragma once

#include "system.h"
#include "web.h"

#include <map>
#include <string>

namespace hs
{
	class HttpDispatcher;

	// http请求处理
	class HttpHandler
	{
	public:
		HttpHandler();
		~HttpHandler();
	public:
		static HttpHandler* getInstance();

		// 添加派发处理
		void addDispatcher(HttpDispatcher* dispatcher);
		// 移除派发处理
		void removeDispatcher(HttpDispatcher* dispatcher);
		// 移除所有派发处理
		void removeAllDispatchers();

		// 处理收到的请求
		void dispatch(sys::HttpRequest* request, sys::HttpResponse& response);
	protected:
		// 检查请求是否有误
		bool checkRequest(sys::HttpReqDocument* document, sys::HttpResponse& response);
		// 处理请求url及其参数
		bool handRequest(sys::HttpReqDocument* document, sys::HttpResponse& response);
	private:
		// 获取请求的页面
		void getRequestUrl(sys::String& inString, std::string& outString);
		// 获取上传的参数
		// for url get param(?xx=xx)
		void handGetMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams);
		// for url post param(xx=xx)
		void handPostMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams);
	private:
		typedef std::map<int, HttpDispatcher*> HttpDispatchers;
		HttpDispatchers m_mDispathers;
	};
}