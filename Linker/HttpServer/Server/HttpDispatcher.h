#pragma once

#include "system.h"
#include "web.h"

#include <string>
#include <map>

namespace hs
{
	class IHttpAction
	{
	public:
		virtual ~IHttpAction() {}
	public:
		// ƥ���ַ
		virtual const char* getUrl();
		// ��ȡ����
		void setParams(const std::map<std::string, std::string>& params);
		const char* getParam(const std::string& key);

		virtual bool hand(sys::HttpResponse& response) = 0;
	private:
		std::map<std::string, std::string>* m_pParams;
	};

	// http �ɷ���
	class HttpDispatcher
	{
	public:
		HttpDispatcher();
		virtual ~HttpDispatcher();
	public:
		inline int getIndex() { return m_nIndex; }
		// �����յ�������
		bool hand(const char* url, const std::map<std::string, std::string>& params, sys::HttpResponse& response);

		void registerHttpAction(IHttpAction* httpAction);
	protected:
		static int s_nIndex;
		// ����url
		int m_nIndex;
		// �������
		std::map<std::string, std::string> m_mParams;
		std::vector<IHttpAction*> m_vecHttpAction;
	};
}