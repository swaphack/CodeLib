#include "HttpHandler.h"
#include "HttpDispatcher.h"

using namespace hs;


HttpHandler::HttpHandler()
{

}

HttpHandler::~HttpHandler()
{
	removeAllDispatchers();
}

HttpHandler* HttpHandler::getInstance()
{
	static HttpHandler* s_HttpHandler = nullptr;
	if (s_HttpHandler == nullptr)
	{
		s_HttpHandler = new HttpHandler();
	}

	return s_HttpHandler;
}

void HttpHandler::addDispatcher(HttpDispatcher* dispatcher)
{
	if (dispatcher == nullptr)
	{
		return;
	}

	HttpDispatchers::iterator iter = m_mDispathers.find(dispatcher->getIndex());

	if (iter != m_mDispathers.end())
	{
		PRINT("Had Exists Dispatcher, Delete Old");
		delete iter->second;
		m_mDispathers.erase(iter);
	}

	m_mDispathers[dispatcher->getIndex()] = dispatcher;
}

void HttpHandler::removeDispatcher(HttpDispatcher* dispatcher)
{
	if (dispatcher == nullptr)
	{
		return;
	}

	HttpDispatchers::iterator iter = m_mDispathers.find(dispatcher->getIndex());

	if (iter != m_mDispathers.end())
	{
		delete iter->second;
		m_mDispathers.erase(iter);
	}
}

void HttpHandler::removeAllDispatchers()
{
	HttpDispatchers::iterator iter = m_mDispathers.begin();

	while (iter != m_mDispathers.end())
	{
		delete iter->second;
		iter++;
	}

	m_mDispathers.clear();
}

void HttpHandler::dispatch(sys::HttpRequest* request, sys::HttpResponse& response)
{
	sys::HttpReqDocument* pDocument = request->getDocument();

	bool bOK = true;

	if (bOK) bOK = checkRequest(pDocument, response);
	if (bOK) bOK = handRequest(pDocument, response);
	
	if (!bOK)
	{
		response.getDocument()->setHttpVersion("HTTP/1.1");
		response.getDocument()->setResponseCode("400");
		response.getDocument()->setDescribe("ERROR");
		response.getDocument()->writeContentString("ERROR");
	}
}

bool HttpHandler::checkRequest(sys::HttpReqDocument* pDocument, sys::HttpResponse& response)
{
	sys::String method = pDocument->getMethod();
	sys::String params = pDocument->getUrl();
	sys::String body = pDocument->getBody();

	if (!method.compare(sys::HttpRequestConstant::HTTP_REQ_GET)
		&& !method.compare(sys::HttpRequestConstant::HTTP_REQ_POST))
	{// 非get和post请求，直接退出
		return false;
	}

	return true;
}

bool HttpHandler::handRequest(sys::HttpReqDocument* pDocument, sys::HttpResponse& response)
{
	std::string url;

	sys::String method = pDocument->getMethod();
	sys::String params = pDocument->getUrl();
	sys::String body = pDocument->getBody();


	// 获取请求的页面
	std::map<std::string, std::string> reqParams;
	getRequestUrl(params, url);

	if (method.compare(sys::HttpRequestConstant::HTTP_REQ_GET))
	{// get
		// 获取上传的参数
		handGetMethodParams(params, reqParams);
	}
	else if (method.compare(sys::HttpRequestConstant::HTTP_REQ_POST))
	{// post
		handPostMethodParams(body, reqParams);
	}
	
	if (reqParams.empty())
	{// 不带参数的请求
		response.getDocument()->setHttpVersion("HTTP/1.1");
		response.getDocument()->setResponseCode("200");
		response.getDocument()->setDescribe("OK");
		response.getDocument()->writeContentFile(url.c_str());

		return true;
	}
	else
	{// 带参数的请求
		bool bFind = false;
		HttpDispatchers::iterator iter = m_mDispathers.begin();
		while (iter != m_mDispathers.end())
		{
			bFind = iter->second->hand(url.c_str(), reqParams, response);
			if (bFind)
			{
				break;
			}
			iter++;
		}

		return bFind;
	}
}

void HttpHandler::getRequestUrl(sys::String& inString, std::string& outString)
{
	int index = inString.findFirstOf('?');
	sys::String url = "";
	if (index == -1)
		url = inString;
	else
		url = inString.subString(0, index);

	if (url.compare("/"))
		outString = "/index.html";
	else
		outString = url.getString();
}

void HttpHandler::handGetMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams)
{
	int index = inString.findFirstOf('?');
	sys::String params = "";
	if (index == -1)
		return;

	index += 1;
	params = inString.subString(index, inString.getSize() - index);

	handPostMethodParams(params, outParams);
}

void HttpHandler::handPostMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams)
{
	std::vector<sys::String> vecParams;
	inString.split('&', vecParams);

	std::vector<sys::String> kv;
	std::vector<sys::String>::iterator iter = vecParams.begin();
	while (iter != vecParams.end())
	{
		kv.clear();
		(*iter).split('=', kv);
		if (kv.size() == 2)
		{
			outParams[kv[0].getString()] = kv[1].getString();
		}
		iter++;
	}
}