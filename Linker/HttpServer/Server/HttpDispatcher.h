#pragma once

#include "system.h"
#include "web.h"

#include <string>
#include <map>

namespace hs
{
	class HttpDispatcher
	{
	public:
		HttpDispatcher();
		virtual ~HttpDispatcher();
	public:
		// 处理收到的请求
		virtual bool hand(const char* url, std::map<std::string, std::string> params, sys::HttpResponse& response);
	protected:
		// 请求url
		std::string m_strUrl;
		// 请求参数
		std::map<std::string, std::string> m_mParams;
	};
}