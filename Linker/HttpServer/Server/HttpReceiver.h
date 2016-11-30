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
		// ����������
		virtual void doGetRequest(sys::HttpRequest* request);
	private:
		// ��ȡ�����ҳ��
		void getRequestUrl(sys::String& inString, std::string& outString);
		// ��ȡ�ϴ��Ĳ���
		// for url get param(?xx=xx)
		void handGetMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams);
		// for url get param(?xx=xx)
		void handPostMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams);
	};
}