#include "HttpRequest.h"
#include "HttpConstant.h"
#include "Type/import.h"

using namespace sys;

HttpReqDocument::HttpReqDocument()
{

}

HttpReqDocument::~HttpReqDocument()
{

}

bool HttpReqDocument::parseRequest(const char* msg, int32_t size)
{
	if (msg == nullptr || size <= 0)
	{
		return false;
	}

	String line(msg, size);

	if (!(line.startWith(HttpRequestConstant::HTTP_REQ_GET)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_POST)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_HEAD)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_PUT)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_DELETE)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_TRACE)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_CONNECT)
		|| line.startWith(HttpRequestConstant::HTTP_REQ_OPTIONS)))
	{
		return false;
	}

	return parse(std::string(msg, size));
}

std::string HttpReqDocument::getMethod()
{
	return getStatus(0);
}

void HttpReqDocument::setMethod(const std::string& method)
{
	setStatus(0, method);
}

std::string HttpReqDocument::getUrl()
{
	return getStatus(1);
}

void HttpReqDocument::setUrl(const std::string& url)
{
	setStatus(1, url);
}

std::string HttpReqDocument::getHttpVersion()
{
	return getStatus(2);
}

void HttpReqDocument::setHttpVersion(const std::string& version)
{
	setStatus(2, version);
}