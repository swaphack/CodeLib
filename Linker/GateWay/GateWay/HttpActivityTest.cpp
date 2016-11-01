#include "HttpActivityTest.h"

#define G_RESOURCE WebApplication::getInstance()->getResourceMgr()->getResource(ERT_LOCAL)

void HttpActivityTest::doGet(sys::HttpRequest* request)
{
	this->doHttpGet(request);
}

void HttpActivityTest::doHttpGet(sys::HttpRequest* request)
{

	std::string url;
	sys::String method = request->getDocument()->getMethod();
	sys::String params = request->getDocument()->getUrl();
	sys::String body = request->getDocument()->getBody();

	std::map<std::string, std::string> reqParams;

	// 获取请求的页面
	handUrlMethod(params, url);
	
	if (method.compare(HttpRequestConstant::HTTP_REQ_GET))
	{// get
		// 获取上传的参数
		handGetParamMethod(params, reqParams);
	}
	else if (method.compare(HttpRequestConstant::HTTP_REQ_POST))
	{// post

	}

	HttpResponse response;
	response.getDocument()->setHttpVersion("HTTP/1.1");
	response.getDocument()->setResponseCode("200");
	response.getDocument()->setDescribe("OK");
	response.getDocument()->setResource(G_RESOURCE);
	response.getDocument()->writeContentFile(url.c_str());
	this->doPost(&response);
}

void HttpActivityTest::doSocketGet(sys::HttpRequest* request)
{
	const char* data = request->getMessage();
	HttpResponse response;
	response.setMessage(data, strlen(data));
	this->doPost(&response);
}

void HttpActivityTest::handUrlMethod(sys::String& inString, std::string& outString)
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


void HttpActivityTest::handGetParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams)
{
	int index = inString.findFirstOf('?');
	sys::String params = "";
	if (index == -1)
		return;

	index += 1;
	params = inString.subString(index, inString.getSize() - index);

	std::vector<sys::String> vecParams;
	params.split('&', vecParams);

	std::vector<sys::String> kv;
	std::vector<sys::String>::iterator iter = vecParams.begin();
	while (iter != vecParams.end())
	{
		(*iter).split('=', kv);
		if (kv.size() == 2)
		{
			outParams[kv[0].getString()] = kv[1].getString();
		}
		iter++;
	}
}

void HttpActivityTest::handPostParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams)
{
	std::vector<sys::String> vecParams;
	inString.split('&', vecParams);

	std::vector<sys::String> kv;
	std::vector<sys::String>::iterator iter = vecParams.begin();
	while (iter != vecParams.end())
	{
		(*iter).split('=', kv);
		if (kv.size() == 2)
		{
			outParams[kv[0].getString()] = kv[1].getString();
		}
		iter++;
	}
}
