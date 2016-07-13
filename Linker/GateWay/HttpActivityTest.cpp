#include "HttpActivityTest.h"

void HttpActivityTest::doGet(HttpRequest* request)
{
	if (request->isHttpFormat())
	{
		this->doHttpGet(request);
	}
	else
	{
		this->doSocketGet(request);
	}
}

void HttpActivityTest::doHttpGet(HttpRequest* request)
{
	std::string url;
	sys::String method = request->getRequest(HttpRequest::HTTP_REQUEST_METHOD);
	sys::String params = request->getRequest(HttpRequest::HTTP_REQUEST_PARAM);
	sys::String body = request->getBody();

	std::map<std::string, std::string> reqParams;

	// 获取请求的页面
	handUrlMethod(params, url);
	// 获取上传的参数
	handParamMethod(params, reqParams);

	if (method.compare(HttpRequestConstant::HTTP_REQ_GET))
	{// get

	}
	else if (method.compare(HttpRequestConstant::HTTP_REQ_POST))
	{// post

	}

	HttpResponse response;
	response.writeFile(url.c_str());
	this->doPost(&response);
}

void HttpActivityTest::doSocketGet(HttpRequest* request)
{
	const char* data = request->getMessage();
	HttpResponse response;
	response.setHttpFormat(false);
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


void HttpActivityTest::handParamMethod(sys::String& inString, std::map<std::string, std::string>& outParams)
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
