#pragma once

#include "system.h"
#include "web.h"

#include <string>
#include <map>

namespace hs
{
	// http 派发器
	class HttpDispatcher
	{
	public:
		HttpDispatcher();
		virtual ~HttpDispatcher();
	public:
		inline int getIndex() { return m_nIndex; }
		// 处理收到的请求
		virtual bool hand(const char* url, std::map<std::string, std::string> params, sys::HttpResponse& response);
	protected:
		static int s_nIndex;
		// 请求url
		int m_nIndex;
		// 请求参数
		std::map<std::string, std::string> m_mParams;
	};
}