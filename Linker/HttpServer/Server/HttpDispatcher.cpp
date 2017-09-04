#include "HttpDispatcher.h"

using namespace hs;


const char* IHttpAction::getUrl()
{
	return "";
}

void IHttpAction::setParams(const std::map<std::string, std::string>& params)
{
	m_pParams = (std::map<std::string, std::string>*)&params;
}

const char* IHttpAction::getParam(const std::string& key)
{
	if (m_pParams->find(key) == m_pParams->end())
	{
		return "";
	}

	return (*m_pParams)[key].c_str();
}


//////////////////////////////////////////////////////////////////////////

int HttpDispatcher::s_nIndex = 0;

HttpDispatcher::HttpDispatcher()
{
	m_nIndex = ++s_nIndex;
}

HttpDispatcher::~HttpDispatcher()
{

}

bool HttpDispatcher::hand(const char* url, const std::map<std::string, std::string>& params, sys::HttpResponse& response)
{
	for (std::vector<IHttpAction*>::iterator it = m_vecHttpAction.begin();
		it != m_vecHttpAction.end();
		it++)
	{
		if (strcmp((*it)->getUrl(), url) == 0)
		{
			(*it)->setParams(params);
			if ((*it)->hand(response))
			{
				return true;
			}
		}
	}
	return false;
}

void HttpDispatcher::registerHttpAction(IHttpAction* httpAction)
{
	if (httpAction == nullptr)
	{
		return;
	}
	m_vecHttpAction.push_back(httpAction);
}