#include "HttpReceiver.h"

using namespace hs;

#define G_RESOURCE WebApplication::getInstance()->getResourceMgr()->getResource(ERT_LOCAL)

void HttpReceiver::doGetRequest(sys::HttpRequest* request)
{
	std::string url;

	sys::HttpReqDocument* pDocument = request->getDocument();
	sys::String method = pDocument->getMethod();
	sys::String params = pDocument->getUrl();
	sys::String body = pDocument->getBody();

	// 获取请求的页面
	std::map<std::string, std::string> reqParams;
	getRequestUrl(params, url);

	if (method.compare(HttpRequestConstant::HTTP_REQ_GET))
	{// get
		// 获取上传的参数
		handGetMethodParams(params, reqParams);
	}
	else if (method.compare(HttpRequestConstant::HTTP_REQ_POST))
	{// post
		handPostMethodParams(body, reqParams);
	}

	HttpResponse response;
	response.getDocument()->setHeader("ClientID", pDocument->getHeader("ClientID"));
	response.getDocument()->setHttpVersion("HTTP/1.1");
	response.getDocument()->setResponseCode("200");
	response.getDocument()->setDescribe("OK");
	response.getDocument()->setResource(G_RESOURCE);
	response.getDocument()->writeContentFile(url.c_str());
	this->doPostResponse(&response);
}

void HttpReceiver::getRequestUrl(sys::String& inString, std::string& outString)
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

void HttpReceiver::handGetMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams)
{
	int index = inString.findFirstOf('?');
	sys::String params = "";
	if (index == -1)
		return;

	index += 1;
	params = inString.subString(index, inString.getSize() - index);

	handPostMethodParams(params, outParams);
}

void HttpReceiver::handPostMethodParams(sys::String& inString, std::map<std::string, std::string>& outParams)
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
