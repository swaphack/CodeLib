#pragma once

#include "system.h"
#include "web.h"

#include <string>
#include <map>

namespace hs
{
	// http �ɷ���
	class HttpDispatcher
	{
	public:
		HttpDispatcher();
		virtual ~HttpDispatcher();
	public:
		inline int getIndex() { return m_nIndex; }
		// �����յ�������
		virtual bool hand(const char* url, std::map<std::string, std::string> params, sys::HttpResponse& response);
	protected:
		static int s_nIndex;
		// ����url
		int m_nIndex;
		// �������
		std::map<std::string, std::string> m_mParams;
	};
}