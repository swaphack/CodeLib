#pragma once

#include "web.h"
#include "system.h"

using namespace sys;
using namespace web;

namespace hs
{
	class HttpReceiver : public web::HttpActivity
	{
	protected:
		// 接收请求处理
		virtual void doGetRequest(sys::HttpRequest* request);
	private:
		// 获取请求的页面
		void getRequestUrl(sys::String& inString, std::string& outString);
		// 获取上传的参数
		// for url get param(?xx=xx)
		void handGetMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams);
		// for url get param(?xx=xx)
		void handPostMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams);
	};
}