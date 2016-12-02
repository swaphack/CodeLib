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
		// �����յ�������
		virtual bool hand(const char* url, std::map<std::string, std::string> params, sys::HttpResponse& response);
	protected:
		// ����url
		std::string m_strUrl;
		// �������
		std::map<std::string, std::string> m_mParams;
	};
}