#pragma once

#include "system.h"
#include "web.h"

#include <map>
#include <string>

namespace hs
{
	class HttpDispatcher;

	// http������
	class HttpHandler
	{
	public:
		HttpHandler();
		~HttpHandler();
	public:
		static HttpHandler* getInstance();

		// ����ɷ�����
		void addDispatcher(HttpDispatcher* dispatcher);
		// �Ƴ��ɷ�����
		void removeDispatcher(HttpDispatcher* dispatcher);
		// �Ƴ������ɷ�����
		void removeAllDispatchers();

		// �����յ�������
		void dispatch(sys::HttpRequest* request, sys::HttpResponse& response);
	protected:
		// ��������Ƿ�����
		bool checkRequest(sys::HttpReqDocument* document, sys::HttpResponse& response);
		// ��������url�������
		bool handRequest(sys::HttpReqDocument* document, sys::HttpResponse& response);
	private:
		// ��ȡ�����ҳ��
		void getRequestUrl(sys::String& inString, std::string& outString);
		// ��ȡ�ϴ��Ĳ���
		// for url get param(?xx=xx)
		void handGetMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams);
		// for url post param(xx=xx)
		void handPostMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams);
	private:
		typedef std::map<int, HttpDispatcher*> HttpDispatchers;
		HttpDispatchers m_mDispathers;
	};
}