#include "HttpDispatcher.h"

using namespace hs;

int HttpDispatcher::s_nIndex = 0;

HttpDispatcher::HttpDispatcher()
{
	m_nIndex = ++s_nIndex;
}

HttpDispatcher::~HttpDispatcher()
{

}

bool HttpDispatcher::hand(const char* url, std::map<std::string, std::string> params, sys::HttpResponse& response)
{
	return false;
}
