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
		// 匹配地址
		virtual const char* getUrl();
		// 获取参数
		void setParams(const std::map<std::string, std::string>& params);
		const char* getParam(const std::string& key);

		virtual bool hand(sys::HttpResponse& response) = 0;
	private:
		std::map<std::string, std::string>* m_pParams;
	};

	// http 派发器
	class HttpDispatcher
	{
	public:
		HttpDispatcher();
		virtual ~HttpDispatcher();
	public:
		inline int getIndex() { return m_nIndex; }
		// 处理收到的请求
		bool hand(const char* url, const std::map<std::string, std::string>& params, sys::HttpResponse& response);

		void registerHttpAction(IHttpAction* httpAction);
	protected:
		static int s_nIndex;
		// 请求url
		int m_nIndex;
		// 请求参数
		std::map<std::string, std::string> m_mParams;
		std::vector<IHttpAction*> m_vecHttpAction;
	};
}